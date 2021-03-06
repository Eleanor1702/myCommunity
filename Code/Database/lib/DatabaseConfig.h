#ifndef DATABASECONFIG_H
#define DATABASECONFIG_H

#include <string>
#include <fstream>

class DatabaseConfig {
private:
    std::string user;
    std::string host;
    std::string password;
    std::string database;
    std::string path;

public:
    DatabaseConfig();
    bool exist();

    void write(std::string user, std::string host, std::string password,
               std::string database);
    void read();

    std::string getUser();
    std::string getHost();
    std::string getPassword();
    std::string getDatabase();
};

#endif // DATABASECONFIG_H
