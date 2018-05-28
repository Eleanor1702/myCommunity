#ifndef EVENTEXPERT_H
#define EVENTEXPERT_H

#include <vector>
#include "event.h"
#include "Database/lib/communitydata.h"

class EventExpert{
private:
    static EventExpert* instance;
    std::vector<Event> Eventlist;

protected:
    EventExpert();

public:

    void createEvent(std::string description, tm timedate, std::string user);             // time und date als t_time
    void deleteEvent(std::string description, tm timedate, std::string user);
    void editEvent(std::string description, tm timedate);       //nur die zeit darf verändert werden

    static EventExpert* getInstance();
};

#endif // EVENTEXPERT_H
