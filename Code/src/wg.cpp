#include "lib/wg.h"
#include <iostream>

using namespace std;

WG::WG() {}

void WG::createResident(string name, int password){
    //Resident* b1 = new Resident();

    //b1->setFirstname(name);
    //b1->setPassword(password);
    //Residentlist.push_back(b1);
}

void WG::createRoom(string art, string name) {

    //Room* r1 = new Room();

    //r1->setArt(art);
    //r1->setName(name);
    //Roomlist.push_back(r1);
}

void WG::deleteResident(Resident* bew) {
    for(vector<Resident*>::iterator it = Residentlist.begin(); it != Residentlist.end(); ++it) {
        if(bew == *it) {
            Residentlist.erase(it);
            cout << "Löschen erfolgreich!" << endl;
        }
    }
}

/*void WG::deleteRoom(Room* room) {
    for(vector<Room*>::iterator it = Roomlist.begin(); it != Roomlist.end(); ++it) {
        if(room == *it) {
            Roomlist.erase(it);
            cout << "Löschen erfolgreich!" << endl;
        }
    }
}*/
