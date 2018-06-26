#ifndef CONCRETETASK_H
#define CONCRETETASK_H

#include <string>
#include "lib/Task.h"

class ConcreteTask {
private:
    Task task;
    std::string resident;
    int cw; //Calendarweek
public:
    ConcreteTask();
    ~ConcreteTask();
    void setTask(Task newTask);
    void setResident(std::string newResident);
    void setCalendarweek(int newCw);
    Task getTask();
    std::string getResident();
    int getCalendarweek();
};

#endif // CONCRETETASK_H
