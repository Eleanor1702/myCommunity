#include <lib/event.h>

Event::Event() {}

void Event::setDescription(std::string newDescription){
    description = newDescription;
}

/*void Event::setTime(tm timedate){
    Event::setDay(timedate);
    Event::setMonth(timedate);
    Event::setYear(timedate);
    Event::setMin(timedate);
    Event::setHour(timedate);
}

void Event::setDay(tm timedate){
    time.tm_mday = timedate.tm_mday;
}

void Event::setMonth(tm timedate){
    time.tm_mon = timedate.tm_mon;
}

void Event::setYear(tm timedate){
    time.tm_year = timedate.tm_year;
}

void Event::setMin(tm timedate){
    time.tm_min = timedate.tm_min;
}

void Event::setHour(tm timedate){
   time.tm_hour = timedate.tm_hour;
}*/

void Event::setUser(std::string newUser){
    user = newUser;
}

void Event::setTime(std::string newTime){
    time = newTime;
}

void Event::setDate(std::string newDate){
    date = newDate;
}
/*
void Event::setDatetime(std::string datetime){
    char buffer[12];
    std::size_t length = datetime.copy(buffer,10,0); //date kopieren
    buffer[length]='\0';
    setDate(buffer);

    length = datetime.copy(buffer,8,10);
    buffer[length] = '\0';
    setTime(buffer);
}*/

std::string Event::getDescription(){
    return description;
}

/*
tm Event::getTime(){
    return time;
}

int Event::getDay(){
    return (int)time.tm_mday;
}

int Event::getMonth(){
    return time.tm_mon;
}

int Event::getYear(){
    return time.tm_year;
}

int Event::getMin(){
    return time.tm_year;
}

int Event::getHour(){
    return time.tm_hour;
}*/

std::string Event::getUser(){
    return user;
}

std::string Event::getTime(){
    return time;
}

std::string Event::getDate(){
    return date;
}
/*
std::string Event::getDatetime(){
    std::string datetime;
    datetime = getDate() + getTime();
    return datetime;
}*/

