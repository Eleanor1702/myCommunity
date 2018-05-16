#include "lib/eventexpert.h"


EventExpert* EventExpert::instance = NULL;

EventExpert::EventExpert(){

}

void EventExpert::createEvent(string description,tm timedate, string user){
    Event ev;
    ev.Event::setDescription(description);
    ev.Event::setTime(timedate);
    ev.Event::setUser(user);
    Eventlist.push_back(ev);
}

void EventExpert::deleteEvent(string description, tm timedate, string user){
    for(vector<Event>::iterator it = Eventlist.begin(); it != Eventlist.end(); ++it) {
        if((it)->getDescription() == description && (it)->getUser() == user
                && (it)->getDay() == timedate.tm_mday && (it)->getMonth() == timedate.tm_mon && (it)->getYear() == timedate.tm_year
                && (it)->getMin() == timedate.tm_min && (it)->getMin() == timedate.tm_min
                ) {
            Eventlist.erase(it);
        }
    }
}

void EventExpert::editEvent(string description, tm timedate){
    for(vector<Event>::iterator it = Eventlist.begin(); it != Eventlist.end(); ++it) {
        if((it)->getDescription() == description) {
            (it)->setTime(timedate);
        }
    }
}

EventExpert* EventExpert::getInstance(){
    if(instance == NULL){
        instance = new EventExpert();
    }
    return instance;
}
