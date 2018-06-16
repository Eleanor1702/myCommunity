#ifndef RESIDENT_H
#define RESIDENT_H

#include <string>

class Resident {

private:
    int password;
    std::string firstname;

public:
    Resident();
    ~Resident();

    void setPassword(int eingabe);
    void setFirstname(std::string eingabe);

    int getPassword();
    std::string getFirstname();
};

#endif // resident
