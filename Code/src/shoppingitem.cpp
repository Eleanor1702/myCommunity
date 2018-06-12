#include "lib/shoppingitem.h"

Shoppingitem::Shoppingitem() {}
Shoppingitem::~Shoppingitem() {}

void Shoppingitem::setItemName(std::string name) {
    this->itemname = name;
}

void Shoppingitem::setNumber(int number) {
    this->number = number;
}

std::string Shoppingitem::getItemName() {
    return itemname;
}

int Shoppingitem::getNumber() {
    return number;
}
