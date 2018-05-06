#ifndef WG_H
#define WG_H

#include <string>
#include <vector>
#include "resident.h"
//#include "room.h"
#include "userInterface/lib/guicontroller.h"

class WG {
private:

    //vector<Room*> Roomlist;
    vector<Resident*> Residentlist;

    //GUIController guic;

public:
    WG();
    void createRoom(string art, string name);
    void createResident(string name, int password);
    void deleteResident(Resident* b);
    //void deleteRoom(Room* r);
    //Bearbeitenfunktion, die passwort und name ändern beinhaltet?
};

#endif // WG_H

