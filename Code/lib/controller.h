#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "wg.h"
#include "userInterface/lib/guicontroller.h"

//Soll zwischen GUI und Logik vermitteln
class Controller{
   private:
        WG *wg;
        //GUIController *guic;

   public:
        Controller();
        void addRoom(string art, string name);      //From Gui to WG (create Rooms)
        void addUser(string name, int password);    //From Gui to WG (add Users)
        void deleteRoom();
        void deleteUser();

};


#endif // CONTROLLER_H
