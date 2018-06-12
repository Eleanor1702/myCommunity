#ifndef TASKEXPERT_H
#define TASKEXPERT_H

#include <vector>
#include "Task.h"
#include "Database/lib/communitydata.h"

class TaskExpert{
private:
    static TaskExpert* instance;
   // std::vector<Task> Tasklist;
   CommunityData* data;

protected:
    TaskExpert(CommunityData* data);

public:

    void createTask(std::string name, std::string room, std::string frequency);
    void deleteTask(std::string name, std::string room);
    void editTask(std::string name, std::string frequency, std::string room);       //was darf alles verändert werden?

    std::vector<std::string> taskNameGetter();
    std::vector<std::string> taskRoomGetter();
    std::vector<std::string> taskFrequencyGetter();
    std::vector<Task> getTasks();
    static TaskExpert* getInstance(CommunityData* data);
};

#endif // TASKEXPERT_H
