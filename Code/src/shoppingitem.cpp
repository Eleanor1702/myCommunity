#include "lib/shoppingitem.h"

Shoppingitem::Shoppingitem() {}
Shoppingitem::~Shoppingitem() {}

void Shoppingitem::setItemName(std::string name) {
    this->itemname = name;
}

void Shoppingitem::setNumber(std::string number) {
    this->number = number;
}

std::string Shoppingitem::getItemName() {
    return itemname;
}

std::string Shoppingitem::getNumber() {
    return number;
}
