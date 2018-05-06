#include "lib/resident.h"
#include <iostream>

using namespace std;

Resident::Resident() {}

void Resident::setFirstname(string eingabe) {
    firstname = eingabe;
}

void Resident::setPassword(int eingabe) {
    password = eingabe;
}

string Resident::getFirstname() {
    return firstname;
}

int Resident::getPassword() {
    return password;
}

void Resident::changePassword() {
    int alt;
    cout << "Bitte altes Passwort eingeben: " << endl;
    cin >> alt;
    if(alt == password) {
        int neu;
        cout << "Bitte neues Passwort eingeben:" << endl;
        cin >> neu;
        setPassword(neu);
    }
    else
        cout << "Falsches Passwort!" << endl;
}

void Resident::changeName() {
    int pass;
    cout << "Bitte Passwort eingeben: " << endl;
    cin >> pass;
    if(pass == password) {
        string neu;
        cout << "Bitte neuen Namen eingeben:" << endl;
        cin >> neu;
        setFirstname(neu);
    }
    else
        cout << "Falsches Passwort!" << endl;
}
