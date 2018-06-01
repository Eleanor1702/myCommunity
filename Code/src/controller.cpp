#include "lib/controller.h"

Controller* Controller::instance = NULL;

Controller::Controller(CommunityData* data){
   rsExpert = rsExpert->getInstance(data);
   roExpert = roExpert->getInstance(data);
   evExpert = evExpert->getInstance(data);
   taExpert = taExpert->getInstance();
}

//  RoomExpert

void Controller::addRoom(std::string art, std::string name){
    roExpert->createRoom(name, art);
}

void Controller::deleteRoom(std::string name){
    roExpert->deleteRoom(name);
}

//  ResidentExpert

void Controller::addResident(std::string name, int password){
    rsExpert->createResident(name, password);
}

void Controller::deleteResident(std::string name){
    rsExpert->deleteResident(name);
}

void Controller::editResident(std::string username,int newPassword){
    rsExpert->editResident(username, newPassword);
}

bool Controller::searchResident(std::string username, int password) {
  if(rsExpert->verifyLogInData(username, password)) {
      user = username;
      return true;
    }
  else return false;
}
bool Controller::searchNameResident(std::string username){
    return rsExpert->verifyName(username);
}

// EventController

/*void Controller::addEvent(std::string description, std::string timedate, std::string user){
    evExpert->createEvent(description, timedate, user);
}

void Controller::deleteEvent(std::string description, std::string timedate, std::string user){
    evExpert->deleteEvent(description, timedate, user);
}

void Controller::editEvent(std::string description, std::string timedate){
    evExpert->editEvent(description, timedate);
}
*/
//



std::vector<std::string> Controller::getRoomNames() {
  return roExpert->roomNameGetter();
}

std::vector<std::string> Controller::getRoomArts() {
  return roExpert->roomArtGetter();
}

int Controller::getRoomlistSize() {
  return roExpert->Roomlist.size();
}


std::vector<std::string> Controller::getUserNames(){
    return rsExpert->userNameGetter();
}
int Controller::getUserlistSize(){
    return rsExpert->getResidents().size();
}

void Controller::addEvent(std::string time, std::string date,std::string description, std::string user){
    evExpert->createEvent(time, date, description, user);
}

void Controller::deleteEvent(std::string time, std::string date, std::string descpription, std::string user){
    evExpert->deleteEvent(time, date, descpription, user);
}
/*
void Controller::editEvent(std::string time, std::string description, std::string user){
    evExpert->editEvent(time, description, user);
}
*/
std::vector<std::string> Controller::getEventTime(){
    return evExpert->eventTimeGetter();
}
std::vector<std::string> Controller::getEventDate(){
    return evExpert->eventDateGetter();
}
std::vector<std::string> Controller::getEventDescription(){
    return evExpert->eventDescriptionGetter();
}
std::vector<std::string> Controller::getEventUser(){
    return evExpert->eventUserGetter();
}

int Controller::getSizeEvent(){
    return evExpert->Eventlist.size();
}

//Current User Methods

void Controller::setCurrentUser(std::string user){
    rsExpert->setCurrentUser(user);
}

std::string Controller::getCurrentUser(){
    return rsExpert->getCurrentUser();
}

Controller* Controller::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new Controller(data);
    }
    return instance;
}
