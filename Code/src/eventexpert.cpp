#include "lib/eventexpert.h"

EventExpert* EventExpert::instance = NULL;

EventExpert::EventExpert(){
    data = data->getInstance();
}

EventExpert* EventExpert::getInstance(){
    if(instance == NULL){
        instance = new EventExpert();
    }
    return instance;
}

//Funktion für String datetime
void EventExpert::createEvent(std::string description, std::string datetime, std::string user){
    Event ev;
    ev.Event::setDescription(description);
    ev.Event::setDatetime(datetime);
    ev.Event::setUser(user);
    Eventlist.push_back(ev);
    data->addEvent(ev);
}

/*void EventExpert::deleteEvent(string description, tm datetime, string user){
    for(vector<Event>::iterator it = Eventlist.begin(); it != Eventlist.end(); ++it) {
        if((it)->getDescription() == description && (it)->getUser() == user
                && (it)->getDay() == datetime.tm_mday && (it)->getMonth() == datetime.tm_mon && (it)->getYear() == datetime.tm_year
                && (it)->getMin() == datetime.tm_min && (it)->getMin() == datetime.tm_min
                ) {
            Eventlist.erase(it);
        }
    }
}
*/

//Funktion für String datetime
void EventExpert::deleteEvent(std::string description, std::string datetime, std::string user){
 char dbuffer[12];
 char tbuffer[12];

  std::size_t length = datetime.copy(dbuffer,10,0); //date kopieren
  dbuffer[length]='\0';

  length = datetime.copy(tbuffer,8,10);
  tbuffer[length] = '\0';
}

/*
void EventExpert::editEvent(string description, tm datetime){
    for(vector<Event>::iterator it = Eventlist.begin(); it != Eventlist.end(); ++it) {
>>>>>>> 02e06bb6ad3d5894727068382ee26c3e3720dd00
        if((it)->getDescription() == description) {
            (it)->setTime(datetime);
        }
    }
}
*/

//Funktion für string datetime
void EventExpert::editEvent(std::string description, std::string datetime){
     char tbuffer[12];
     std::size_t length = datetime.copy(tbuffer,8,10);
     tbuffer[length] = '\0';

     for(std::vector<Event>::iterator it = Eventlist.begin(); it != Eventlist.end(); ++it) {
        if((it)->getDescription() == description) {
            (it)->setTime(tbuffer);
        }
    }
}
