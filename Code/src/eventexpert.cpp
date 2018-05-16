#include "lib/eventexpert.h"

EventExpert* EventExpert::instance = NULL;

EventExpert::EventExpert(){

}

void EventExpert::createEvent(string name, int time, int date, string user){

}

void EventExpert::deleteEvent(string name, int time, int date, string user){

}

void EventExpert::editEvent(string name, int time){

}

EventExpert* EventExpert::getInstance(){
    if(instance == NULL){
        instance = new EventExpert();
    }
    return instance;
}
