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
//Konstruktor und Destruktor!
CommunityData::~CommunityData() {
    delete con;
}

CommunityData::CommunityData() {
    if(!connect())
        cout <<"Fehler bei der Verbindung!" << endl;

    //nur einmal ausführen

    //Statement* stmt;
    //stmt = con->createStatement();
    //stmt->execute("CREATE SCHEMA MyCommunity");
    //createRoomTable();
    //createResidentTable();
    //createCalendarTable();
}

//Table for all Rooms
void CommunityData::createRoomTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE Rooms(Name VARCHAR(50) PRIMARY KEY, Type VARCHAR(20))");
    delete stmt;
}
//Table for all Residents
void CommunityData::createResidentTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE Residents(Firstname VARCHAR(50) PRIMARY KEY, Password INT)");
    delete stmt;
}
//Table for Calendar
void CommunityData::createCalendarTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE Calendar (Date DATE, Time TIME, Event VARCHAR(50), Resident VARCHAR(50))");
    delete stmt;
}
//get all events from calendar of a user-> use views
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



//use D.R.Y?
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

//get all events from calendar of a user-> use views



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
