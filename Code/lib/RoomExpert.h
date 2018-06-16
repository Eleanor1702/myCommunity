#ifndef ROOMEXPERT_H
#define ROOMEXPERT_H

#include <vector>
#include "Room.h"
#include "Database/lib/communitydata.h"

class RoomExpert{
private:
    static RoomExpert* instance;

    CommunityData* data;

protected:
    RoomExpert(CommunityData* data);

public:
    void createRoom(std::string name, std::string typ);
    void deleteRoom(std::string name);

    std::vector<std::string> roomNameGetter();
    std::vector<std::string> roomArtGetter();

    std::vector<Room> getRooms();

    static RoomExpert* getInstance(CommunityData* data);
};

#endif // ROOMEXPERT_H
