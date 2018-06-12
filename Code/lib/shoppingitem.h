#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include <string>

class Shoppingitem {
private:
    std::string itemname;
    int number;

public:
    Shoppingitem();
    ~Shoppingitem();
    void setItemName(std::string name);
    void setNumber(int number);
    std::string getItemName();
    int getNumber();
};

#endif // SHOPPINGLIST_H
