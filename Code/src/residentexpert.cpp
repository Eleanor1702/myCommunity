#include "lib/residentexpert.h"

ResidentExpert::ResidentExpert(){
  re = new Resident();
}

void ResidentExpert::createResident(string name, int password){
    re->setFirstname(name);
    re->setPassword(password);
    Residentlist.push_back(re);
    std::cout << Residentlist[1];
}

void ResidentExpert::deleteResident(string name){
    for(vector<Resident*>::iterator it = Residentlist.begin(); it != Residentlist.end(); ++it) {
        if((*it)->getFirstname() == name) {
            Residentlist.erase(it);
        }
    }
}

void ResidentExpert::editResident(string username, int newPassword){
    for(vector<Resident*>::iterator it = Residentlist.begin(); it != Residentlist.end(); ++it) {
        if((*it)->getFirstname() == username) {
            (*it)->setPassword(newPassword);
        }
    }
}

bool ResidentExpert::verifyLogInData(string username, int password){
  for(vector<Resident*>::iterator it = this->Residentlist.begin(); it != this->Residentlist.end(); ++it) {
      string fn = (*it)->getFirstname();
      int pw = (*it)->getPassword();
      if(fn == username && pw == password) {
          return true;
      }
  }
  return false;
}
