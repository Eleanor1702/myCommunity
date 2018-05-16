#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <time.h>

using namespace std;

class Event{

private:
    string description;
    tm time;
    string user;


public:
    Event();


    void setDescription(string newDescription);
    void setTime(int day, int month, int year, int min, int hour);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setMin(int min);
    void setHour(int hour);
    void setUser(string newUser);

    string getDescription();
    int getDay();
    int getMonth();
    int getYear();
    int getMin();
    int getHour();
    string getUser();

};





#endif // EVENT_H
