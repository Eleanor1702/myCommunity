#include "lib/Resident.h"
#include <iostream>

Resident::Resident() {}

Resident::~Resident() {}

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
