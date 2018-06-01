#include "lib/RoomExpert.h"

RoomExpert* RoomExpert::instance = NULL;

RoomExpert* RoomExpert::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new RoomExpert(data);
    }
    return instance;
}

RoomExpert::RoomExpert(CommunityData* data){
    this->data = data;
}

void RoomExpert::createRoom(std::string name, std::string typ){
     Room ro;

     ro.setName(name);
     ro.setArt(typ);
     data->addRoom(ro);
}

void RoomExpert::deleteRoom(std::string name){
     data->deleteRoom(name);
}

std::vector<std::string> RoomExpert::roomNameGetter() {
  std::vector<std::string> nameVector;

  for(unsigned int i = 0; i < data->getAllRooms().size(); i++){
      nameVector.push_back(data->getAllRooms()[i].getName());
  }
  return nameVector;
}

std::vector<std::string> RoomExpert::roomArtGetter() {
  std::vector<std::string> artVector;

  for(unsigned int i = 0; i < data->getAllRooms().size(); i++){
      artVector.push_back(data->getAllRooms()[i].getArt());
  }
  return artVector;
}

std::vector<Room> RoomExpert::getRooms() {
  return data->getAllRooms();
}
