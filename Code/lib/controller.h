#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ResidentExpert.h"
#include "RoomExpert.h"
#include "EventExpert.h"
#include "taskexpert.h"
#include "shoppingexpert.h"

//Connector between GUI and Logic
class Controller{
private:
        friend class GuiController;

        ResidentExpert* rsExpert;
        RoomExpert*  roExpert;
        EventExpert* evExpert;
        TaskExpert* taExpert;
        ShoppingExpert* shExpert;

        static Controller* instance;                         //Singleton

        std::string user;                                    //aktueller User, der angemeldet ist

protected:
        Controller(CommunityData* data);

public:
        //Room
        void addRoom(std::string art, std::string name);
        void deleteRoom(std::string name);
        std::vector<std::string>getRoomNames();
        std::vector<std::string>getRoomArts();
        int getRoomlistSize();

        //Resident
        void addResident(std::string name, int password);
        void deleteResident(std::string name);
        void editResident(std::string username,int newPassword);
        bool searchResident(std::string username, int password);
        bool searchNameResident(std::string username);       // To get the same Name in Login
        std::vector<std::string>getUserNames();
        int getUserlistSize();

        //Task
        void addTask(std::string name, std::string room, std::string frequency);
        void deleteTask(std::string name, std::string room);
        void editTask();
        std::vector<std::string>getTaskName();
        std::vector<std::string>getTaskRoom();
        std::vector<std::string>getTaskFrequency();
        int getTasklistSize();

        //Event
        void addEvent (std::string time, std::string date, std::string description, std::string user);
        void deleteEvent(std::string time, std::string date, std::string descpription, std::string user);
        void editEvent(std::string time, std::string date, std::string description, std::string user, std::string newtime, std::string newdate, std::string newdescription);       
        std::vector<std::string>getEventTime(std::string user, std::string date);
        std::vector<std::string>getEventDate(std::string user, std::string date);
        std::vector<std::string>getEventDescription(std::string user, std::string date);
        std::vector<std::string>getEventUser(std::string user, std::string date);
        int getSizeEvent(std::string user, std::string date);

        //Shopping items
        void addItem(std::string itemname, int number);
        void deleteItem(std::string itemname);
        std::vector<std::string> getItemNames();
        std::vector<int> getItemNumbers();
        int getItemlistSize();

        //Methods currentUser
        void setCurrentUser(std::string user);
        std::string getCurrentUser();

        static Controller* getInstance(CommunityData* data);
};


#endif // CONTROLLER_H
