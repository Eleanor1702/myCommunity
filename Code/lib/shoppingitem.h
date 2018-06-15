#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include <string>

class Shoppingitem {
private:
    std::string itemname;
    //int number;
    std::string number;

public:
    Shoppingitem();
    ~Shoppingitem();
    void setItemName(std::string name);
    //void setNumber(int number);
    void setNumber(std::string number);
    std::string getItemName();
    //int getNumber();
    std::string getNumber();
};

#endif // SHOPPINGLIST_H
