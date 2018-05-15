#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "residentexpert.h"
#include "roomexpert.h"

//Soll zwischen GUI und Logik vermitteln
class Controller{
   private:
        ResidentExpert* rsExpert;
        RoomExpert*  roExpert;
        static Controller* instance;             //Singleton



protected:
        Controller();
   public:
        void addRoom(string art, string name);      //From Gui to WG (create Rooms)
        void addResident(string name, int password);    //From Gui to WG (add Users)
        void deleteRoom(string name);
        void deleteResident(string name);
        void editResident(string username,int newPassword);
        bool searchResident(string username, int password);
        bool searchNameResident(string username);   // Damit Login selbe Namen abfängt

        static Controller* getInstance();


};


#endif // CONTROLLER_H
