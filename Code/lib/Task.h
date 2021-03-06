#ifndef TASK_H
#define TASK_H

#include <string>

class Task{

private:
    std::string name;
    std::string room;
    std::string frequency;       //how often does the job have to be done

public:
    Task();
    ~Task();

    void setName(std::string newName);
    void setRoom(std::string newRoom);
    void setFrequency(std::string newFrequency);

    std::string getName();
    std::string getRoom();
    std::string getFrequency();
};

#endif // TASK_H
