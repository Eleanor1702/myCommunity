#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "residentexpert.h"
#include "roomexpert.h"

//Soll zwischen GUI und Logik vermitteln
class Controller{
   private:
        ResidentExpert* RsExpert;
        RoomExpert*  RoExpert;

   public:
        Controller();
        void addRoom(string art, string name);      //From Gui to WG (create Rooms)
        void addResident(string name, int password);    //From Gui to WG (add Users)
        void deleteRoom(string name);
        void deleteResident(string name);
        void editResident(string username,int newPassword);

};


#endif // CONTROLLER_H
