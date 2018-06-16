#include "lib/Room.h"

Room::Room() {}
Room::~Room(){}

void Room::setArt(std::string eingabe){
    art = eingabe;
}

void Room::setName(std::string eingabe){
    name = eingabe;
}

std::string Room::getArt(){
    return art;
}

std::string Room::getName(){
    return name;
}
