#include "Database/lib/communitydata.h"
#include <QDebug>

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
    createRoomTable();
    createResidentTable();
    createCalendarTable();
    //createEventCommunityView();
    createCleaningTable();
    createTaskTable();
    createShoppinglistTable();
}


//****Rooms****

//Table for all Rooms
void CommunityData::createRoomTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS Rooms(Name VARCHAR(50) PRIMARY KEY, Type VARCHAR(20))");
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

//delete a room
void CommunityData::deleteRoom(std::string name) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Rooms WHERE Name = ?");
    stmt->setString(1, name);
    stmt->execute();
    deleteAllTaskOfRoom(name); //delete tasks
    //deleteRoomCleaningplan(name); //and update cleaningplan


    delete stmt;
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


//****Residents****

//Table for all Residents
void CommunityData::createResidentTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS Residents(Firstname VARCHAR(50) PRIMARY KEY, Password INT)");
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
//set a new password for a resident
void CommunityData::updatePassword(std::string username, int newPassword) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("UPDATE Residents SET Password = ? WHERE Firstname = ?");
    stmt->setInt(1, newPassword);
    stmt->setString(2, username);
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
    deleteResidentCleaningplan(name); //delete his cleaning tasks
    delete stmt;
}
//get all residents from database
std::vector<std::string> CommunityData::getAllResidents() {
    std::vector<std::string> list;
    PreparedStatement* stmt = con->prepareStatement("SELECT * FROM Residents");
    ResultSet *resultSet = NULL;
    resultSet = stmt->executeQuery();

    while(resultSet->next()) {
        std::string res;
        res = resultSet->getString("Firstname");
        list.push_back(res);
    }
    delete stmt;
    delete resultSet;
    return list;
}
//verifying the log in data by username and password
 bool CommunityData::verifyLogInData(std::string username, int password) {
     PreparedStatement* stmt = con->prepareStatement("SELECT * FROM Residents WHERE Firstname = ? "
                                                     "AND Password = ?");
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
//Get Username from database (username is not case sensitive)
 std::string CommunityData::getDbUser(std::string user){
     PreparedStatement* stmt = con->prepareStatement("SELECT * FROM Residents WHERE Firstname = ?");
     ResultSet* resultSet = NULL;
     std::string res;
     stmt->setString(1, user);
     resultSet = stmt->executeQuery();
     if(resultSet->next()){
         res = resultSet->getString("Firstname");
         return res;
     }
     else{
     return "Fehler";
        }
  }





//****Calendar****

//Table for Calendar
void CommunityData::createCalendarTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS Calendar (Datetime DATETIME, Event VARCHAR(50), User VARCHAR(50))");
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
//delete the whole calendar of an user
void CommunityData::deleteCalendar(std::string user) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Calendar WHERE User = ?");
    stmt->setString(1, user);
    stmt->execute();
    delete stmt;
}
//get all events from calendar of a user
std::vector<Event> CommunityData::getAllEventsOfUser(std::string user, std::string datetime) {
    std::vector<Event> list;
    PreparedStatement* stmt;
    ResultSet* resultSet = NULL;
    stmt = con->prepareStatement("SELECT * FROM Calendar WHERE Username = ? AND WHERE DATE(Datetime) = ?");
    stmt->setString(1, user);
    stmt->setString(2, datetime);
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

//get all Events
std::vector<Event> CommunityData::getAllEvents(std::string user, std::string date){
    std::vector<Event> list;
    ResultSet* resultSet = NULL;
    PreparedStatement* stmt;
    stmt = con->prepareStatement("SELECT * FROM Calendar WHERE User = ? AND DATE(Datetime) = ? ORDER BY Datetime");
    stmt->setString(1, user);
    stmt->setString(2, date);
    resultSet = stmt->executeQuery();
    while(resultSet->next()) {
        Event ev;
        ev.setDescription(resultSet->getString("Event"));
        ev.setUser(resultSet->getString("User"));
        ev.setDatetime(resultSet->getString("Datetime"));
        list.push_back(ev);
    }
    delete stmt;
    delete resultSet;
    return list;
}

std::vector<std::string> CommunityData::getAllEventsString(std::string cuser, std::string datetime){
    std::vector<std::string> stringlist;
    std::string name;
    std::string user;
    std::string date;
    std::string time;
    std::string info; //name,user,datetime

    std::vector<Event> list = this->getAllEvents(cuser, datetime);

    for(std::vector<Event>::iterator it = list.begin(); it != list.end(); it++)    {
                  name = it->getDescription();
                  user = it->getUser();
                  date = it->getDate();
                  time = it->getTime();
                  info = name + "," + user + "," + date + "," + time + "\n";
                  stringlist.push_back(info);
     }
    return stringlist;
}



//*****Cleaningplan*****

//Table to store cleaning plan
void CommunityData::createCleaningTable(){
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS Cleaning (Task VARCHAR(50), CRoom VARCHAR(50), Resident VARCHAR(50), Week INT)");
}
void CommunityData::addToCleaningplan(ConcreteTask ctask){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Cleaning(Task, CRoom, Resident, Week) VALUES(?, ?, ?, ?)");
    stmt->setString(1, ctask.getTask().getName());
    stmt->setString(2, ctask.getTask().getRoom());
    stmt->setString(3, ctask.getResident());
    stmt->setInt(4, ctask.getCalendarweek());
    stmt->execute();
    delete stmt;
}
//delete a concrete task
void CommunityData::deleteConcreteTask(std::string task, std::string resident, int week, std::string room){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Cleaning WHERE Task = ? AND Resident = ? AND Week = ? AND CRoom = ?");
    stmt->setString(1, task);
    stmt->setString(2, resident);
    stmt->setInt(3,week);
    stmt->setString(4, room);
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

//update cleaningplan by task
void CommunityData::deleteTaskCleaningplan(std::string name, std::string room) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Cleaning WHERE Task = ? AND CRoom = ?");
    stmt->setString(1, name);
    stmt->setString(2, room);
    stmt->execute();
    delete stmt;
}

std::vector<ConcreteTask> CommunityData::getAllConcreteTasks(int week) {
    std::vector<ConcreteTask> list;
    ResultSet* resultSet = NULL;
    PreparedStatement* stmt;
    stmt = con->prepareStatement("SELECT * FROM Cleaning JOIN Tasks ON Week >= ? AND Tasks.Name = Cleaning.Task AND Tasks.Room = Cleaning.CRoom ORDER BY Resident");
    stmt->setInt(1, week);
    resultSet = stmt->executeQuery();
    while(resultSet->next()) {
        ConcreteTask ctask;
        Task ta;
        ta.setName(resultSet->getString("Task"));
        ta.setRoom(resultSet->getString("CRoom"));
        ta.setFrequency(resultSet->getString("Frequency"));
        ctask.setResident(resultSet->getString("Resident"));
        ctask.setCalendarweek(resultSet->getInt("Week"));
        ctask.setTask(ta);
        list.push_back(ctask);
    }
    delete stmt;
    delete resultSet;
    return list;
}


std::vector<std::string> CommunityData::getAllConcreteTasksString(int week){
    std::vector<std::string> stringlist;
    std::string taskname;
    std::string resident;
    std::string cw;   //calendarweek
    std::string info; //taskname,resident,cw

    std::vector<ConcreteTask> list = this->getAllConcreteTasks(week);

    for(std::vector<ConcreteTask>::iterator it = list.begin(); it != list.end(); it++)    {
                  taskname = it->getTask().getName();
                  resident = it->getResident();
                  cw = it->getCalendarweek();
                  info = taskname + "," + resident + "," + cw + "\n";
                  stringlist.push_back(info);
     }
    return stringlist;
}

//****Tasks*****

//Table to store cleaning Tasks
void CommunityData::createTaskTable(){
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS Tasks (Name VARCHAR(50), Room VARCHAR(50), Frequency VARCHAR(50))");
    delete stmt;
}
//add a new cleaning task
void CommunityData::addTask(Task ta){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Tasks(Name, Room, Frequency) VALUES(?, ?, ?)");
    stmt->setString(1, ta.getName());
    stmt->setString(2, ta.getRoom());
    stmt->setString(3, ta.getFrequency());
    stmt->execute();
    delete stmt;
}
//delete a cleaning task from database
void CommunityData::deleteTaskByName(std::string taskname, std::string room){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Tasks WHERE Name = ? AND Room = ? ");
    stmt->setString(1, taskname);
    stmt->setString(2, room);
    stmt->execute();
    //update cleaning plan
    deleteTaskCleaningplan(taskname, room);
    delete stmt;
}
//delete all tasks of a room
void CommunityData::deleteAllTaskOfRoom(std::string room){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Tasks WHERE Room = ?");
    stmt->setString(1, room);
    stmt->execute();
    //update cleaning plan
    //deleteTaskCleaningplan();

    delete stmt;
}
//get all tasks
std::vector<Task> CommunityData::getAllTasks(){
    std::vector<Task> list;
    ResultSet* resultSet = NULL;
    PreparedStatement* stmt;
    stmt = con->prepareStatement("SELECT * FROM Tasks");
    resultSet = stmt->executeQuery();
    while(resultSet->next()) {
        Task ta;
        ta.setName(resultSet->getString("Name"));
        ta.setRoom(resultSet->getString("Room"));
        ta.setFrequency(resultSet->getString("Frequency"));
        list.push_back(ta);
    }
    delete stmt;
    delete resultSet;
    return list;
}


//*****Shoppinglist****

//create Table for Shopping list
void CommunityData::createShoppinglistTable(){
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE IF NOT EXISTS ShoppingList (Item VARCHAR(50), Number VARCHAR(20))");
    delete stmt;
}
//add Shoppinglist item
void CommunityData::addItem(Shoppingitem si) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO ShoppingList(Item, Number) VALUES (?,?)");
    stmt->setString(1,si.getItemName());
    stmt->setString(2, si.getNumber());
    stmt->execute();
    delete stmt;
}

//delete an item from shoppinglist
void CommunityData::deleteShoppinglistItem(std::string item) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM ShoppingList WHERE Item = ?");
    stmt->setString(1, item);
    stmt->execute();
    delete stmt;
}
//get all shoppinglist items
std::vector<Shoppingitem> CommunityData::getAllItems() {
    std::vector<Shoppingitem> list;
    ResultSet* resultSet = NULL;
    PreparedStatement* stmt;
    stmt = con->prepareStatement("SELECT * FROM ShoppingList");
    resultSet = stmt->executeQuery();
    while(resultSet->next()) {
        Shoppingitem si;
        si.setItemName(resultSet->getString("Item"));
        si.setNumber(resultSet->getString("Number"));
        list.push_back(si);
    }
    delete stmt;
    delete resultSet;
    return list;
}
//get ShopingList as String
std::vector<std::string> CommunityData::getAllItemsString(){
    std::vector<std::string> stringlist;
    std::string amount;
    std::string name;
    std::string info;   //"amaount,name"

    std::vector<Shoppingitem> list = this->getAllItems();

    for(std::vector<Shoppingitem>::iterator it = list.begin(); it != list.end(); it++)    {
                  amount = it->getNumber();
                  name = it->getItemName();
                  info = amount + "," + name + "\n";
                  stringlist.push_back(info);
     }
    return stringlist;
}





