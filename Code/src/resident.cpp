#include "lib/resident.h"
#include <iostream>

Resident::Resident() {}

void Resident::setFirstname(std::string eingabe) {
    firstname = eingabe;
}

void Resident::setPassword(int eingabe) {
    password = eingabe;
}

std::string Resident::getFirstname() {
    return firstname;
}

int Resident::getPassword() {
    return password;
}

void Resident::changePassword() {
    int alt;
    std::cout << "Bitte altes Passwort eingeben: " << std::endl;
    std::cin >> alt;
    if(alt == password) {
        int neu;
        std::cout << "Bitte neues Passwort eingeben:" << std::endl;
        std::cin >> neu;
        setPassword(neu);
    }
    else
        std::cout << "Falsches Passwort!" << std::endl;
}

void Resident::changeName() {
    int pass;
    std::cout << "Bitte Passwort eingeben: " << std::endl;
    std::cin >> pass;
    if(pass == password) {
        std::string neu;
        std::cout << "Bitte neuen Namen eingeben:" << std::endl;
        std::cin >> neu;
        setFirstname(neu);
    }
    else
        std::cout << "Falsches Passwort!" << std::endl;
}
