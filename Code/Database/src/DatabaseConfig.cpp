#include "../lib/DatabaseConfig.h"
#include <QDebug>

DatabaseConfig::DatabaseConfig() {
    //create config File path
    const char* home = std::getenv("HOME");
    this->path = (std::string(home) + "/.myCommunity");
}

bool DatabaseConfig::exist() {
    std::ifstream f(path.c_str());
    return f.good();
}

void DatabaseConfig::write(std::string user, std::string host, std::string password,
                           std::string database){
    std::ofstream file(path);
    file << user <<"\n";
    file << host <<"\n";
    file << password <<"\n";
    file << database;

    file.close();
}

void DatabaseConfig::read() {
    std::ifstream file(path);

    std::getline(file, user);
    std::getline(file, host);
    std::getline(file, password);
    std::getline(file, database);

    file.close();
}

std::string DatabaseConfig::getUser() {
    return user;
}

std::string DatabaseConfig::getHost() {
    return host;
}

std::string DatabaseConfig::getPassword() {
    return password;
}

std::string DatabaseConfig::getDatabase() {
    return database;
}
