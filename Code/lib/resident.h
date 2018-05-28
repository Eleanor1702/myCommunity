#ifndef RESIDENT_H
#define RESIDENT_H

#include <string>

class Resident {

private:
    int password;
    std::string firstname;

public:
    friend class WG;

    Resident();

    void setPassword(int eingabe);
    void setFirstname(std::string eingabe);

    int getPassword();
    std::string getFirstname();

    void changePassword();  //not tested (should be changed)
    void changeName();    //not tested (should be changed)
};

#endif // resident
