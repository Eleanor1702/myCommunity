#ifndef WG_H
#define WG_H

#include <string>
#include <vector>
#include "bewohner.h"
#include "raum.h"
#include "userInterface/lib/guicontroller.h"

class WG {
private:
    vector<Raum*> raumListe;
    vector<Bewohner*> bewohnerListe;
    GUIController guic;

public:
    WG();
    void raumErstellen(string art, string name);
    void bewohnerErstellen(string name, int password);
    void bewohnerLoeschen(Bewohner* b);
    void raumLoeschen(Raum* r);
    //Bearbeitenfunktion, die passwort und name ändern beinhaltet?
};

#endif // WG_H

