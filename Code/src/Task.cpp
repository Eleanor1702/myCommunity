#include <lib/Task.h>

Task::Task() {}

void Task::setName(std::string newName){
    name = newName;
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

void Task::setHour(tm timedate){
   time.tm_hour = timedate.tm_hour;
}

void Task::setMin(tm timedate){
    time.tm_min = timedate.tm_min;
}

void Task::setTime(tm timedate){
    setDay(timedate);
    setMonth(timedate);
    setYear(timedate);
    setHour(timedate);
    setMin(timedate);
}

void Task::setUser(std::string newUser){
    user = newUser;
}

void Task::setRoom(std::string newRoom){
    room = newRoom;
}

void Task::setFrequency(int newFrequency){
    frequency = newFrequency;
}

std::string Task::getName(){
    return name;
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

int Task::getHour(){
    return time.tm_hour;
}

int Task::getMin(){
    return time.tm_year;
}

tm Task::getTime(){
    return time;
}

std::string Task::getUser(){
    return user;
}

std::string Task::getRoom(){
    return room;
}

int Task::getFrequency(){
    return frequency;
}
