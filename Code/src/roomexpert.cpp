#include "lib/roomexpert.h"

RoomExpert::RoomExpert(){}

void RoomExpert::createRoom(string name, string typ){
     Room ro;

     ro.setName(name);
     ro.setArt(typ);
     Roomlist.push_back(ro);
}

void RoomExpert::deleteRoom(string name){
        for(vector<Room>::iterator it = Roomlist.begin(); it != Roomlist.end(); ++it) {
            if((it)->getName() == name) {
                Roomlist.erase(it);
            }
        }
}
