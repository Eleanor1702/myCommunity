#include "lib/eventexpert.h"

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
/*
//Funktion für String datetime
void EventExpert::deleteEvent(std::string time, std::string date, std::string description, std::string user){
 char dbuffer[12];
 char tbuffer[12];

  std::size_t length = date.copy(dbuffer,10,0); //date kopieren
  dbuffer[length]='\0';

  length = date.copy(tbuffer,8,10);
  tbuffer[length] = '\0';
}*/


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
/*
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
}*/

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



