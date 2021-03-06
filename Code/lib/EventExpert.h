#ifndef EVENTEXPERT_H
#define EVENTEXPERT_H

#include <vector>
#include "Event.h"
#include "Database/lib/communitydata.h"

class EventExpert{
private:
    friend class Controller;

    static EventExpert* instance;
    CommunityData* data;

protected:
    EventExpert(CommunityData* data);

public:
    void createEvent(std::string time, std::string date,
                     std::string description, std::string user);
    void deleteEvent(std::string time, std::string date,
                     std::string description, std::string user);
    void editEvent(std::string time, std::string date, std::string description, std::string user, std::string newtime, std::string newdate, std::string newdescription);

    std::vector<std::string> eventTimeGetter(std::string user, std::string date);
    std::vector<std::string> eventDateGetter(std::string user, std::string date);
    std::vector<std::string> eventDescriptionGetter(std::string user, std::string date);
    std::vector<std::string> eventUserGetter(std::string user, std::string date);
    unsigned int eventSizeGetter(std::string user, std::string date);
    std::vector<std::string> getAllDates(std::string user);

    static EventExpert* getInstance(CommunityData* data);

    ~EventExpert();
};

#endif // EVENTEXPERT_H
