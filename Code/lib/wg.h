#ifndef WG_H
#define WG_H

#include <string>
#include <vector>
#include "resident.h"
#include "room.h"
#include "userInterface/lib/guicontroller.h"

class WG {
private:
<<<<<<< HEAD
    vector<Raum*> raumListe;
    vector<Bewohner*> bewohnerListe;
=======
    vector<Room*> Roomlist;
    vector<Resident*> Residentlist;
>>>>>>> 85e2b20551bb013ca5174df67a9de20088a76f89
    //GUIController guic;

public:
    WG();
    void createRoom(string art, string name);
    void createResident(string name, int password);
    void deleteResident(Resident* b);
    void deleteRoom(Room* r);
    //Bearbeitenfunktion, die passwort und name ändern beinhaltet?
};

#endif // WG_H

