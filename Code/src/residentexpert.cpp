#include "lib/residentexpert.h"

ResidentExpert::ResidentExpert(){}

void ResidentExpert::createResident(string name, int password){
    Resident* re = new Resident();

    re->setFirstname(name);
    re->setPassword(password);
    Residentlist.push_back(re);
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
