#ifndef WG
#define WG

#include <string>

using namespace std;

class WG {
private:
    vector<Raum> raumListe;
    vector<Bewohner> bewohnerListe;

public:
    void raumErstellen(string art, int anzahl);
    void bewohnerErstellen(string name, int passwort);
};

#endif // WG

