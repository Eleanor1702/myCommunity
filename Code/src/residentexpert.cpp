#include "lib/residentexpert.h"
#include <string>
#include <iostream>

ResidentExpert::ResidentExpert(){
}

void ResidentExpert::createResident(string name, int password){
    re.setFirstname(name);
    re.setPassword(password);
    Residentlist.push_back(re);
    //std::cout << Residentlist[1];
}

void ResidentExpert::deleteResident(string name){
    for(vector<Resident>::iterator it = Residentlist.begin(); it != Residentlist.end(); ++it) {
        if((it)->getFirstname() == name) {
            Residentlist.erase(it);
        }
    }
}

void ResidentExpert::editResident(string username, int newPassword){
    for(vector<Resident>::iterator it = Residentlist.begin(); it != Residentlist.end(); ++it) {
        if((it)->getFirstname() == username) {
            (it)->setPassword(newPassword);
        }
    }
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

QTextStream& ResidentExpert::qStdOut() {
  static QTextStream ts( stdout );
  return ts;
}
