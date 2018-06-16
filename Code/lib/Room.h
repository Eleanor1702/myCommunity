#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
private:
    std::string name;
    std::string art;

public:
    Room();
    ~Room();

    void setName(std::string eingabe);
    void setArt(std::string eingabe);

    std::string getName();
    std::string getArt();
};
#endif // room
