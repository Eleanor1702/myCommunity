#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <time.h>

using namespace std;

class Event{

private:
    string description;
    //tm time;
    string date;
    string time;
    string user;


public:
    Event();
    //~Event();

    void setDescription(string newDescription);
   /* void setTime(tm timedate);
    void setDay(tm timedate);
    void setMonth(tm timedate);
    void setYear(tm timedate);
    void setMin(tm timedate);
    void setHour(tm timedate);
*/
    void setUser(string newUser);

    void setTime(string time);
    void setDate(string date);
    void setDatetime(string datetime);



    string getDescription();
    /*tm getTime();
    int getDay();
    int getMonth();
    int getYear();
    int getMin();
    int getHour();
*/
    string getUser();

    string getTime();
    string getDate();



};





#endif // EVENT_H
