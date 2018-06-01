#include "lib/ResidentExpert.h"

ResidentExpert* ResidentExpert::instance = NULL;

ResidentExpert* ResidentExpert::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new ResidentExpert(data);
        }
    return instance;
}

ResidentExpert::ResidentExpert(CommunityData* data){
    this->data = data;
}

void ResidentExpert::createResident(std::string name, int password){
    Resident re;

    re.setFirstname(name);
    re.setPassword(password);
    data->addResident(re);
}

void ResidentExpert::deleteResident(std::string name){
    data->deleteResident(name);
}

void ResidentExpert::editResident(std::string username, int newPassword){
    for(int i = 0; i < getResidents().size(); i++) {
        if(getResidents()[i].getFirstname() == username) {
            getResidents()[i].setPassword(newPassword);
            data->updatePassword(username, newPassword);
            break;
        }
    }
}

bool ResidentExpert::verifyLogInData(std::string username, int password){
    for(int i = 0; i < getResidents().size(); i++) {
        if(getResidents()[i].getFirstname() == username && getResidents()[i].getPassword() == password) {
            return true;
        }
    }

    return false;
}

bool ResidentExpert::verifyName(std::string username){
    for(int i = 0; i < getResidents().size(); i++) {
        if(getResidents()[i].getFirstname() == username) {
            return true;
        }
    }

    return false;
}

std::vector<std::string> ResidentExpert::userNameGetter() {
  std::vector<std::string> nameVector;

  for(int i = 0; i < data->getAllResidents().size(); i++){
      nameVector.push_back(data->getAllResidents()[i].getFirstname());
  }
  return nameVector;
}

std::vector<Resident> ResidentExpert::getResidents(){
    return data->getAllResidents();
}

void ResidentExpert::setCurrentUser(std::string newUser){
    currentUser = newUser;
}

std::string ResidentExpert::getCurrentUser(){
    return currentUser;
}
