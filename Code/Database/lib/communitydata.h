#ifndef COMMUNITYDATA_H
#define COMMUNITYDATA_H

#include <vector>


#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>

#include "lib/Resident.h"
#include "lib/Room.h"
#include "lib/Event.h"
#include "lib/Task.h"
#include "lib/shoppingitem.h"
#include "lib/concretetask.h"

#include <string>


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
    //CurrentUser
    std::string getDbUser(std::string user);

    //Calendar
    void createCalendarTable();
    void addEvent(Event ev);
    void updateEvent(Event ev, std::string timedate,std::string description);
    void deleteEvent(Event ev);
    void deleteCalendar(std::string user);
 //   std::vector<Event> getAllEventsOfUser(std::string user, std::string datetime);
    std::vector<Event> getAllEvents(std::string user, std::string date);
    std::vector<std::string> getAllEventsString(std::string cuser, std::string datetime);
    std::vector<std::string> getAllDates(std::string user);


    //Cleaning plan
    void createCleaningTable();
    void addToCleaningplan(ConcreteTask ctask);
    void deleteConcreteTask(std::string task, std::string resident, int week, std::string room);
    void deleteTaskCleaningplan(std::string name, std::string room);
    void deleteResidentCleaningplan(std::string resident);
    void deleteRoomCleaningplan(std::string room);
    std::vector<ConcreteTask> getAllConcreteTasks(int week);
    std::vector<std::string> getAllConcreteTasksString(int week);

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
    std::vector<std::string> getAllItemsString();

};

#endif // COMMUNITYDATA_H
