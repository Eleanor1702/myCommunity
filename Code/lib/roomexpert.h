#ifndef ROOMEXPERT_H
#define ROOMEXPERT_H
#include <vector>
#include "room.h"

class RoomExpert{
    private:
    vector<Room> Roomlist;

    public:
    RoomExpert();
    void createRoom(string name, string typ);
    void deleteRoom(string name);


};
#endif // ROOMEXPERT_H
