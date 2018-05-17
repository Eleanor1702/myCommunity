#include "lib/roomexpert.h"

RoomExpert* RoomExpert::instance = NULL;

RoomExpert::RoomExpert(){
    data = data->getInstance();
    Roomlist = data->getAllRooms();
}

void RoomExpert::createRoom(string name, string typ){
     Room ro;

     ro.setName(name);
     ro.setArt(typ);
     Roomlist.push_back(ro);
     data->addRoom(name, typ);
}

void RoomExpert::deleteRoom(string name){
        for(vector<Room>::iterator it = Roomlist.begin(); it != Roomlist.end(); ++it) {
            if((it)->getName() == name) {
                Roomlist.erase(it);
                data->deleteRoom(name);
                break;
            }
        }   
}

RoomExpert* RoomExpert::getInstance(){
    if(instance == NULL){
        instance = new RoomExpert();
    }
    return instance;
}
