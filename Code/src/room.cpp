#include "lib/room.h"
#include <iostream>

using namespace std;

Room::Room() {}

void Room::setArt(string eingabe){
    art = eingabe;
}

void Room::setName(string eingabe){
    name = eingabe;
}

string Room::getArt(){
    return art;
}

string Room::getName(){
    return name;
}
