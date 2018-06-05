#include "Database/lib/communitydata.h"

using namespace sql;

CommunityData* CommunityData::instance = NULL;

//return an instance of community data and assure that only one instance exists
CommunityData* CommunityData::getInstance(std::string user, std::string password, std::string host, std::string database) {
   if(instance == NULL) {
       instance = new CommunityData(user, password, host, database);
   }
   return instance;
}

bool CommunityData::connect(std::string user, std::string password, std::string host, std::string database) {
    driver = mysql::get_mysql_driver_instance();
    connection_properties["hostName"] = host;
    connection_properties["userName"] = user;
    connection_properties["password"] = password;
    connection_properties["schema"] = database;
    connection_properties["port"] = 3306;
    if((con = driver->connect(connection_properties)) == NULL) {
        return false;
    }
    else return true;
}
//Destructor
CommunityData::~CommunityData() {
    delete con;
}

//Constructor
CommunityData::CommunityData(std::string user, std::string password, std::string host, std::string database) {
    if(!connect(user, password, host, database)) {
        std::cout <<"Fehler bei der Verbindung!" << std::endl;
    }

    //nur einmal ausführen
    createRoomTable();
    createResidentTable();
    createCalendarTable();
    //createEventCommunityView();
    createCleaningTable();
    createTaskTable();
    createShoppinglistTable();
}

//Table for all Rooms
void CommunityData::createRoomTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS Rooms(Name VARCHAR(50) PRIMARY KEY, Type VARCHAR(20))");
    delete stmt;
}
//Table for all Residents
void CommunityData::createResidentTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS Residents(Firstname VARCHAR(50) PRIMARY KEY, Password INT)");
    delete stmt;
}
//Table for Calendar
void CommunityData::createCalendarTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS Calendar (Datetime DATETIME, Event VARCHAR(50), User VARCHAR(50))");
    delete stmt;
}

//create a View to get only community events
void CommunityData::createEventCommunityView() {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("CREATE OR REPLACE VIEW CommunityEvent AS SELECT * FROM Calendar WHERE Username = 'community'");
    stmt->execute();
    delete stmt;
}

//Table to store cleaning plan
void CommunityData::createCleaningTable(){
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS Cleaning (Task VARCHAR(50), Resident VARCHAR(50), Week DATE)");
}

//Table to store cleaning Tasks
void CommunityData::createTaskTable(){
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS Tasks (Name VARCHAR(50), Room VARCHAR(50), Frequency VARCHAR(50))");
    delete stmt;
}

//create Table for Shopping list
void CommunityData::createShoppinglistTable(){
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS ShoppingList (Item VARCHAR(50), Number INT)");
    delete stmt;
}

//insert a new resident identified by his name and his password
void CommunityData::addResident(Resident re) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Residents(Firstname, Password) VALUES(?, ?)");
    stmt->setString(1, re.getFirstname());
    stmt->setInt(2, re.getPassword());
    stmt->execute();
    delete stmt;
}

//add a new room identified by a room type and a name
void CommunityData::addRoom(Room ro) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Rooms(Name, Type) VALUES(?, ?)");
    stmt->setString(1, ro.getName());
    stmt->setString(2, ro.getArt());
    stmt->execute();
    delete stmt;
}
//add a new calendar event for a user
void CommunityData::addEvent(Event ev) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Calendar(Datetime, Event, User) VALUES(?, ?, ?)");
    stmt->setDateTime(1, ev.getDatetime());
    stmt->setString(2, ev.getDescription());
    stmt->setString(3, ev.getUser());
    stmt->execute();
    delete stmt;
}

//add a new cleaning task
void CommunityData::addTask(Task ta){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Tasks(Name, Room, Frequency) VALUES(?, ?)");
    stmt->setString(1, ta.getName());
    stmt->setString(2, ta.getRoom());
    stmt->setString(3, ta.getFrequency());
    stmt->execute();
    delete stmt;
}

void CommunityData::addToCleaningplan(std::string task, std::string resident, std::string week){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Cleaning(Task, Resident, Week) VALUES(?, ?, ?)");
    stmt->setString(1, task);
    stmt->setString(2, resident);
    stmt->setDateTime(3, week);
    stmt->execute();
    delete stmt;
}

//add Shoppinglist item
void CommunityData::addItem(std::string item, int number) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Shoppinglist(Item, Number) VALUES (?,?)");
    stmt->setString(1,item);
    stmt->setInt(2, number);
    stmt->execute();
    delete stmt;
}

//set a new password for a resident
void CommunityData::updatePassword(std::string username, int newPassword) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("UPDATE Residents SET Password = ? WHERE Firstname = ?");
    stmt->setInt(1, newPassword);
    stmt->setString(2, username);
    stmt->execute();
    delete stmt;
}

//change time or description of an event
void CommunityData::updateEvent(Event ev, std::string newtimedate, std::string newdescription) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("UPDATE Calendar SET Datetime = ? WHERE Datetime = ? AND EVENT = ? AND User = ? ");
    stmt->setDateTime(1, newtimedate);
    stmt->setDateTime(2, ev.getTime());
    stmt->setString(3, ev.getDescription());
    stmt->setString(4, ev.getUser());
    stmt->execute();
    stmt->close();

    stmt = con->prepareStatement("UPDATE Calendar SET Description = ? WHERE Datetime = ? AND EVENT = ? AND User = ? ");
    stmt->setString(1, newdescription);
    stmt->setDateTime(2, ev.getTime());
    stmt->setString(3, ev.getDescription());
    stmt->setString(4, ev.getUser());
    stmt->execute();
    delete stmt;

}

//delete a resident
void CommunityData::deleteResident(std::string name) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Residents WHERE Firstname = ?");
    stmt->setString(1, name);
    stmt->execute();
    deleteCalendar(name); //delete calendar of deleted resident
    //deleteResidentCleaningplan(name); //delete his cleaning tasks
    delete stmt;
}

//delete a room
void CommunityData::deleteRoom(std::string name) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Rooms WHERE Name = ?");
    stmt->setString(1, name);
    stmt->execute();
    deleteTaskByRoom(name); //delete tasks
    //deleteRoomCleaningplan(name); //and update cleaningplan


    delete stmt;
}

//delete a calendar event
void CommunityData::deleteEvent(Event ev) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Calendar WHERE Datetime = ? AND Event = ? AND User = ?");
    stmt->setDateTime(1,ev.getDatetime());
    stmt->setString(2, ev.getDescription());
    stmt->setString(3, ev.getUser());
    stmt->execute();
    delete stmt;
}

//delete a cleaning task from database
void CommunityData::deleteTaskByName(std::string taskname){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Tasks WHERE Name = ? ");
    stmt->setString(1, taskname);
    stmt->execute();
    //update cleaning plan

    delete stmt;
}

//delete all tasks of a room
void CommunityData::deleteTaskByRoom(std::string room){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Tasks WHERE Room = ?");
    stmt->setString(1, room);
    stmt->execute();
    //update cleaning plan
    //deleteTaskCleaningplan();

    delete stmt;
}

//delete the whole calendar of an user
void CommunityData::deleteCalendar(std::string user) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Calendar WHERE User = ?");
    stmt->setString(1, user);
    stmt->execute();
    delete stmt;
}

//update cleaningplan by task
void CommunityData::deleteTaskCleaningplan(std::string task){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Cleaning WHERE Task = ?");
    stmt->setString(1, task);
    stmt->execute();
    delete stmt;

}

//update cleaningplan by resident
void CommunityData::deleteResidentCleaningplan(std::string resident){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Cleaning WHERE Resident = ?");
    stmt->setString(1, resident);
    stmt->execute();
    delete stmt;
}

//update cleaningplan by room
/*void CommunityData::deleteRoomCleaningplan(std::string room){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Cleaning WHERE Room = ?");
    stmt->setString(1, room);
    stmt->execute();
    delete stmt;
}*/

//delete an item from shoppinglist
void CommunityData::deleteShoppinglistItem(std::string item) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Shoppinglist WHERE Item = ?");
    stmt->setString(1, item);
    stmt->execute();
    delete stmt;
}

//get all residents from database
std::vector<Resident> CommunityData::getAllResidents() {
    std::vector<Resident> list;
    PreparedStatement* stmt = con->prepareStatement("SELECT * FROM Residents");
    ResultSet *resultSet = NULL;
    resultSet = stmt->executeQuery();

    while(resultSet->next()) {
        Resident res;
        SQLString psw = "Password";
        res.setFirstname(resultSet->getString("Firstname"));
        res.setPassword(resultSet->getInt(psw));
        list.push_back(res);
    }
    delete stmt;
    delete resultSet;
    return list;
}

//get all rooms from database
std::vector<Room> CommunityData::getAllRooms() {
    std::vector<Room> list;
    PreparedStatement* stmt = con->prepareStatement("SELECT * FROM Rooms");
    ResultSet* resultSet = NULL;
    resultSet = stmt->executeQuery();
    while(resultSet->next()) {
      Room ro;
      ro.setName(resultSet->getString("Name"));
      ro.setArt(resultSet->getString("Type"));
      list.push_back(ro);
    }
    delete stmt;
    delete resultSet;
    return list;
}

//get all events from calendar of a user
std::vector<Event> CommunityData::getAllEventsOfUser(std::string user) {
    std::vector<Event> list;
    PreparedStatement* stmt;
    ResultSet* resultSet = NULL;
    stmt = con->prepareStatement("SELECT * FROM Calendar WHERE Username = ?");
    stmt->setString(1, user);
    resultSet = stmt->executeQuery();
    while(resultSet->next()) {
        Event ev;
        ev.setDescription(resultSet->getString("Event"));
        ev.setUser(user);
        ev.setDatetime(resultSet->getString("Datetime"));
        list.push_back(ev);
    }
    delete stmt;
    delete resultSet;
    return list;
}
//get all Community Events
std::vector<Event> CommunityData::getAllCommunityEvents() {
    std::vector<Event> list;
    ResultSet* resultSet = NULL;
    PreparedStatement* stmt;
    stmt = con->prepareStatement("SELECT * FROM CommunityEvent");
    resultSet = stmt->executeQuery();
    while(resultSet->next()) {
        Event ev;
        ev.setDescription(resultSet->getString("Event"));
        ev.setUser("community");
        ev.setDatetime(resultSet->getString("Datetime"));
        list.push_back(ev);
    }
    delete stmt;
    delete resultSet;
    return list;
}

//verifying the log in data by username and password
 bool CommunityData::verifyLogInData(std::string username, int password) {
     PreparedStatement* stmt = con->prepareStatement("SELECT * FROM Residents WHERE Firstname = ? AND Password = ?");
     ResultSet* resultSet = NULL;
     stmt->setString(1, username);
     stmt->setInt(2, password);
     resultSet = stmt->executeQuery();
     if(resultSet->next()){
         delete stmt;
         delete resultSet;
         return true;

     }
     else {
         delete stmt;
         delete resultSet;
         return false;
     }
 }

 //verify if resident with this name exists
 bool CommunityData::verifyName(std::string username) {
     PreparedStatement* stmt = con->prepareStatement("SELECT * FROM Residents WHERE Firstname = ?");
     ResultSet* resultSet = NULL;
     stmt->setString(1, username);
     resultSet = stmt->executeQuery();
     if(resultSet->next() ){
         delete stmt;
         delete resultSet;
         return true;
     }
     else {
         delete stmt;
         delete resultSet;
         return false;
     }
 }
