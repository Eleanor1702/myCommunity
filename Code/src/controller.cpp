#include "lib/controller.h"

Controller* Controller::instance = NULL;

Controller::Controller(CommunityData* data){
   rsExpert = rsExpert->getInstance(data);
   roExpert = roExpert->getInstance(data);
   evExpert = evExpert->getInstance(data);
   taExpert = taExpert->getInstance(data);
   shExpert = shExpert->getInstance(data);
}

//  RoomExpert

void Controller::addRoom(std::string art, std::string name){
    roExpert->createRoom(name, art);
}
void Controller::deleteRoom(std::string name){
    roExpert->deleteRoom(name);
}
std::vector<std::string> Controller::getRoomNames() {
  return roExpert->roomNameGetter();
}

std::vector<std::string> Controller::getRoomArts() {
  return roExpert->roomArtGetter();
}

int Controller::getRoomlistSize() {
  return roExpert->getRooms().size();
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
        //user = username;
        return true;
    }else{
        return false;
    }
}
bool Controller::searchNameResident(std::string username){
    return rsExpert->verifyName(username);
}
std::vector<std::string> Controller::getUserNames(){
    return rsExpert->userNameGetter();
}
int Controller::getUserlistSize(){
    return rsExpert->userNameGetter().size();
}

// EventExpert

void Controller::addEvent(std::string time, std::string date,std::string description, std::string user){
    std::string currentUser = user;
    if (user=="privat"){
        currentUser=rsExpert->getCurrentUser();
    }
    evExpert->createEvent(time, date, description, currentUser);
}

void Controller::deleteEvent(std::string time, std::string date, std::string descpription, std::string user){
    evExpert->deleteEvent(time, date, descpription, user);
}
/*
void Controller::editEvent(std::string time, std::string date, std::string description, std::string user, std::string newtime, std::string newdate, std::string newdescription ){
    evExpert->editEvent(time, date, description, user, newtime, newdate, newdescription);
}
*/
std::vector<std::string> Controller::getEventTime(std::string user, std::string date){
    return evExpert->eventTimeGetter(user, date);
}
std::vector<std::string> Controller::getEventDate(std::string user, std::string date){
    return evExpert->eventDateGetter(user, date);
}
std::vector<std::string> Controller::getEventDescription(std::string user, std::string date){
    return evExpert->eventDescriptionGetter(user, date);
}
std::vector<std::string> Controller::getEventUser(std::string user, std::string date){
    return evExpert->eventUserGetter(user, date);
}

int Controller::getSizeEvent(std::string user, std::string date){
    return evExpert->eventSizeGetter(user, date);
}

//TaskExpert

void Controller::addTask(std::string name, std::string room, std::string frequency) {
    taExpert->createTask(name, room, frequency);
}

void Controller::deleteTask(std::string name, std::string room) {
    taExpert->deleteTask(name, room);
}
//editTask

std::vector<std::string> Controller::getTaskName(){
    return taExpert->taskNameGetter();
}
std::vector<std::string> Controller::getTaskRoom(){
    return taExpert->taskRoomGetter();
}
std::vector<std::string> Controller::getTaskFrequency(){
    return taExpert->taskFrequencyGetter();
}
int Controller::getTasklistSize(){
    return taExpert->getTasks().size();
}

//concreteTask
void Controller::addConcreteTask(int week, std::string task, std::string res, std::string room) {
    taExpert->createConcreteTask(task, res, week, room);
}

void Controller::deleteConcreteTask(int week, std::string task, std::string res, std::string room){
    taExpert->deleteConcreteTask(task, res, week, room);
}

std::vector<int> Controller::getConcreteTaskWeek(){
    return taExpert->concreteTaskWeekGetter(getCurrentCW());
}
std::vector<std::string> Controller::getConcreteTaskName(){
    return taExpert->concreteTaskNameGetter(getCurrentCW());
}
std::vector<std::string> Controller::getConcreteTaskRes(){
    return taExpert->concreteTaskResGetter(getCurrentCW());
}
std::vector<std::string> Controller::getConcreteTaskRoom(){
    return taExpert->concreteTaskRoomGetter(getCurrentCW());
}
int Controller::getConcreteTaskListSize(){
    return taExpert->concreteTaskGetter(getCurrentCW()).size();
}

//ShoppingExpert

void Controller::addItem(std::string itemname, std::string number) {
    shExpert->createItem(itemname, number);
}

void Controller::deleteItem(std::string itemname) {
    shExpert->deleteItem(itemname);
}

std::vector<std::string> Controller::getItemNames() {
    return shExpert->itemNameGetter();
}
std::vector<std::string> Controller::getItemNumbers() {
    return shExpert->itemNumberGetter();
}
int Controller::getItemlistSize() {
    return shExpert->getItems().size();
}

//Exporter

void Controller::exportCleaningPlan(){
    expo->exportCleaningplan(getCurrentCW());
}

void Controller::exportShoppingList(){
    expo->exportShopinglist();
}

//Current User Methods

void Controller::setCurrentUser(std::string user){
    rsExpert->setCurrentUser(user);
}

std::string Controller::getCurrentUser(){
    return rsExpert->getCurrentUser();
}

int Controller::getCurrentCW(){
    return taExpert->getCurrentCW();
}


Controller* Controller::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new Controller(data);
    }
    return instance;
}
