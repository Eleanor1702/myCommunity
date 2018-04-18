#ifndef BEWOHNER
#define BEWOHNER

#include <string>

using namespace std;

class Bewohner {
private:
    int passwort;
    string vorname;

public:
    Bewohner();
    void setPasswort(int eingabe);
    void setVorname(string eingabe);
    int getPasswort();
    string getVorname();
    void passwortAendern();
    void nameAendern();
    friend class WG;
};

#endif // BEWOHNER

