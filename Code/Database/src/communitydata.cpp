#include "Database/lib/communitydata.h"

using namespace std;
using namespace sql;

CommunityData* CommunityData::instance = NULL;

bool CommunityData::connect() {
    driver = mysql::get_mysql_driver_instance();
    SQLString userName = "user";
    SQLString hostName = "localhost";
    SQLString password = "mycommunity";
    SQLString schema = "MyCommunity";
    connection_properties["hostName"] = hostName;
    connection_properties["userName"] = userName;
    connection_properties["password"] = password;
    connection_properties["schema"] = schema;
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
CommunityData::CommunityData() {
    if(!connect())
        cout <<"Fehler bei der Verbindung!" << endl;

    //nur einmal ausführen

    //Statement* stmt;
    //stmt = con->createStatement();
    //stmt->execute("CREATE DATABASE IF NOT EXISTS MyCommunity");
    //createRoomTable();
    //createResidentTable();
    //createCalendarTable();
    //createEventCommunityView();
    //createCleaningTable();
    //createTaskTable();
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
    stmt->execute("CREATE TABLE IF NOT EXISTS Tasks (Name VARCHAR(50) PRIMARY KEY, Room(50), FREQUENCY VARCHAR(50))");
    delete stmt;
}

//insert a new resident identified by his name and his password
void CommunityData::addResident(string name, int password) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Residents(Firstname, Password) VALUES(?, ?)");
    stmt->setString(1, name);
    stmt->setInt(2, password);
    stmt->execute();
    delete stmt;
}

//add a new room identifies by a room type and a name
void CommunityData::addRoom(string name, string type) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Rooms(Name, Type) VALUES(?, ?)");
    stmt->setString(1, name);
    stmt->setString(2, type);
    stmt->execute();
    delete stmt;
}

//add a new calendar event for a user
void CommunityData::addEvent(string timedate, string description, string user) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Calendar(Datetime, Event, User) VALUES(?, ?, ?)");
    stmt->setDateTime(1, timedate);
    stmt->setString(2, description);
    stmt->setString(3, user);
    stmt->execute();
    delete stmt;
}

//add a new cleaning task
void CommunityData::addTask(string taskname, string room,string frequency){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Tasks(Name, Room, Frequency) VALUES(?, ?)");
    stmt->setString(1, taskname);
    stmt->setString(2, room);
    stmt->setString(3, frequency);
    stmt->execute();
    delete stmt;
}

void CommunityData::addToCleaningplan(string task, string resident, string week){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Cleaning(Task, Resident, Week) VALUES(?, ?, ?)");
    stmt->setString(1, task);
    stmt->setString(2, resident);
    stmt->setDateTime(3, week);
    stmt->execute();
    delete stmt;
}

//set a new password for a resident
void CommunityData::updatePassword(string username, int newPassword) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("UPDATE Residents SET Password = ? WHERE Firstname = ?");
    stmt->setInt(1, newPassword);
    stmt->setString(2, username);
    stmt->execute();
    delete stmt;
}

//change time or description of an event
void CommunityData::updateEvent(Event ev, string newtimedate, string newdescription) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("UPDATE Calendar SET Datetime = ? WHERE Datetime = ? AND EVENT = ? AND User = ? ");
    //stmt->setDateTime(1, newtimedate);
    //stmt->setDateTime(2, ev.getTime());
    stmt->setString(3, ev.getDescription());
    stmt->setString(4, ev.getUser());
    stmt->execute();
    stmt->close();

    stmt = con->prepareStatement("UPDATE Calendar SET Description = ? WHERE Datetime = ? AND EVENT = ? AND User = ? ");
    stmt->setString(1, newdescription);
    //stmt->setDateTime(2, ev.getTime());
    stmt->setString(3, ev.getDescription());
    stmt->setString(4, ev.getUser());
    stmt->execute();
    delete stmt;

}


//delete a resident
void CommunityData::deleteResident(string name) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Residents WHERE Firstname = ?");
    stmt->setString(1, name);
    stmt->execute();
    delete stmt;
}

//delete a room
void CommunityData::deleteRoom(string name) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Rooms WHERE Name = ?");
    stmt->setString(1, name);
    stmt->execute();
    delete stmt;
}

//delete a calendar event
void CommunityData::deleteEvent(tm timedate, string description, string user) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Calendar WHERE Datetime = ? AND Event = ? AND User = ?");
    //Convert timedate to SQLString or DATETIME type



    //stmt->setDateTime(1,timedate);
    stmt->setString(2, description);
    stmt->setString(3, user);
    stmt->execute();
    delete stmt;
};

//delete a cleaning task from database
void CommunityData::deleteTask(string taskname){
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Tasks WHERE Name = ? ");
    stmt->setString(1, taskname);
    stmt->execute();
    delete stmt;
}

//get all residents from database
vector<Resident> CommunityData::getAllResidents() {
    vector<Resident> list;
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
vector<Room> CommunityData::getAllRooms() {
    vector<Room> list;
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
vector<Event> CommunityData::getAllEventsOfUser(string user) {
    vector<Event> list;
    PreparedStatement* stmt;
    ResultSet* resultSet = NULL;
    stmt = con->prepareStatement("SELECT * FROM Calendar WHERE Username = ?");
    stmt->setString(1, user);
    resultSet = stmt->executeQuery();
    while(resultSet->next()) {
        Event ev;
        ev.setDescription(resultSet->getString("Event"));
        ev.setUser(user);
        //ev.setDatetime(resultSet->getString("Datetime"));

        //ev.setTime(timedate);
        list.push_back(ev);
    }
    delete stmt;
    delete resultSet;
    return list;
}
//get all Community Events
vector<Event> CommunityData::getAllCommunityEvents() {
    vector<Event> list;
    ResultSet* resultSet = NULL;
    PreparedStatement* stmt;
    stmt = con->prepareStatement("SELECT * FROM CommunityEvent");
    resultSet = stmt->executeQuery();
    while(resultSet->next()) {
        Event ev;
        ev.setDescription(resultSet->getString("Event"));
        ev.setUser("community");
        //Convert datetime / SQLString to tm type


        //ev.setTime(timedate);
        list.push_back(ev);
    }
    delete stmt;
    delete resultSet;
    return list;
}

//verifying the log in data by username and password
 bool CommunityData::verifyLogInData(string username, int password) {
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
 bool CommunityData::verifyName(string username) {
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

 //return an instance of community data and assure that only one instance exists
CommunityData* CommunityData::getInstance() {
    if(instance == NULL) {
        instance = new CommunityData();
    }
    return instance;
}
