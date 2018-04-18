#ifndef BEWOHNER
#define BEWOHNER

#include <string>

using namespace std;

class Bewohner {
private:
    int passwort;
    string vorname;
    int num = 999;

public:
    void setPasswort(int eingabe);
    void setVorname(string eingabe);
    int getPasswort();
    string getVorname();
};

#endif // BEWOHNER

