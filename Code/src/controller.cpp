#include "lib/controller.h"

Controller::controller(){
    wg = new WG;
    guic = new GUIController;
}


void Controller::addRoom(string art, string name){}
void Controller::addUser(string name, int password){}
void Controller::deleteRoom(){}
void Controller::deleteUser(){}
