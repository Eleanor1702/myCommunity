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
