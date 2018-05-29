#include "lib/eventexpert.h"


EventExpert* EventExpert::instance = NULL;

EventExpert::EventExpert(){

}

/*
 * void EventExpert::createEvent(string description,tm datetime, string user){
    Event ev;
    ev.Event::setDescription(description);
    ev.Event::setTime(datetime);
    ev.Event::setUser(user);
    Eventlist.push_back(ev);
}
*/
      //Funktion für String datetime
    void EventExpert::createEvent(string description, string datetime, string user){
    Event ev;
    ev.Event::setDescription(description);
    ev.Event::setDatetime(datetime);
    ev.Event::setUser(user);
    Eventlist.push_back(ev);
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
void EventExpert::deleteEvent(string description, string datetime, string user){
 char dbuffer[12];
 char tbuffer[12];

  std::size_t length = datetime.copy(dbuffer,10,0); //date kopieren
  dbuffer[length]='\0';

  length = datetime.copy(tbuffer,8,10);
  tbuffer[length] = '\0';

   for(vector<Event>::iterator it = Eventlist.begin(); it != Eventlist.end(); ++it) {
        if((it)->getDescription() == description && (it)->getUser() == user
                && (it)->getDate() == dbuffer &&
                (it)->getTime() == tbuffer) {
            Eventlist.erase(it);
        }
    }
}
/*
void EventExpert::editEvent(string description, tm datetime){
    for(vector<Event>::iterator it = Eventlist.begin(); it != Eventlist.end(); ++it) {
        if((it)->getDescription() == description) {
            (it)->setTime(datetime);
        }
    }
}
*/
          //Funktion für string datetime
void EventExpert::editEvent(string description, string datetime){
     char tbuffer[12];
     std::size_t length = datetime.copy(tbuffer,8,10);
     tbuffer[length] = '\0';

     for(vector<Event>::iterator it = Eventlist.begin(); it != Eventlist.end(); ++it) {
        if((it)->getDescription() == description) {
            (it)->setTime(tbuffer);
        }
    }
}


EventExpert* EventExpert::getInstance(){
    if(instance == NULL){
        instance = new EventExpert();
    }
    return instance;
}
