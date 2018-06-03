#ifndef TASK_H
#define TASK_H

#include <string>
#include <time.h>

class Task{

private:
    std::string name;
    tm time;
    std::string user;
    std::string room;
    int frequency;              //Wie oft muss die Aufgabe erledigt werden
                                //z.B. frequency = 4 -> Aufgabe muss 4 mal
                                //im Monat erledigt werden


public:
    Task();
    //~Task();

    void setName(std::string newName);
    void setDay(tm timedate);
    void setMonth(tm timedate);
    void setYear(tm timedate);
    void setHour(tm timedate);
    void setMin(tm timedate);
    void setTime(tm timedate);

    void setUser(std::string newUser);
    void setRoom(std::string newRoom);
    void setFrequency(int newFrequency);

    std::string getName();
    int getDay();
    int getMonth();
    int getYear();
    int getHour();
    int getMin();
    tm getTime();

    std::string getUser();
    std::string getRoom();
    int getFrequency();
};

#endif // TASK_H
