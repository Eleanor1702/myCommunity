#ifndef EVENTEXPERT_H
#define EVENTEXPERT_H

#include <vector>
#include "event.h"

class EventExpert{
private:
    static EventExpert* instance;
    std::vector<Event> Eventlist;

protected:
    EventExpert();

public:

    void createEvent(string description, tm timedate, string user);             // time und date als t_time
    void deleteEvent(string description, tm timedate, string user);
    void editEvent(string description, tm timedate);       //nur die zeit darf verändert werden

    static EventExpert* getInstance();
};

#endif // EVENTEXPERT_H
