#include "lib/roomexpert.h"

RoomExpert::RoomExpert(){}

RoomExpert* RoomExpert::instance = NULL;

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

RoomExpert* RoomExpert::getInstance(){
    if(instance == NULL){
        instance = new RoomExpert();
    }
    return instance;
}
