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
    void setTime(tm timedate);
    void setDay(tm timedate);
    void setMonth(tm timedate);
    void setYear(tm timedate);
    void setMin(tm timedate);
    void setHour(tm timedate);
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
