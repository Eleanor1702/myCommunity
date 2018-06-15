#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include <string>

class Shoppingitem {
private:
    std::string itemname;
    std::string number;

public:
    Shoppingitem();
    ~Shoppingitem();
    void setItemName(std::string name);
    void setNumber(std::string number);
    std::string getItemName();
    std::string getNumber();
};

#endif // SHOPPINGLIST_H
