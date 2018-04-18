#include "lib/raum.h"
#include <iostream>

using namespace std;

Raum::Raum() {};

void Raum::setArt(string eingabe){
    art = eingabe;
}

void Raum::setName(string eingabe){
    name = eingabe;
}

string Raum::getArt(){
    return art;
}

string Raum::getName(){
    return name;
}
