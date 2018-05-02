#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "wg.h"

class controller{
   private:
        WG* wg;

   public:
        void addRoom(string art, string name);      //Leitet Daten aus Gui an WG weiter, um neuen Raum zu erstellen
        void addUser(string name, int password);    //Leitet Daten aus Gui an WG weiter, um neuen Bewohner zu erstellen
        void deleteRoom();

};


#endif // CONTROLLER_H
