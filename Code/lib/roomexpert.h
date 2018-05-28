#ifndef ROOMEXPERT_H
#define ROOMEXPERT_H

#include <vector>
#include "room.h"
#include "Database/lib/communitydata.h"

class RoomExpert{
private:
    friend class Controller;

    std::vector<Room> Roomlist;
    static RoomExpert* instance;

    //CommunityData* data;

protected:
    RoomExpert();
public:

    void createRoom(std::string name, std::string typ);
    void deleteRoom(std::string name);
    std::vector<std::string> roomNameGetter();
    std::vector<std::string> roomArtGetter();

    std::vector<Room> getRooms();

    static RoomExpert* getInstance();

};
#endif // ROOMEXPERT_H
