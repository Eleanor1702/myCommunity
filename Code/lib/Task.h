#ifndef TASK_H
#define TASK_H

#include <string>

class Task{

private:
    std::string name;
    std::string room;
    std::string frequency;              //Wie oft muss die Aufgabe erledigt werden
                                //z.B. frequency = 4 -> Aufgabe muss 4 mal
                                //im Monat erledigt werden


public:
    Task();
    //~Task();

    void setName(std::string newName);
    void setRoom(std::string newRoom);
    void setFrequency(std::string newFrequency);

    std::string getName();
    std::string getRoom();
    std::string getFrequency();
};

#endif // TASK_H
