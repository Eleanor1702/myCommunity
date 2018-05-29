#ifndef COMMUNITYDATA_H
#define COMMUNITYDATA_H

#include <vector>
#include <string>
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
    void createShoppinglistTable();

    void addResident(string name, int password);
    void addRoom(string name, string type);
    void addEvent(string timedate, string description, string user);
    void addTask(string taskname, string room, string frequency);
    void addToCleaningplan(string task, string resident, string week);

    void updatePassword(string user, int password);
    void updateEvent(Event ev, string timedate,string description);

    void deleteResident(string name);
    void deleteRoom(string name);
    void deleteEvent(string timedate, string description, string user);
    void deleteTaskByName(string taskname);
    void deleteTaskByRoom(string room);
    void deleteCalendar(string user);
    void deleteTaskCleaningplan(string task);
    void deleteResidentCleaningplan(string resident);
    void deleteRoomCleaningplan(string room);

    vector<Resident> getAllResidents();
    vector<Room> getAllRooms();
    vector<Event> getAllEventsOfUser(string user);
    vector<Event> getAllCommunityEvents();
    vector<Task> getAllTasks();
    // getCleaningPlan()

    bool verifyLogInData(string, int);
    bool verifyName(string);
    ~CommunityData();

    static CommunityData* getInstance();

};

#endif // COMMUNITYDATA_H
