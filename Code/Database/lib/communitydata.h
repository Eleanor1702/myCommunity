#ifndef COMMUNITYDATA_H
#define COMMUNITYDATA_H

#include <vector>

#include <cppconn/connection.h>
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
#include "lib/task.h"
#include <time.h>

class CommunityData {
private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection* con;
    sql::ConnectOptionsMap connection_properties;
    static CommunityData* instance;

protected:
    CommunityData();

public:
    bool connect();
    void createRoomTable();
    void createResidentTable();
    void createCalendarTable();
    //void createEventUserView(string user);
    void createEventCommunityView();
    void createCleaningTable();
    void createTaskTable();
    //void createShoppinglistTable();

    void addResident(std::string name, int password);
    void addRoom(std::string name, std::string type);
    void addEvent(std::string timedate, std::string description, std::string user);
    void addTask(std::string taskname, std::string room, std::string frequency);
    void addToCleaningplan(std::string task, std::string resident, std::string week);

    void updatePassword(std::string user, int password);
    void updateEvent(Event ev, std::string timedate,std::string description);

    void deleteResident(std::string name);
    void deleteRoom(std::string name);
    void deleteEvent(std::string timedate, std::string description, std::string user);
    void deleteTaskByName(std::string taskname);
    void deleteTaskByRoom(std::string room);
    void deleteCalendar(std::string user);
    void deleteTaskCleaningplan(std::string task);
    void deleteResidentCleaningplan(std::string resident);
    void deleteRoomCleaningplan(std::string room);

    std::vector<Resident> getAllResidents();
    std::vector<Room> getAllRooms();
    std::vector<Event> getAllEventsOfUser(std::string user);
    std::vector<Event> getAllCommunityEvents();
    std::vector<Task> getAllTasks();

    // getCleaningPlan()

    bool verifyLogInData(std::string, int);
    bool verifyName(std::string);

    ~CommunityData();

    static CommunityData* getInstance();
};

#endif // COMMUNITYDATA_H
