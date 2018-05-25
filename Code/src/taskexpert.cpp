#include "lib/taskexpert.h"


TaskExpert* TaskExpert::instance = NULL;

TaskExpert::TaskExpert(){

}

void TaskExpert::createTask(string name,tm timedate, string user, string room, int frequency){
    Task ta;
    ta.Task::setName(name);
    ta.Task::setTime(timedate);
    ta.Task::setUser(user);
    ta.Task::setRoom(room);
    ta.Task::setFrequency(frequency);
    Tasklist.push_back(ta);
}

void TaskExpert::deleteTask(string name, tm timedate, string user){
    for(vector<Task>::iterator it = Tasklist.begin(); it != Tasklist.end(); ++it) {
        if((it)->getName() == name && (it)->getUser() == user
                && (it)->getDay() == timedate.tm_mday && (it)->getMonth() == timedate.tm_mon && (it)->getYear() == timedate.tm_year
                && (it)->getMin() == timedate.tm_min && (it)->getMin() == timedate.tm_min
                ) {
            Tasklist.erase(it);
        }
    }
}

void TaskExpert::editTask(string name, tm timedate, int frequency) {       //Nur Zeit und Häufigkeit sollen veränderbar sein
    for(vector<Task>::iterator it = Tasklist.begin(); it != Tasklist.end(); ++it) {
        if((it)->getName() == name) {
            (it)->setTime(timedate);
            (it)->setFrequency(frequency);
        }
    }
}

TaskExpert* TaskExpert::getInstance(){
    if(instance == NULL){
        instance = new TaskExpert();
    }
    return instance;
}
