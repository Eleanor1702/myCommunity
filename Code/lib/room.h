#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

class Room {
private:
    string name;
    string art;

public:
    Room();
    void setName(string eingabe);
    void setArt(string eingabe);
    string getName();
    string getArt();
    void nameAendern();

};

#endif // room
