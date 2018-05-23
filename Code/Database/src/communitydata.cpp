#include "Database/lib/communitydata.h"

using namespace std;
using namespace sql;

CommunityData* CommunityData::instance = NULL;

bool CommunityData::connect() {
    driver = mysql::get_mysql_driver_instance();
    SQLString userName = "root";
    SQLString hostName = "localhost";
    SQLString password = "mysql";
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
   // createRoomTable();
   // createResidentTable();

}

void CommunityData::createRoomTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE Rooms(Name VARCHAR(50) PRIMARY KEY, Type VARCHAR(20))");
    delete stmt;
}
void CommunityData::createResidentTable() {
    Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("CREATE TABLE Residents(Firstname VARCHAR(50) PRIMARY KEY, Password INT)");
    delete stmt;
}

void CommunityData::addResident(string name, int password) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Residents(Firstname, Password) VALUES(?, ?)");
    stmt->setString(1, name);
    stmt->setInt(2, password);
    stmt->execute();
    delete stmt;
}

void CommunityData::addRoom(string name, string type) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("INSERT INTO Rooms(Name, Type) VALUES(?, ?)");
    stmt->setString(1, name);
    stmt->setString(2, type);
    stmt->execute();
    delete stmt;
}

void CommunityData::updatePassword(string username, int newPassword) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("UPDATE Residents SET Password = ? WHERE Firstname = ?");
    stmt->setInt(1, newPassword);
    stmt->setString(2, username);
    stmt->execute();
    delete stmt;
}
//D.R.Y anwenden?
void CommunityData::deleteResident(string name) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Residents WHERE Firstname = ?");
    stmt->setString(1, name);
    stmt->execute();
    delete stmt;
}


void CommunityData::deleteRoom(string name) {
    PreparedStatement* stmt;
    stmt = con->prepareStatement("DELETE FROM Rooms WHERE Name = ?");
    stmt->setString(1, name);
    stmt->execute();
    delete stmt;
}

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
    resultSet->close();
    stmt->close();
    delete stmt;
    delete resultSet;
    return list;
}
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
    resultSet->close();
    stmt->close();
    delete stmt;
    delete resultSet;
    return list;
}

CommunityData* CommunityData::getInstance() {
    if(instance == NULL) {
        instance = new CommunityData();
    }
    return instance;
}
