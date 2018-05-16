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

    void createEvent(string name, int time, int date, string user);             // time und date als t_time
    void deleteEvent(string name, int time, int date, string user);
    void editEvent(string name, int time);

    static EventExpert* getInstance();
};

#endif // EVENTEXPERT_H
