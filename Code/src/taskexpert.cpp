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

//get all tasks
std::vector<Task> TaskExpert::getTasks(){
    return data->getAllTasks();
}

//get all tasknames
std::vector<std::string> TaskExpert::taskNameGetter() {
    std::vector<std::string> nameVector;

    for(unsigned int i = 0; i < getTasks().size(); i++) {
        nameVector.push_back(getTasks()[i].getName());
    }
    return nameVector;
}

//get all taskrooms
std::vector<std::string> TaskExpert::taskRoomGetter() {
    std::vector<std::string> RoomVector;

    for(unsigned int i = 0; i < getTasks().size(); i++) {
        RoomVector.push_back(getTasks()[i].getRoom());
    }
    return RoomVector;
}

//get task frequency
std::vector<std::string> TaskExpert::taskFrequencyGetter() {
    std::vector<std::string> frequencyVector;

    for(unsigned int i = 0; i < getTasks().size(); i++) {
        frequencyVector.push_back(getTasks()[i].getFrequency());
    }
    return frequencyVector;
}
TaskExpert* TaskExpert::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new TaskExpert(data);
    }
    return instance;
}
