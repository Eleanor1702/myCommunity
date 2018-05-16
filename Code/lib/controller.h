#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "residentexpert.h"
#include "roomexpert.h"
#include "eventexpert.h"

//Connector between GUI and Logic
class Controller{
private:
        friend class GuiController;

        ResidentExpert* rsExpert;
        RoomExpert*  roExpert;
        EventExpert* evExpert;

        static Controller* instance;                    //Singleton

protected:
        Controller();
public:
        void addRoom(string art, string name);          //From Gui to WG (create Rooms)
        void addResident(string name, int password);    //From Gui to WG (add Users)
        void deleteRoom(string name);
        void deleteResident(string name);
        void editResident(string username,int newPassword);
        bool searchResident(string username, int password);
        bool searchNameResident(string username);       // To get the same Name in Login

        static Controller* getInstance();
};


#endif // CONTROLLER_H
