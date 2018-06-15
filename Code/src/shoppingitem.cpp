#include "lib/shoppingitem.h"

Shoppingitem::Shoppingitem() {}
Shoppingitem::~Shoppingitem() {}

//set name of item
void Shoppingitem::setItemName(std::string name) {
    this->itemname = name;
}

//set number of item
void Shoppingitem::setNumber(std::string number) {
    this->number = number;
}

//get itemname
std::string Shoppingitem::getItemName() {
    return itemname;
}

//get itmenumber
std::string Shoppingitem::getNumber() {
    return number;
}
