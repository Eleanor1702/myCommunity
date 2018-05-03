#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include "Roomlistitem.h"
#include "SetUpRooms.h"
#include "SetUpUsers.h"
#include "SignUp.h"
#include "UserList.h"

class GUIController{
public:
    GUIController();

private:
    SetUpRooms setRooms;
    SetUpUsers setUsers;
    RoomListItem roomItem;
    UserList userItem;

};
#endif // GUICONTROLLER_H
