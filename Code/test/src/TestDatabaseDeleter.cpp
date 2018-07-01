#include "../lib/TestDatabaseDeleter.h"

TestDatabaseDeleter::TestDatabaseDeleter(std::string user, std::string password, std::string host, std::string database) {
    mysql = mysql_init(NULL);

    if(mysql_errno(mysql) != 0){
        return;
    }

    //Encoding from Mac to unix and windows
    mysql_options(mysql, MYSQL_SET_CHARSET_NAME, "utf8");

    mysql_real_connect(mysql, host.c_str(), user.c_str(), password.c_str(), database.c_str(), 3306, NULL, 0);
}

void TestDatabaseDeleter::cleanRooms() {
    std::string stmt = "DELETE FROM Rooms";

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

void TestDatabaseDeleter::cleanResidents() {
    std::string stmt = "DELETE FROM Residents";

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}
