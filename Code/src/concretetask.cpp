#include "lib/concretetask.h"

ConcreteTask::ConcreteTask()
{

}
//set Task
void ConcreteTask::setTask(Task task){
    this->task = task;
}

//set resident
void ConcreteTask::setResident(std::string resident) {
    this->resident = resident;
}

//set calendar week
void ConcreteTask::setCalendarweek(int cw){
    this->cw = cw;
}

//get task
Task ConcreteTask::getTask(){
    return task;
}

//get resident
std::string ConcreteTask::getResident() {
    return resident;
}

//get calendar week
int ConcreteTask::getCalendarweek(){
    return cw;
}
