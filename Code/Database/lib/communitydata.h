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

#include "lib/resident.h"
#include "lib/room.h"
#include "lib/event.h"
#include "lib/Task.h"
#include <time.h>

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
    void createRoomTable();
    void createResidentTable();
    void createCalendarTable();
    //void createEventUserView(string user);
    void createEventCommunityView();
    void createCleaningTable();
    void createTaskTable();
    void createShoppinglistTable();

    void addResident(Resident re);
    void addRoom(Room ro);
    void addEvent(Event ev);
    void addTask(Task ta);
    void addToCleaningplan(std::string task, std::string resident, std::string week);
    void addItem(std::string item, int number);

    void updatePassword(std::string user, int password);
    void updateEvent(Event ev, std::string timedate,std::string description);

    void deleteResident(std::string name);
    void deleteRoom(std::string name);
    void deleteEvent(Event ev);

    void deleteAllTaskOfRoom(std::string room);
    void deleteTaskByName(std::string taskname, std::string room );

    void deleteCalendar(std::string user);

    void deleteTaskCleaningplan(std::string task);
    void deleteResidentCleaningplan(std::string resident);
    void deleteRoomCleaningplan(std::string room);

    void deleteShoppinglistItem(std::string item);

    std::vector<std::string> getAllResidents();
    std::vector<Room> getAllRooms();
    std::vector<Event> getAllEventsOfUser(std::string user);
    std::vector<Event> getAllCommunityEvents();
    std::vector<Event> getAllEvents();
    std::vector<Task> getAllTasks();

    // getCleaningPlan()

    bool verifyLogInData(std::string, int);
    bool verifyName(std::string);
};

#endif // COMMUNITYDATA_H
