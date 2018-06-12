#include "lib/shoppingexpert.h"

ShoppingExpert* ShoppingExpert::instance = NULL;

ShoppingExpert* ShoppingExpert::getInstance(CommunityData *data) {
    if(instance == NULL){
        instance = new ShoppingExpert(data);
    }
    return instance;
}

ShoppingExpert::ShoppingExpert(CommunityData *data) {
    this->data = data;
}

//create a new shoppingitem
void ShoppingExpert::createItem(std::string name, int number) {
    Shoppingitem si;
    si.setItemName(name);
    si.setNumber(number);
    data->addItem(si);
}

//delete an item
void ShoppingExpert::deleteItem(std::string name) {
    data->deleteShoppinglistItem(name);
}

//get all item names as strings
std::vector<std::string> ShoppingExpert::itemNameGetter() {
    std::vector<std::string> nameVector;
    for(unsigned int i = 0; i< getItems().size(); i++) {
        nameVector.push_back(getItems()[i].getItemName());
    }
    return nameVector;
}

//get all item numbers
std::vector<int> ShoppingExpert::itemNumberGetter() {
    std::vector<int> numberVector;
    for(unsigned int i = 0; i< getItems().size(); i++) {
        numberVector.push_back(getItems()[i].getNumber());
    }
    return numberVector;
}

//get all items as Shoppingitem types
std::vector<Shoppingitem> ShoppingExpert::getItems() {
    return data->getAllItems();
}
