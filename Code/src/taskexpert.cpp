#include "lib/taskexpert.h"

TaskExpert* TaskExpert::instance = NULL;

TaskExpert* TaskExpert::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new TaskExpert(data);
    }
    return instance;
}

TaskExpert::TaskExpert(CommunityData* data){
    this->data = data;
}

TaskExpert::~TaskExpert() {
    instance = NULL;
}

//**************************************Tasks
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

//Getter Functions Task
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


//***************************ConcreteTasks

//get all concretTasks
std::vector<ConcreteTask> TaskExpert::concreteTaskGetter(int week){
    return data->getAllConcreteTasks(week);
}


void TaskExpert::createConcreteTask(std::string taskname, std::string resident, int cw, std::string room){
    ConcreteTask cTask;
    Task task;
    task.setName(taskname);
    task.setRoom(room);
    task.setFrequency("");
    cTask.setTask(task);
    cTask.setResident(resident);
    cTask.setCalendarweek(cw);
    data->addToCleaningplan(cTask);

}

void TaskExpert::deleteConcreteTask(std::string task, std::string resident, int cw, std::string room){
    data->deleteConcreteTask(task, resident, cw, room);
}

//Getter Functions concrete Task
std::vector<int> TaskExpert::concreteTaskWeekGetter(int week){
    std::vector<int> weekVector;
    std::vector<ConcreteTask> tasklist = concreteTaskGetter(week);
    for(unsigned int i = 0; i < tasklist.size(); i++) {
        weekVector.push_back((tasklist[i].getCalendarweek()));
    }
    return weekVector;
}

std::vector<std::string> TaskExpert::concreteTaskResGetter(int week){
    std::vector<std::string> residentVector;
    std::vector<ConcreteTask> tasklist = concreteTaskGetter(week);
    for(unsigned int i = 0; i < tasklist.size(); i++) {
        residentVector.push_back((tasklist[i].getResident()));
    }
    return residentVector;
}

std::vector<std::string> TaskExpert::concreteTaskNameGetter(int week){
    std::vector<std::string> nameVector;
    std::vector<ConcreteTask> tasklist = concreteTaskGetter(week);
    for(unsigned int i= 0; i<tasklist.size();i++){
        nameVector.push_back(tasklist[i].getTask().getName());
    }
    return nameVector;
}
std::vector<std::string> TaskExpert::concreteTaskRoomGetter(int week){
    std::vector<std::string> roomVector;
    std::vector<ConcreteTask> tasklist = concreteTaskGetter(week);
    for(unsigned int i= 0; i<tasklist.size();i++){
        roomVector.push_back(tasklist[i].getTask().getRoom());
    }
    return roomVector;
}


//Returns current calendarweek as int
int TaskExpert::getCurrentCW(){
    time_t the_time;
    time(&the_time);
    tm *t = localtime(&the_time);
    char week_string[3];
    strftime(week_string, 3, "%W", t);
    return atoi(week_string);
}
