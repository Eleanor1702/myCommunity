#include "../lib/TestDatabaseDeleter.h"

TestDatabaseDeleter::TestDatabaseDeleter(std::string user, std::string password, std::string host, std::string database) {
    driver = sql::mysql::get_mysql_driver_instance();
    connection_properties["hostName"] = host;
    connection_properties["userName"] = user;
    connection_properties["password"] = password;
    connection_properties["schema"] = database;
    connection_properties["port"] = 3306;

    con = driver->connect(connection_properties);
}

void TestDatabaseDeleter::cleanRooms() {
    sql::Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("DELETE FROM Rooms");
    delete stmt;
}

void TestDatabaseDeleter::cleanResidents() {
    sql::Statement* stmt;
    stmt = con->createStatement();
    stmt->execute("DELETE FROM Residents");
    delete stmt;
}
