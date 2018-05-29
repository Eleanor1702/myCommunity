#include "lib/roomexpert.h"

RoomExpert* RoomExpert::instance = NULL;

RoomExpert::RoomExpert(){
    data = data->getInstance();
    Roomlist = data->getAllRooms();
}

void RoomExpert::createRoom(std::string name, std::string typ){
     Room ro;

     ro.setName(name);
     ro.setArt(typ);
     Roomlist.push_back(ro);
     data->addRoom(name, typ);
}

void RoomExpert::deleteRoom(std::string name){
        for(std::vector<Room>::iterator it = Roomlist.begin(); it != Roomlist.end(); ++it) {
            if((it)->getName() == name) {
                Roomlist.erase(it);
                data->deleteRoom(name);
                break;
            }
        }   
}

std::vector<std::string> RoomExpert::roomNameGetter() {
  std::vector<std::string> nameVector;

  for(unsigned int i = 0; i < Roomlist.size(); i++){
      nameVector.push_back(Roomlist[i].getName());
  }
  return nameVector;
}

std::vector<std::string> RoomExpert::roomArtGetter() {
  std::vector<std::string> artVector;

  for(unsigned int i = 0; i < Roomlist.size(); i++){
      artVector.push_back(Roomlist[i].getArt());
  }
  return artVector;
}

std::vector<Room> RoomExpert::getRooms() {
  return Roomlist;
}

RoomExpert* RoomExpert::getInstance(){
    if(instance == NULL){
        instance = new RoomExpert();
    }
    return instance;
}
