#include "lib/residentexpert.h"
#include <string>
#include <iostream>

ResidentExpert* ResidentExpert::instance = NULL;

ResidentExpert::ResidentExpert(){
    //data = data->getInstance();
}

void ResidentExpert::createResident(string name, int password){
    Resident re;
    re.setFirstname(name);
    re.setPassword(password);
    Residentlist.push_back(re);
    //data->addResident(name, password);
}

void ResidentExpert::deleteResident(string name){
    for(vector<Resident>::iterator it = Residentlist.begin(); it != Residentlist.end(); ++it) {
        if((it)->getFirstname() == name) {
            Residentlist.erase(it);
        }
    }
    //data->deleteResident(name);
}

void ResidentExpert::editResident(string username, int newPassword){
    for(vector<Resident>::iterator it = Residentlist.begin(); it != Residentlist.end(); ++it) {
        if((it)->getFirstname() == username) {
            (it)->setPassword(newPassword);
        }
    }
    //data->updatePassword(username, newPassword);
}

bool ResidentExpert::verifyLogInData(string username, int password){
  for(std::vector<Resident>::iterator it = this->Residentlist.begin(); it != this->Residentlist.end(); ++it) {
      if((it)->getFirstname() == username && (it)->getPassword() == password) {
          return true;
      }
  }
  return false;
}

bool ResidentExpert::verifyName(string username){
  for(std::vector<Resident>::iterator it = this->Residentlist.begin(); it != this->Residentlist.end(); ++it) {
      if((it)->getFirstname() == username) {
          return true;
      }
  }
  return false;
}

ResidentExpert* ResidentExpert::getInstance(){
    if(instance == NULL){
        instance = new ResidentExpert();
        }
    return instance;
}
