#include "lib/wg.h"
#include <iostream>

using namespace std;

WG::WG() {}

void WG::bewohnerErstellen(){
    Bewohner* b1 = new Bewohner();
    string name;
    int pass;

    cout << "Bitte Namen eingeben" << endl;
    cin >> name;
    b1->setVorname(name);

    cout << "Bitte pass eingeben" << endl;
    cin >> pass;
    b1->setPasswort(pass);
    bewohnerListe.push_back(b1);
}

void WG::raumErstellen(string art, string name) {

    Raum* r1 = new Raum();

    r1->setArt(art);
    r1->setName(name);
    raumListe.push_back(r1);
}

void WG::bewohnerLoeschen(Bewohner* bew) {
    for(vector<Bewohner*>::iterator it = bewohnerListe.begin(); it != bewohnerListe.end(); ++it) {
        if(bew == *it) {
            bewohnerListe.erase(it);
            cout << "Löschen erfolgreich!" << endl;
        }
    }
}

void WG::raumLoeschen(Raum* raum) {
    for(vector<Raum*>::iterator it = raumListe.begin(); it != raumListe.end(); ++it) {
        if(raum == *it) {
            raumListe.erase(it);
            cout << "Löschen erfolgreich!" << endl;
        }
    }
}
