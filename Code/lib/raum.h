#ifndef RAUM
#define RAUM

#include <string>

using namespace std;

class Raum {
private:
    string name;
    string art;

public:
    Raum();
    void setName(string eingabe);
    void setArt(string eingabe);
    string getName();
    string getArt();
};

#endif // RAUM

