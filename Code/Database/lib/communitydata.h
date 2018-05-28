/*#ifndef COMMUNITYDATA_H
#define COMMUNITYDATA_H

//  sudo apt-get install  libmysqlcppconn-dev

#include <vector>
#include <string>

#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>

#include "lib/resident.h"
#include "lib/room.h"

class CommunityData {
private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection* con;
    sql::ConnectOptionsMap connection_properties;
    static CommunityData* instance;

protected:
    CommunityData();

public:
    bool connect();
    void createRoomTable();
    void createResidentTable();
    void addResident(std::string, int);
    void addRoom(std::string, std::string);
    void updatePassword(std::string, int);
    void deleteResident(std::string);
    void deleteRoom(std::string);
    vector<Resident> getAllResidents();
    vector<Room> getAllRooms();
    bool verifyLogInData(std::string, int);
    bool verifyName(std::string);
    ~CommunityData();

    static CommunityData* getInstance();

};

#endif // COMMUNITYDATA_H*/
