#include "lib/bewohner.h"
#include <iostream>

using namespace std;

Bewohner::Bewohner() {}

void Bewohner::setVorname(string eingabe) {
    vorname = eingabe;
}

void Bewohner::setPasswort(int eingabe) {
    passwort = eingabe;
}

string Bewohner::getVorname() {
    return vorname;
}

int Bewohner::getPasswort() {
    return passwort;
}

void Bewohner::passwortAendern() {
    int alt;
    cout << "Bitte altes Passwort eingeben: " << endl;
    cin >> alt;
    if(alt == passwort) {
        int neu;
        cout << "Bitte neues Passwort eingeben:" << endl;
        cin >> neu;
        setPasswort(neu);
    }
    else
        cout << "Falsches Passwort!" << endl;
}

void Bewohner::nameAendern() {
    int pass;
    cout << "Bitte Passwort eingeben: " << endl;
    cin >> pass;
    if(pass == passwort) {
        string neu;
        cout << "Bitte neuen Namen eingeben:" << endl;
        cin >> neu;
        setVorname(neu);
    }
    else
        cout << "Falsches Passwort!" << endl;
}
