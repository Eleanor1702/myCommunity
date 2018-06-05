#ifndef EVENTEXPERT_H
#define EVENTEXPERT_H

#include <vector>
#include "event.h"
#include "Database/lib/communitydata.h"

class EventExpert{
private:
    friend class Controller;

    static EventExpert* instance;
    std::vector<Event> Eventlist;
    CommunityData* data;

protected:
    EventExpert(CommunityData* data);

public:
    void createEvent(std::string time, std::string date,
                     std::string description, std::string user);             // time und date als t_time
    void deleteEvent(std::string time, std::string date,
                     std::string description, std::string user);
    void editEvent(std::string time, std::string date, std::string description, std::string user, std::string newtime, std::string newdate, std::string newdescription);

    std::vector<std::string> eventTimeGetter();
    std::vector<std::string> eventDateGetter();
    std::vector<std::string> eventDescriptionGetter();
    std::vector<std::string> eventUserGetter();
    std::vector<Event> getUserEvents(std::string user);
    std::vector<Event> getCommunityEvents();

    static EventExpert* getInstance(CommunityData* data);
};

#endif // EVENTEXPERT_H
