#include "lib/EventExpert.h"

EventExpert* EventExpert::instance = NULL;

EventExpert::EventExpert(CommunityData* data){
    this->data = data;
}

EventExpert* EventExpert::getInstance(CommunityData* data){
    if(instance == NULL){
        instance = new EventExpert(data);
    }
    return instance;
}

//Funktion für String datetime
void EventExpert::createEvent(std::string time, std::string date, std::string description, std::string user){
    Event ev;
    ev.Event::setDescription(description);
    ev.Event::setTime(time);
    ev.Event::setDate(date);
    ev.Event::setUser(user);
    data->addEvent(ev);
}

void EventExpert::deleteEvent(std::string time, std::string date, std::string description, std::string user){
            Event ev;
            ev.setDate(date);
            ev.setDescription(description);
            ev.setTime(time);
            ev.setUser(user);
            data->deleteEvent(ev);
}

void EventExpert::editEvent(std::string time, std::string date, std::string description, std::string user, std::string newtime, std::string newdate, std::string newdescription){
    Event ev;
    ev.setDate(date);
    ev.setTime(time);
    ev.setDescription(description);
    ev.setUser(user);
    data->updateEvent(ev, (newdate+newtime), newdescription);
}

unsigned int EventExpert::getEventSize(std::string user, std::string date){
    return (data->getAllEvents(user, date)).size();
}

std::vector<std::string>EventExpert::eventTimeGetter(std::string user, std::string date){
    std::vector<std::string> timeVec;
    std::vector<Event> Eventlist = data->getAllEvents(user, date);
    for(unsigned int i=0; i<Eventlist.size(); i++){
        timeVec.push_back(Eventlist[i].getTime());
    }
    return timeVec;
}

std::vector<std::string>EventExpert::eventDateGetter(std::string user, std::string date){
    std::vector<std::string> dateVec;
    std::vector<Event> Eventlist = data->getAllEvents(user, date);
    for(unsigned int i=0; i<Eventlist.size(); i++){
        dateVec.push_back(Eventlist[i].getDate());
    }
    return dateVec;
}

std::vector<std::string>EventExpert::eventDescriptionGetter(std::string user, std::string date){
    std::vector<std::string> descrVec;
    std::vector<Event> Eventlist = data->getAllEvents(user, date);
    for(unsigned int i=0; i<Eventlist.size(); i++){
        descrVec.push_back(Eventlist[i].getDescription());
    }
    return descrVec;
}

std::vector<std::string>EventExpert::eventUserGetter(std::string user, std::string date){
    std::vector<std::string> userVec;
    std::vector<Event> Eventlist = data->getAllEvents(user, date);
    for(unsigned int i=0; i<Eventlist.size(); i++){
        userVec.push_back(Eventlist[i].getUser());
    }
    return userVec;
}

std::vector<Event> EventExpert::getUserEvents(std::string user, std::string datetime) {
  return data->getAllEventsOfUser(user, datetime);
}

std::vector<Event> EventExpert::getCommunityEvents() {
  return data->getAllCommunityEvents();
}



