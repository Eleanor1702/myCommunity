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
    void setTask(Task task);
    void setResident(std::string resident);
    void setCalendarweek(int cw);
    Task getTask();
    std::string getResident();
    int getCalendarweek();
};

#endif // CONCRETETASK_H
