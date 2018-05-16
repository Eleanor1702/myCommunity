#ifndef COMMUNITYDATA_H
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

public:
    bool connect();
    void createRoomTable();
    void createResidentTable();
    void addResident(string, int);
    void addRoom(string, string);
    void updatePassword(string, int);
    void deleteResident(string);
    void deleteRoom(string);
    vector<Resident> getAllResidents();
    vector<Room> getAllRooms();
    CommunityData();
    ~CommunityData();
};

#endif // COMMUNITYDATA_H

