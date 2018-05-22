#ifndef RESIDENT_H
#define RESIDENT_H

#include <string>

using namespace std;

class Resident {

private:
    int password;
    string firstname;

public:
    friend class WG;

    Resident();

    void setPassword(int eingabe);
    void setFirstname(string eingabe);

    int getPassword();
    string getFirstname();

    void changePassword();  //not tested (should be changed)
    void changeName();    //not tested (should be changed)
};

#endif // resident
