#include <lib/task.h>



Task::Task() {}

void Task::setName(string newName){
    name = newName;
}

void Task::setTime(tm timedate){
    Task::setDay(timedate);
    Task::setMonth(timedate);
    Task::setYear(timedate);
    Task::setMin(timedate);
    Task::setHour(timedate);
}

void Task::setDay(tm timedate){
    time.tm_mday = timedate.tm_mday;
}

void Task::setMonth(tm timedate){
    time.tm_mon = timedate.tm_mon;
}

void Task::setYear(tm timedate){
    time.tm_year = timedate.tm_year;
}

void Task::setMin(tm timedate){
    time.tm_min = timedate.tm_min;
}

void Task::setHour(tm timedate){
   time.tm_hour = timedate.tm_hour;
}

void Task::setUser(string newUser){
    user = newUser;
}

void Task::setRoom(string newRoom){
    room = newRoom;
}

void Task::setFrequency(int newFrequency){
    frequency = newFrequency;
}


string Task::getName(){
    return Name;
}

tm Task::getTime(){
    return time;
}


int Task::getDay(){
    return (int)time.tm_mday;
}

int Task::getMonth(){
    return time.tm_mon;
}

int Task::getYear(){
    return time.tm_year;
}

int Task::getMin(){
    return time.tm_year;
}

int Task::getHour(){
    return time.tm_hour;
}

string Task::getUser(){
    return user;
}

string Task::getRoom(){
    return room;
}

int Task::getFrequency(){
    return frequency;
}
