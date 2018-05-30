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

        void addEvent (std::string time, std::string date,
                       std::string description, std::string user);
        void deleteEvent(std::string time, std::string date,
                         std::string descpription, std::string user);
    //  void editEvent(std::string time, std::string description, std::string user);



        std::vector<std::string>getRoomNames();
        std::vector<std::string>getRoomArts();
        int getSize();

        std::vector<std::string>getEventTime();
        std::vector<std::string>getEventDate();
        std::vector<std::string>getEventDescription();
        std::vector<std::string>getEventUser();
        int getSizeEvent();


        static Controller* getInstance();
};


#endif // CONTROLLER_H
