#ifndef TASK_H
#define TASK_H

#include <string>
#include <time.h>

using namespace std;

class Task{

private:
    string name;
    tm time;
    string user;
    string room;
    int frequency;              //Wie oft muss die Aufgabe erledigt werden
                                //z.B. frequency = 4 -> Aufgabe muss 4 mal
                                //im Monat erledigt werden


public:
    Task();
    //~Task();

    void setName(string newName);
    void setDay(tm timedate);
    void setMonth(tm timedate);
    void setUser(string newUser);
    void setRoom(string newRoom);
    void setFrequency(int newFrequency);

    string getName();
    int getDay();
    int getMonth();
    string getUser();
    string getRoom();
    int getFrequency();


    //Methoden die nicht direkt gebraucht werden, da der Putzplan
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
