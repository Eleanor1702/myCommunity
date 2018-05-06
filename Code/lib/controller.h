#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "wg.h"
#include "userInterface/lib/guicontroller.h"

//Soll zwischen GUI und Logik vermitteln
class Controller{
   private:
        WG *wg;
        GuiController *guic;

   public:
        Controller();
        void addRoom(string art, string name);      //Leitet Daten aus Gui an WG weiter, um neuen Raum zu erstellen
        void addUser(string name, int password);    //Leitet Daten aus Gui an WG weiter, um neuen Bewohner zu erstellen
        void deleteRoom();
        void deleteUser();

};


#endif // CONTROLLER_H
