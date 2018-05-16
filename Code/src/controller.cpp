#include "lib/controller.h"
#include "lib/residentexpert.h"
#include "lib/roomexpert.h"

Controller* Controller::instance = NULL;

Controller::Controller(){
    rsExpert->getInstance();
    roExpert->getInstance();
}

void Controller::addRoom(string art, string name){
    roExpert->createRoom(name, art);
}

void Controller::addResident(string name, int password){
    rsExpert->createResident(name, password);
}

void Controller::deleteRoom(string name){
    roExpert->deleteRoom(name);
}

void Controller::deleteResident(string name){
    rsExpert->deleteResident(name);
}

void Controller::editResident(string username,int newPassword){
    rsExpert->editResident(username, newPassword);
}

bool Controller::searchResident(string username, int password) {
  return rsExpert->verifyLogInData(username, password);
}
bool Controller::searchNameResident(string username){
    return rsExpert->verifyName(username);
}

Controller* Controller::getInstance(){
    if(instance == NULL){
        instance = new Controller();
        //instance->rsExpert->getInstance();
        //instance->roExpert->getInstance() ;
    }
    return instance;
}

