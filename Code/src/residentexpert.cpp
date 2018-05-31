#include "lib/residentexpert.h"

ResidentExpert* ResidentExpert::instance = NULL;

ResidentExpert::ResidentExpert(){
    data = data->getInstance();
    Residentlist = data->getAllResidents();
}

void ResidentExpert::createResident(std::string name, int password){
    Resident re;
    re.setFirstname(name);
    re.setPassword(password);
    Residentlist.push_back(re);
    data->addResident(re);
}

void ResidentExpert::deleteResident(std::string name){
    for(std::vector<Resident>::iterator it = Residentlist.begin(); it != Residentlist.end(); ++it) {
        if((it)->getFirstname() == name) {
            Residentlist.erase(it);
            data->deleteResident(name);
            break;
        }
    }
}

void ResidentExpert::editResident(std::string username, int newPassword){
    for(std::vector<Resident>::iterator it = Residentlist.begin(); it != Residentlist.end(); ++it) {
        if((it)->getFirstname() == username) {
            (it)->setPassword(newPassword);
            data->updatePassword(username, newPassword);
            break;

        }
    }

}

bool ResidentExpert::verifyLogInData(std::string username, int password){
  for(std::vector<Resident>::iterator it = this->Residentlist.begin(); it != this->Residentlist.end(); ++it) {
      if((it)->getFirstname() == username && (it)->getPassword() == password) {
          return true;
      }
  }
  return false;
    if(data->verifyLogInData(username, password)) {
            return true;
    }
    else return false;
}

bool ResidentExpert::verifyName(std::string username){
  for(std::vector<Resident>::iterator it = this->Residentlist.begin(); it != this->Residentlist.end(); ++it) {
      if((it)->getFirstname() == username) {
          return true;
      }
  }
  return false;
    if(data->verifyName(username)) {
        return true;
    }
    else return false;
}

ResidentExpert* ResidentExpert::getInstance(){
    if(instance == NULL){
        instance = new ResidentExpert();
        }
    return instance;
}

std::vector<std::string> ResidentExpert::userNameGetter() {
  std::vector<std::string> nameVector;

  for(int i = 0; i < Residentlist.size(); i++){
      nameVector.push_back(Residentlist[i].getFirstname());
  }
  return nameVector;
}

std::vector<Resident> ResidentExpert::getResidents(){
    return Residentlist;
}
