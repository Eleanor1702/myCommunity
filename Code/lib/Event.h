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


    std::string getDescription();
    std::string getUser();
    std::string getTime();
    std::string getDate();
    std::string getDatetime();
};

#endif // EVENT_H
