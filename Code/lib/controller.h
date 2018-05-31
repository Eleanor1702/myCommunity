#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "residentexpert.h"
#include "roomexpert.h"
#include "eventexpert.h"
#include "taskexpert.h"

//Connector between GUI and Logic
class Controller{
private:
        friend class GuiController;

        ResidentExpert* rsExpert;
        RoomExpert*  roExpert;
        EventExpert* evExpert;
        TaskExpert* taExpert;

        static Controller* instance;                    //Singleton

        std::string user;                                    //aktueller User, der angemeldet ist

protected:
        Controller();
public:
        void addRoom(std::string art, std::string name);          //From Gui to WG (create Rooms)
        void addResident(std::string name, int password);    //From Gui to WG (add Users)
        void deleteRoom(std::string name);
        void deleteResident(std::string name);
        void editResident(std::string username,int newPassword);
        bool searchResident(std::string username, int password);
        bool searchNameResident(std::string username);       // To get the same Name in Login

        void addEvent(std::string description, std::string timedate, std::string user);
        void deleteEvent(std::string description, std::string timedate, std::string user);
        void editEvent(std::string description, std::string timedate);

        void addTask();
        void deleteTask();
        void editTask();

        std::vector<std::string>getRoomNames();
        std::vector<std::string>getRoomArts();
        int getRoomlistSize();

        std::vector<std::string>getUserNames();
        int getUserlistSize();

        static Controller* getInstance();
};


#endif // CONTROLLER_H
