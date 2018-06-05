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
    Eventlist.push_back(ev);
    data->addEvent(ev);
}

void EventExpert::deleteEvent(std::string time, std::string date, std::string description, std::string user){
    for(std::vector<Event>::iterator it = Eventlist.begin(); it != Eventlist.end(); ++it){
        if((it->getDate()==date && it->getTime()==time && it->getDescription()==description && it->getUser()==user)){
            Event ev;
            ev.setDate(date);
            ev.setDescription(description);
            ev.setTime(time);
            ev.setUser(user);
            Eventlist.erase(it);
            data->deleteEvent(ev);
            break;
        }
    }
}

void EventExpert::editEvent(std::string time, std::string date, std::string description, std::string user, std::string newtime, std::string newdate, std::string newdescription){
    Event ev;
    ev.setDate(date);
    ev.setTime(time);
    ev.setDescription(description);
    ev.setUser(user);

    data->updateEvent(ev, (newdate+newtime), newdescription);
}

std::vector<std::string>EventExpert::eventTimeGetter(){
    std::vector<std::string> timeVec;
    for(unsigned int i=0; i<Eventlist.size(); i++){
        timeVec.push_back(Eventlist[i].getTime());
    }
    return timeVec;
}

std::vector<std::string>EventExpert::eventDateGetter(){
    std::vector<std::string> dateVec;
    for(unsigned int i=0; i<Eventlist.size(); i++){
        dateVec.push_back(Eventlist[i].getDate());
    }
    return dateVec;
}

std::vector<std::string>EventExpert::eventDescriptionGetter(){
    std::vector<std::string> descrVec;
    for(unsigned int i=0; i<Eventlist.size(); i++){
        descrVec.push_back(Eventlist[i].getDescription());
    }
    return descrVec;
}

std::vector<std::string>EventExpert::eventUserGetter(){
    std::vector<std::string> userVec;
    for(unsigned int i=0; i<Eventlist.size(); i++){
        userVec.push_back(Eventlist[i].getUser());
    }
    return userVec;
}

std::vector<Event> EventExpert::getUserEvents(std::string user) {
  return data->getAllEventsOfUser(user);
}

std::vector<Event> EventExpert::getCommunityEvents() {
  return data->getAllCommunityEvents();
}



