#include <lib/event.h>

Event::Event() {}

void Event::setDescription(std::string newDescription){
    description = newDescription;
}


void Event::setUser(std::string newUser){
    user = newUser;
}

void Event::setTime(std::string newTime){
    time = newTime;
}

void Event::setDate(std::string newDate){
    date = newDate;
}

void Event::setDatetime(std::string datetime){
    char buffer[12];
    std::size_t length = datetime.copy(buffer,10,0); //date kopieren
    buffer[length]='\0';
    setDate(buffer);

    length = datetime.copy(buffer,6,10);
    buffer[length] = '\0';
    setTime(buffer);
}

std::string Event::getDescription(){
    return description;
}


std::string Event::getUser(){
    return user;
}

std::string Event::getTime(){
    return time;
}

std::string Event::getDate(){
    return date;
}

std::string Event::getDatetime(){
    std::string datetime;
    datetime = getDate() + getTime();
    return datetime;
}

