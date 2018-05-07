#include "lib/controller.h"
#include "lib/residentexpert.h"
#include "lib/roomexpert.h"

Controller::Controller(){
    RsExpert = new ResidentExpert();
    RoExpert = new RoomExpert();
    }

void Controller::addRoom(string art, string name){
    RoExpert->createRoom(name, art);
}

void Controller::addResident(string name, int password){
    RsExpert->createResident(name, password);
}

void Controller::deleteRoom(string name){
    RoExpert->deleteRoom(name);
}

void Controller::deleteResident(string name){
    RsExpert->deleteResident(name);
}

void Controller::editResident(string username,int newPassword){
    RsExpert->editResident(username, newPassword);
}
