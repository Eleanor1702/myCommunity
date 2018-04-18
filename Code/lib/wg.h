#ifndef WG_H
#define WG_H

#include <string>
#include <vector>
#include "bewohner.h"
#include "raum.h"

class WG {
private:
    vector<Raum*> raumListe;
    vector<Bewohner*> bewohnerListe;

public:
    WG();
    void raumErstellen(string art, string name);
    void bewohnerErstellen();
};

#endif // WG_H

