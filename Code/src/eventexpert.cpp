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

}

void EventExpert::editEvent(string description, tm timedate){

}

EventExpert* EventExpert::getInstance(){
    if(instance == NULL){
        instance = new EventExpert();
    }
    return instance;
}
