#ifndef TASKEXPERT_H
#define TASKEXPERT_H

#include <vector>
#include "task.h"

class TaskExpert{
private:
    static TaskExpert* instance;
    std::vector<Task> Tasklist;

protected:
    TaskExpert();

public:

    void createTask(string name, tm timedate, string user, string room, int frequency);             // time und date als t_time
    void deleteTask(string name, tm timedate, string user);
    void editTask(string name, tm timedate, int frequency);       //nur die zeit darf verändert werden

    static TaskExpert* getInstance();
};


#endif // TASKEXPERT_H
