#include "lib/RoomExpert.h"

RoomExpert* RoomExpert::instance = NULL;

RoomExpert* RoomExpert::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new RoomExpert(data);
    }
    return instance;
}

//connect to database
RoomExpert::RoomExpert(CommunityData* data){
    this->data = data;
}

//create a new room
void RoomExpert::createRoom(std::string name, std::string typ){
     Room ro;
     ro.setName(name);
     ro.setArt(typ);
     data->addRoom(ro);
}

//delete a room
void RoomExpert::deleteRoom(std::string name){
     data->deleteRoom(name);
}

//get all names of rooms as strings
std::vector<std::string> RoomExpert::roomNameGetter() {
  std::vector<std::string> nameVector;

  for(unsigned int i = 0; i < getRooms().size(); i++){
      nameVector.push_back(getRooms()[i].getName());
  }
  return nameVector;
}

//get the types of rooms as strings
std::vector<std::string> RoomExpert::roomArtGetter() {
  std::vector<std::string> artVector;

  for(unsigned int i = 0; i < getRooms().size(); i++){
      artVector.push_back(getRooms()[i].getArt());
  }
  return artVector;
}

//get all rooms od database as roomtypes
std::vector<Room> RoomExpert::getRooms() {
  return data->getAllRooms();
}
