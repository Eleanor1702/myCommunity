#include "lib/concretetask.h"

ConcreteTask::ConcreteTask()
{

}
//set Task
void ConcreteTask::setTask(Task newTask){
    this->task = newTask;
}

//set resident
void ConcreteTask::setResident(std::string newResident) {
    this->resident = newResident;
}

//set calendar week
void ConcreteTask::setCalendarweek(int newCw){
    this->cw = newCw;
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
