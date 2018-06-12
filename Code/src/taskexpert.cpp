#include "lib/taskexpert.h"

TaskExpert* TaskExpert::instance = NULL;

TaskExpert::TaskExpert(CommunityData* data){
    this->data = data;
}


//create a new cleaning task
void TaskExpert::createTask(std::string taskname, std::string room, std::string frequency){
    Task ta;
    ta.setName(taskname);
    ta.setRoom(room);
    ta.setFrequency(frequency);
    data->addTask(ta);
}

//delete a task
void TaskExpert::deleteTask(std::string taskname, std::string room) {
    data->deleteTaskByName(taskname, room);
}

//edit a task


TaskExpert* TaskExpert::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new TaskExpert(data);
    }
    return instance;
}
