#ifndef RESIDENT_H
#define RESIDENT_H

#include <string>

using namespace std;

class resident {
private:
    int password;
    string firstname;

public:
    resident();
    void setpassword(int eingabe);
    void setfirstname(string eingabe);
    int getpassword();
    string getfirstname();
    void passwordAendern();
    void nameAendern();
    friend class WG;
};

#endif // resident

