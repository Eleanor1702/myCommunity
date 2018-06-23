#ifndef TASKEXPERT_H
#define TASKEXPERT_H

#include <vector>
#include <ctime>

#include "Task.h"
#include "concretetask.h"
#include "Database/lib/communitydata.h"

class TaskExpert{
private:
    static TaskExpert* instance;
   CommunityData* data;

protected:
    TaskExpert(CommunityData* data);

public:
    //Task methods
    void createTask(std::string name, std::string room, std::string frequency);
    void deleteTask(std::string name, std::string room);
    void editTask(std::string name, std::string frequency, std::string room);

    std::vector<std::string> taskNameGetter();
    std::vector<std::string> taskRoomGetter();
    std::vector<std::string> taskFrequencyGetter();
    std::vector<Task> getTasks();
    static TaskExpert* getInstance(CommunityData* data);


    //Concrete Task methods
    void createConcreteTask(std::string task, std::string resident, int cw, std::string room);
    void deleteConcreteTask(std::string task, std::string resident, int cw, std::string room);
    std::vector<ConcreteTask> concreteTaskGetter(int week);
    std::vector<std::string> concreteTaskNameGetter(int week);
    std::vector<std::string> concreteTaskRoomGetter(int week);
    std::vector<int> concreteTaskWeekGetter(int week);
    std::vector<std::string> concreteTaskResGetter(int week);

    //current CW methods
    int getCurrentCW();
};

#endif // TASKEXPERT_H
