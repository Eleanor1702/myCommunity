#ifndef TESTDATABASEDELETER_H
#define TESTDATABASEDELETER_H

#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>

class TestDatabaseDeleter {

private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection* con;
    sql::ConnectOptionsMap connection_properties;

public:
    TestDatabaseDeleter(std::string user, std::string password, std::string host, std::string database);

    void cleanRooms();
    void cleanResidents();
};

#endif // TESTDATABASEDELETER_H
