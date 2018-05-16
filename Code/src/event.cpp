#include <lib/event.h>



void Event::setDescription(string newDescription){
    description = newDescription;
}

void Event::setTime(int day, int month, int year, int min, int hour){
    Event::setDay(day);
    Event::setMonth(month);
    Event::setYear(year);
    Event::setMin(min);
    Event::setHour(hour);
}

void Event::setDay(int day){
    time.tm_mday = day;
}

void Event::setMonth(int month){
    time.tm_mon = month;
}

void Event::setYear(int year){
    time.tm_year = year;
}

void Event::setMin(int min){
    time.tm_min = min;
}

void Event::setHour(int hour){
   time.tm_hour = hour;
}
