#include "lib/taskexpert.h"

TaskExpert* TaskExpert::instance = NULL;

TaskExpert::TaskExpert(CommunityData data){
    this->data = data;
}

void TaskExpert::createTask(std::string name, std::string room, int frequency){
    Task ta;
    ta.Task::setName(name);
    ta.Task::setRoom(room);
    ta.Task::setFrequency(frequency);
    data->addTask(ta);
}


void TaskExpert::deleteTask(std::string name, std::string room, int frequency){
    Task ta;
    ta.Task::setName(name);
    ta.Task::setRoom(room);
    ta.Task::setFrequency(frequency);
    data->deleteTaskCleaningplan(ta);
}

void TaskExpert::editTask(std::string name, std::string room, int frequency) {       //Nur Zeit und Häufigkeit sollen veränderbar sein

}

TaskExpert* TaskExpert::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new TaskExpert(data);
    }
    return instance;
}
