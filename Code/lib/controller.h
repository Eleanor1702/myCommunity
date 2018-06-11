#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ResidentExpert.h"
#include "RoomExpert.h"
#include "EventExpert.h"
#include "taskexpert.h"

//Connector between GUI and Logic
class Controller{
private:
        friend class GuiController;

        ResidentExpert* rsExpert;
        RoomExpert*  roExpert;
        EventExpert* evExpert;
        TaskExpert* taExpert;

        static Controller* instance;                         //Singleton

        std::string user;                                    //aktueller User, der angemeldet ist

protected:
        Controller(CommunityData* data);

public:
        void addRoom(std::string art, std::string name);          //From Gui to WG (create Rooms)
        void addResident(std::string name, int password);    //From Gui to WG (add Users)
        void deleteRoom(std::string name);
        void deleteResident(std::string name);
        void editResident(std::string username,int newPassword);
        bool searchResident(std::string username, int password);
        bool searchNameResident(std::string username);       // To get the same Name in Login

        void addTask(std::string name, std::string room, std::string frequency);
        void deleteTask(std::string name, std::string room);
        void editTask();

        void addEvent (std::string time, std::string date,
                       std::string description, std::string user);
        void deleteEvent(std::string time, std::string date,
                         std::string descpription, std::string user);
        void editEvent(std::string time, std::string date, std::string description, std::string user, std::string newtime, std::string newdate, std::string newdescription);

        //Methods currentUser
        void setCurrentUser(std::string user);
        std::string getCurrentUser();

        std::vector<std::string>getRoomNames();
        std::vector<std::string>getRoomArts();
        int getRoomlistSize();

        std::vector<std::string>getUserNames();
        int getUserlistSize();

        std::vector<std::string>getEventTime();
        std::vector<std::string>getEventDate();
        std::vector<std::string>getEventDescription();
        std::vector<std::string>getEventUser();
        int getSizeEvent();

        static Controller* getInstance(CommunityData* data);
};


#endif // CONTROLLER_H
