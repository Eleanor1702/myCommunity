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
    void setUser(std::string newUser);
    void setRoom(std::string newRoom);
    void setFrequency(int newFrequency);

    std::string getName();
    int getDay();
    int getMonth();
    std::string getUser();
    std::string getRoom();
    int getFrequency();

    //Methoden, die nicht direkt gebraucht werden, da der Putzplan
    //auf wöchentlicher Basis erstellt wird

    void setTime(tm timedate);
    void setYear(tm timedate);
    void setMin(tm timedate);
    void setHour(tm timedate);

    tm getTime();
    int getYear();
    int getMin();
    int getHour();
};

#endif // TASK_H
