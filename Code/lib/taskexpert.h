#ifndef TASKEXPERT_H
#define TASKEXPERT_H

#include <vector>
#include "Task.h"

class TaskExpert{
private:
    static TaskExpert* instance;
    std::vector<Task> Tasklist;

protected:
    TaskExpert();

public:

    void createTask(std::string name, tm timedate, std::string user, std::string room, int frequency);             // time und date als t_time
    void deleteTask(std::string name, tm timedate, std::string user);
    void editTask(std::string name, tm timedate, int frequency);       //nur die zeit darf verändert werden

    static TaskExpert* getInstance();
};

#endif // TASKEXPERT_H
