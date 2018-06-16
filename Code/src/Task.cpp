#include <lib/Task.h>

Task::Task() {}

Task::Task() {}

void Task::setName(std::string newName){
    name = newName;
}

void Task::setRoom(std::string newRoom){
    room = newRoom;
}

void Task::setFrequency(std::string newFrequency){
    frequency = newFrequency;
}

std::string Task::getName(){
    return name;
}

std::string Task::getRoom(){
    return room;
}

std::string Task::getFrequency(){
    return frequency;
}
