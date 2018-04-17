#ifndef RAUM
#define RAUM

#include <string>

using namespace std;

class Raum {
private:
    string name;
    string art;

public:
    void setName(string eingabe);
    void setArt(string eingabe);
    string getName();
    string getArt();
};

#endif // RAUM

