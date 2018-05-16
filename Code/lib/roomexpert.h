#ifndef ROOMEXPERT_H
#define ROOMEXPERT_H
#include <vector>
#include "room.h"
#include "Database/lib/communitydata.h"

class RoomExpert{
private:
    vector<Room> Roomlist;
    static RoomExpert* instance;
    //CommunityData* data;

protected:
    RoomExpert();
public:

    void createRoom(string name, string typ);
    void deleteRoom(string name);

    static RoomExpert* getInstance();

};
#endif // ROOMEXPERT_H
