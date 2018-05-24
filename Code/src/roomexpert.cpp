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
int RoomExpert::GetSizeAndUpdate() {
    Roomlist = data->getAllRooms(); //nochmal zur Sicherheit akuellen Daten aus DB holen
    return Roomlist.size();
}

string RoomExpert::RoomGetterName(int i) {
    return Roomlist[i].getName();
}
string RoomExpert::RoomGetterArt(int i) {
    return Roomlist[i].getArt();
}

RoomExpert* RoomExpert::getInstance(){
    if(instance == NULL){
        instance = new RoomExpert();
    }
    return instance;
}
