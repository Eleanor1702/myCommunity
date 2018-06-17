#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <time.h>

class Event{

private:
    std::string description;
    std::string date;
    std::string time;
    std::string user;

public:
    Event();
    ~Event();

    void setDescription(std::string newDescription);
    void setUser(std::string newUser);
    void setTime(std::string newTime);
    void setDate(std::string newDate);
    void setDatetime(std::string datetime);
   /* void setTime(tm timedate);
    void setDay(tm timedate);
    void setMonth(tm timedate);
    void setYear(tm timedate);
    void setMin(tm timedate);
    void setHour(tm timedate);
    */

    /*tm getTime();
    int getDay();
    int getMonth();
    int getYear();
    int getMin();
    int getHour();
    */

    std::string getDescription();
    std::string getUser();
    std::string getTime();
    std::string getDate();
    std::string getDatetime();
};

#endif // EVENT_H