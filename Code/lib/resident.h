#ifndef RESIDENT_H
#define RESIDENT_H

#include <string>

using namespace std;

class Resident {
private:
    int password;
    string firstname;

public:
    Resident();
    void setPassword(int eingabe);
    void setFirstname(string eingabe);
    int getPassword();
    string getFirstname();
    void changePassword();
    void changeName();
    friend class WG;
};

#endif // resident
