#ifndef COMMUNITYDATA_H
#define COMMUNITYDATA_H

#include <vector>

//#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>

#include "lib/Resident.h"
#include "lib/Room.h"
#include "lib/event.h"
#include "lib/Task.h"
#include "lib/shoppingitem.h"
#include "lib/concretetask.h"


class CommunityData {
private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection* con;
    sql::ConnectOptionsMap connection_properties;
    static CommunityData* instance;

protected:
    CommunityData(std::string user, std::string password, std::string host, std::string database);

public:
    static CommunityData* getInstance(std::string user, std::string password, std::string host, std::string database);

    ~CommunityData();

    bool connect(std::string user, std::string password, std::string host, std::string database);
    //Rooms
    void createRoomTable();
    void addRoom(Room ro);
    void deleteRoom(std::string name);
    std::vector<Room> getAllRooms();

    //Residents
    void createResidentTable();
    void addResident(Resident re);
    void updatePassword(std::string user, int password);
    void deleteResident(std::string name);
    std::vector<std::string> getAllResidents();
    bool verifyLogInData(std::string, int);
    bool verifyName(std::string);

    //Calendar
    void createCalendarTable();
    //void createEventUserView(string user);
    void createEventCommunityView();
    void addEvent(Event ev);
    void updateEvent(Event ev, std::string timedate,std::string description);
    void deleteEvent(Event ev);
    void deleteCalendar(std::string user);
    std::vector<Event> getAllEventsOfUser(std::string user, std::string datetime);
    std::vector<Event> getAllCommunityEvents();
    std::vector<Event> getAllEvents(std::string user, std::string date);

    //Cleaning plan
    void createCleaningTable();
    void addToCleaningplan(ConcreteTask ctask);
    void deleteConcreteTask(Task ta, std::string resident, int week);
    void deleteTaskCleaningplan(std::string name, std::string room);
    void deleteResidentCleaningplan(std::string resident);
    void deleteRoomCleaningplan(std::string room);
    std::vector<ConcreteTask> getAllConcreteTasks();

    //Tasks
    void createTaskTable();
    void addTask(Task ta);
    void deleteAllTaskOfRoom(std::string room);
    void deleteTaskByName(std::string taskname, std::string room );
    std::vector<Task> getAllTasks();

    //Shoppinglist
    void createShoppinglistTable();
    void addItem(Shoppingitem si);
    void deleteShoppinglistItem(std::string item);
    std::vector<Shoppingitem> getAllItems();
};

#endif // COMMUNITYDATA_H
