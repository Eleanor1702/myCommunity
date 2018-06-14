#ifndef TASKEXPERT_H
#define TASKEXPERT_H

#include <vector>

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
    void editTask(std::string name, std::string frequency, std::string room);       //was darf alles verändert werden?

    std::vector<std::string> taskNameGetter();
    std::vector<std::string> taskRoomGetter();
    std::vector<std::string> taskFrequencyGetter();
    std::vector<Task> getTasks();
    static TaskExpert* getInstance(CommunityData* data);


    //Concrete Task methods
    void createConcreteTask(Task task, std::string resident, int cw);
    void deleteConcreteTask(Task task, std::string resident, int cw);
    std::vector<ConcreteTask> getConcreteTasks();
    std::vector<ConcreteTask> showConcreteTasks(int cw, std::string user);



};

#endif // TASKEXPERT_H
