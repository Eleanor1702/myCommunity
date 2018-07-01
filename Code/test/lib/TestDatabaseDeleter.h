#ifndef TESTDATABASEDELETER_H
#define TESTDATABASEDELETER_H

#include <iostream>
#include <cstring>
#include <mysql.h>

class TestDatabaseDeleter {

private:
    MYSQL* mysql;

public:
    TestDatabaseDeleter(std::string user, std::string password, std::string host, std::string database);

    void cleanRooms();
    void cleanResidents();
};

#endif // TESTDATABASEDELETER_H
