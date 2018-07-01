#include "Database/lib/communitydata.h"
#include <QDebug>
#include <iostream>

CommunityData* CommunityData::instance = NULL;

//return an instance of community data and assure that only one instance exists
CommunityData* CommunityData::getInstance(std::string user, std::string password, std::string host, std::string database) {
   if(instance == NULL) {
       instance = new CommunityData(user, password, host, database);
   }
   return instance;
}

bool CommunityData::connect(std::string user, std::string password, std::string host, std::string database) {
    mysql = mysql_init(NULL);

    if(mysql_errno(mysql) != 0){
        return false;
    }

    mysql_real_connect(mysql, host.c_str(), user.c_str(), password.c_str(), database.c_str(), 3306, NULL, 0);

    if(mysql_errno(mysql) != 0){
        qDebug() << mysql_error(mysql);
        return false;
    }
    return true;
}

//Destructor
CommunityData::~CommunityData() {}

//Constructor
CommunityData::CommunityData(std::string user, std::string password, std::string host, std::string database) {
    if(!connect(user, password, host, database)) {
        std::cout <<"Connection failed!" << std::endl;
    }
    createRoomTable();
    createResidentTable();
    createCalendarTable();
    createCleaningTable();
    createTaskTable();
    createShoppinglistTable();
}

//****Rooms****

//Table for all Rooms
void CommunityData::createRoomTable() {
    std::string stmt = "CREATE TABLE IF NOT EXISTS Rooms(Name VARCHAR(50) PRIMARY KEY, Type VARCHAR(20))";

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//add a new room identified by a room type and a name
void CommunityData::addRoom(Room ro) {
    std::string stmt = "INSERT INTO Rooms(Name, Type) VALUES('";
    stmt.append(ro.getName());
    stmt.append("', '");
    stmt.append(ro.getArt());
    stmt.append("')");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//delete a room
void CommunityData::deleteRoom(std::string name) {
    std::string stmt = "DELETE FROM Rooms WHERE Name = '";
    stmt.append(name);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

    deleteAllTaskOfRoom(name);                                      //delete tasks
    deleteRoomCleaningplan(name);                                   //and update cleaningplan
}

//get all rooms from database
std::vector<Room> CommunityData::getAllRooms() {
    std::vector<Room> list;
    std::string stmt = "SELECT * FROM Rooms";

    MYSQL_RES* result;
    MYSQL_ROW row;
    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

    result = mysql_store_result(mysql);

    while((row = mysql_fetch_row(result)) != NULL){
        Room newRoom;
        mysql_field_seek(result, 0);
        newRoom.setName(std::string(row[0]));
        newRoom.setArt(std::string(row[1]));
        list.push_back(newRoom);
    }

    return list;
}

//****Residents****

//Table for all Residents
void CommunityData::createResidentTable() {
    std::string stmt = "CREATE TABLE IF NOT EXISTS Residents(Firstname VARCHAR(50) PRIMARY KEY, Password INT)";

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//insert a new resident identified by his name and his password
void CommunityData::addResident(Resident re) {
    std::string stmt = "INSERT INTO Residents(Firstname, Password) VALUES('";
    stmt.append(re.getFirstname());
    stmt.append("', ");
    stmt.append(std::to_string(re.getPassword()));
    stmt.append(")");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//set a new password for a resident
void CommunityData::updatePassword(std::string username, int newPassword) {
    std::string stmt = "UPDATE Residents SET Password = ";
    stmt.append(std::to_string(newPassword));
    stmt.append(" WHERE Firstname = '");
    stmt.append(username);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//delete a resident
void CommunityData::deleteResident(std::string name) {
    std::string stmt = "DELETE FROM Residents WHERE Firstname = '";
    stmt.append(name);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

    deleteCalendar(name);                                               //delete calendar of deleted resident
    deleteResidentCleaningplan(name);                                   //delete his cleaning tasks
}

//get all residents from database
std::vector<std::string> CommunityData::getAllResidents() {
    std::vector<std::string> list;
    std::string stmt = "SELECT * FROM Residents";

    MYSQL_RES* result;
    MYSQL_ROW row;
    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

    result = mysql_store_result(mysql);

    while((row = mysql_fetch_row(result)) != NULL){
        mysql_field_seek(result, 0);
        list.push_back(std::string(row[0]));
    }

    return list;
}

//verifying the log in data by username and password
 bool CommunityData::verifyLogInData(std::string username, int password) {
     std::string stmt = "SELECT * FROM Residents WHERE Firstname = '";
     stmt.append(username);
     stmt.append("' AND Password = ");
     stmt.append(std::to_string(password));

     MYSQL_RES* result;
     mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

     result = mysql_store_result(mysql);

     unsigned long rows = (unsigned long) mysql_num_rows(result);

     if(rows >= 1) {
        return true;
     }else{
        return false;
     }
}

//verify if resident with this name exists
bool CommunityData::verifyName(std::string username) {
     std::string stmt = "SELECT * FROM Residents WHERE Firstname = '";
     stmt.append(username);
     stmt.append("'");

     MYSQL_RES* result;
     mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

     result = mysql_store_result(mysql);

     unsigned long rows = (unsigned long) mysql_num_rows(result);

     if(rows >= 1) {
        return true;
     }else{
        return false;
     }
}

//Get Username from database (username is not case sensitive)
std::string CommunityData::getDbUser(std::string user){
     std::string currUser;
     std::string stmt = "SELECT * FROM Residents WHERE Firstname = '";
     stmt.append(user);
     stmt.append("'");

     MYSQL_RES* result;
     MYSQL_ROW row;
     mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

     result = mysql_store_result(mysql);

     //check if user exist
     unsigned long rows = (unsigned long) mysql_num_rows(result);

     if(rows == 0) {
        return "Fehler";
     }

     row = mysql_fetch_row(result);
     mysql_field_seek(result, 0);

     currUser = std::string(row[0]);

     return currUser;
}

//****Calendar****

//Table for Calendar
void CommunityData::createCalendarTable() {
    std::string stmt = "CREATE TABLE IF NOT EXISTS Calendar (Datetime DATETIME, Event VARCHAR(50), User VARCHAR(50))";

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//add a new calendar event for a user
void CommunityData::addEvent(Event ev) {
    std::string stmt = "INSERT INTO Calendar(Datetime, Event, User) VALUES('";
    stmt.append(ev.getDatetime());
    stmt.append("', '");
    stmt.append(ev.getDescription());
    stmt.append("', '");
    stmt.append(ev.getUser());
    stmt.append("')");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//change time or description of an event
void CommunityData::updateEvent(Event ev, std::string newtimedate, std::string newdescription) {
    std::string stmt = "UPDATE Calendar SET Datetime = '";
    stmt.append(newtimedate);
    stmt.append("', SET Description ='");
    stmt.append(newdescription);
    stmt.append("' WHERE Datetime = '");
    stmt.append(ev.getTime());
    stmt.append("' AND EVENT = '");
    stmt.append(ev.getDescription());
    stmt.append("' AND User = '");
    stmt.append(ev.getUser());
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//delete a calendar event
void CommunityData::deleteEvent(Event ev) {
    std::string stmt = "DELETE FROM Calendar WHERE Datetime = '";
    stmt.append(ev.getDatetime());
    stmt.append("' AND Event = '");
    stmt.append(ev.getDescription());
    stmt.append("' AND User = '");
    stmt.append(ev.getUser());
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//delete the whole calendar of an user
void CommunityData::deleteCalendar(std::string user) {
    std::string stmt = "DELETE FROM Calendar WHERE User = '";
    stmt.append(user);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//get all Events
std::vector<Event> CommunityData::getAllEvents(std::string user, std::string date){
    std::vector<Event> list;
    std::string stmt = "SELECT * FROM Calendar WHERE User = '";
    stmt.append(user);
    stmt.append("' AND DATE(Datetime) = '");
    stmt.append(date);
    stmt.append("' ORDER BY Datetime");

    MYSQL_RES* result;
    MYSQL_ROW row;
    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

    result = mysql_store_result(mysql);

    while((row = mysql_fetch_row(result)) != NULL){
        Event newEvent;
        mysql_field_seek(result, 0);
        newEvent.setDatetime(row[0]);
        newEvent.setDescription(row[1]);
        newEvent.setUser(row[2]);
        list.push_back(newEvent);
    }

    return list;
}

std::vector<std::string> CommunityData::getAllEventsString(std::string cuser, std::string datetime){
    std::vector<std::string> stringlist;
    std::string name;
    std::string user;
    std::string date;
    std::string time;
    std::string info;                                               //name, user, datetime

    std::vector<Event> list = this->getAllEvents(cuser, datetime);

    for(std::vector<Event>::iterator it = list.begin(); it != list.end(); it++){
        name = it->getDescription();
        user = it->getUser();
        date = it->getDate();
        time = it->getTime();
        info = name + "," + user + "," + date + "," + time + "\n";
        stringlist.push_back(info);
     }
    return stringlist;
}

//gets All Dates
std::vector<std::string> CommunityData::getAllDates(std::string user){
    std::vector<std::string> list;
    std::string stmt = "SELECT CONVERT(Datetime, Date) AS Datetime FROM Calendar WHERE User = '";
    stmt.append(user);
    stmt.append("' OR User = 'gemeinschaftlich' ORDER BY Datetime");

    MYSQL_RES* result;
    MYSQL_ROW row;
    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

    result = mysql_store_result(mysql);

    while((row = mysql_fetch_row(result)) != NULL){
        mysql_field_seek(result, 0);
        list.push_back(std::string(row[0]));
    }

    return list;
}

//*****Cleaningplan*****

//Table to store cleaning plan
void CommunityData::createCleaningTable(){
    std::string stmt = "CREATE TABLE IF NOT EXISTS Cleaning (Task VARCHAR(50), CRoom VARCHAR(50), Resident VARCHAR(50), Week INT)";

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

void CommunityData::addToCleaningplan(ConcreteTask ctask){
    std::string stmt = "INSERT INTO Cleaning(Task, CRoom, Resident, Week) VALUES('";
    stmt.append(ctask.getTask().getName());
    stmt.append("', '");
    stmt.append(ctask.getTask().getRoom());
    stmt.append("', '");
    stmt.append(ctask.getResident());
    stmt.append("', ");
    stmt.append(std::to_string(ctask.getCalendarweek()));
    stmt.append(")");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//delete a concrete task
void CommunityData::deleteConcreteTask(std::string task, std::string resident, int week, std::string room){
    std::string stmt = "DELETE FROM Cleaning WHERE Task = '";
    stmt.append(task);
    stmt.append("' AND Resident = '");
    stmt.append(resident);
    stmt.append("' AND Week = ");
    stmt.append(std::to_string(week));
    stmt.append(" AND CRoom = '");
    stmt.append(room);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//update cleaningplan by resident
void CommunityData::deleteResidentCleaningplan(std::string resident){
    std::string stmt = "DELETE FROM Cleaning WHERE Resident = '";
    stmt.append(resident);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//update cleaningplan by room
void CommunityData::deleteRoomCleaningplan(std::string room){
    std::string stmt = "DELETE FROM Cleaning WHERE CRoom = '";
    stmt.append(room);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//update cleaningplan by task
void CommunityData::deleteTaskCleaningplan(std::string name, std::string room) {
    std::string stmt = "DELETE FROM Cleaning WHERE Task = '";
    stmt.append(name);
    stmt.append("' AND CRoom = '");
    stmt.append(room);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

std::vector<ConcreteTask> CommunityData::getAllConcreteTasks(int week) {
    std::vector<ConcreteTask> list;
    std::string stmt = "SELECT * FROM Cleaning JOIN Tasks ON Week >= ";
    stmt.append(std::to_string(week));
    stmt.append(" AND Tasks.Name = Cleaning.Task AND Tasks.Room = Cleaning.CRoom ORDER BY Resident");

    MYSQL_RES* result;
    MYSQL_ROW row;
    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

    result = mysql_store_result(mysql);

    while((row = mysql_fetch_row(result)) != NULL){
        ConcreteTask cNewTask;
        Task newTask;
        mysql_field_seek(result, 0);
        newTask.setName(std::string(row[0]));
        newTask.setRoom(std::string(row[3]));
        newTask.setFrequency(std::string(row[5]));
        cNewTask.setResident(std::string(row[1]));
        cNewTask.setCalendarweek(std::stoi(std::string(row[2])));
        cNewTask.setTask(newTask);
        list.push_back(cNewTask);
    }

    return list;
}

std::vector<std::string> CommunityData::getAllConcreteTasksString(int week){
    std::vector<std::string> stringlist;
    std::string taskname;
    std::string resident;
    std::string cw;                                                         //CalendarWeek
    std::string info;                                                       //taskname, resident, cw

    std::vector<ConcreteTask> list = this->getAllConcreteTasks(week);

    for(std::vector<ConcreteTask>::iterator it = list.begin(); it != list.end(); it++)    {
        taskname = it->getTask().getName();
        resident = it->getResident();
        cw = std::to_string(it->getCalendarweek());

        info = taskname + "," + resident + "," + cw + "\n";

        stringlist.push_back(info);
     }

    return stringlist;
}

//****Tasks*****

//Table to store cleaning Tasks
void CommunityData::createTaskTable(){
    std::string stmt = "CREATE TABLE IF NOT EXISTS Tasks (Name VARCHAR(50), Room VARCHAR(50), Frequency VARCHAR(50))";

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//add a new cleaning task
void CommunityData::addTask(Task ta){
    std::string stmt = "INSERT INTO Tasks(Name, Room, Frequency) VALUES('";
    stmt.append(ta.getName());
    stmt.append("', '");
    stmt.append(ta.getRoom());
    stmt.append("', '");
    stmt.append(ta.getFrequency());
    stmt.append("')");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//delete a cleaning task from database
void CommunityData::deleteTaskByName(std::string taskname, std::string room){
    std::string stmt = "DELETE FROM Tasks WHERE Name = '";
    stmt.append(taskname);
    stmt.append("' AND Room = '");
    stmt.append(room);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

    //update cleaning plan
    deleteTaskCleaningplan(taskname, room);
}

//delete all tasks of a room
void CommunityData::deleteAllTaskOfRoom(std::string room){
    std::string stmt = "DELETE FROM Tasks WHERE Room = '";
    stmt.append(room);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//get all tasks
std::vector<Task> CommunityData::getAllTasks(){
    std::vector<Task> list;
    std::string stmt = "SELECT * FROM Tasks";

    MYSQL_RES* result;
    MYSQL_ROW row;
    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

    result = mysql_store_result(mysql);

    while((row = mysql_fetch_row(result)) != NULL){
        Task newTask;
        mysql_field_seek(result, 0);
        newTask.setRoom(row[0]);
        newTask.setFrequency(row[1]);
        newTask.setName(row[2]);
        list.push_back(newTask);
    }

    return list;
}

//*****Shoppinglist****

//create Table for Shopping list
void CommunityData::createShoppinglistTable(){
    std::string stmt = "CREATE TABLE IF NOT EXISTS ShoppingList (Item VARCHAR(50), Number VARCHAR(20))";

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//add Shoppinglist item
void CommunityData::addItem(Shoppingitem si) {
    std::string stmt = "INSERT INTO ShoppingList(Item, Number) VALUES('";
    stmt.append(si.getItemName());
    stmt.append("', '");
    stmt.append(si.getNumber());
    stmt.append("')");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//delete an item from shoppinglist
void CommunityData::deleteShoppinglistItem(std::string item) {
    std::string stmt = "DELETE FROM ShoppingList WHERE Item = '";
    stmt.append(item);
    stmt.append("'");

    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));
}

//get all shoppinglist items
std::vector<Shoppingitem> CommunityData::getAllItems() {
    std::vector<Shoppingitem> list;
    std::string stmt = "SELECT * FROM ShoppingList";

    MYSQL_RES* result;
    MYSQL_ROW row;
    mysql_real_query(mysql, stmt.c_str(), strlen(stmt.c_str()));

    result = mysql_store_result(mysql);

    while((row = mysql_fetch_row(result)) != NULL){
        Shoppingitem newItem;
        mysql_field_seek(result, 0);
        newItem.setItemName(std::string(row[0]));
        newItem.setNumber(std::string(row[1]));
        list.push_back(newItem);
    }

    return list;
}

//get ShopingList as String
std::vector<std::string> CommunityData::getAllItemsString(){
    std::vector<std::string> stringlist;
    std::string amount;
    std::string name;
    std::string info;                                               //amaount, name

    std::vector<Shoppingitem> list = this->getAllItems();

    for(std::vector<Shoppingitem>::iterator it = list.begin(); it != list.end(); it++) {
        amount = it->getNumber();
        name = it->getItemName();
        info = amount + "," + name + "\n";
        stringlist.push_back(info);
     }

    return stringlist;
}
