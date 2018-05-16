#include <lib/event.h>



void Event::setDescription(string newDescription){
    description = newDescription;
}

void Event::setTime(tm timedate){
    Event::setDay(timedate);
    Event::setMonth(timedate);
    Event::setYear(timedate);
    Event::setMin(timedate);
    Event::setHour(timedate);
}

void Event::setDay(tm timedate){
    time.tm_mday = timedate.tm_mday;
}

void Event::setMonth(tm timedate){
    time.tm_mon = timedate.tm_mon;
}

void Event::setYear(tm timedate){
    time.tm_year = timedate.tm_year;
}

void Event::setMin(tm timedate){
    time.tm_min = timedate.tm_min;
}

void Event::setHour(tm timedate){
   time.tm_hour = timedate.tm_hour;
}
