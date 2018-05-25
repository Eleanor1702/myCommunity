#include "lib/controller.h"

Controller* Controller::instance = NULL;

Controller::Controller(){
   rsExpert = rsExpert->getInstance();
   roExpert = roExpert->getInstance();
   evExpert = evExpert->getInstance();
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
  if(rsExpert->verifyLogInData(username, password)) {
      user = username;
      return true;
    }
  else return false;
}
bool Controller::searchNameResident(string username){
    return rsExpert->verifyName(username);
}

std::vector<std::string> Controller::getRoomNames() {
  return roExpert->roomNameGetter();
}

std::vector<std::string> Controller::getRoomArts() {
  return roExpert->roomArtGetter();
}

int Controller::getSize() {
  return roExpert->Roomlist.size();
}

Controller* Controller::getInstance(){
    if(instance == NULL){
        instance = new Controller();
    }
    return instance;
}

