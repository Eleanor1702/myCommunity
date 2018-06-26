#include "lib/shoppingexpert.h"

ShoppingExpert* ShoppingExpert::instance = NULL;

//Singleton, so only one Instance can exist
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
void ShoppingExpert::createItem(std::string name, std::string number) {
    Shoppingitem si;
    si.setItemName(name);
    si.setNumber(number);
    data->addItem(si);
}

//delete an item
void ShoppingExpert::deleteItem(std::string name) {
    data->deleteShoppinglistItem(name);
}

//Getter Functions
//get all item names as strings
std::vector<std::string> ShoppingExpert::itemNameGetter() {
    std::vector<std::string> nameVector;
    std::vector<Shoppingitem> list = getItems();
    for(unsigned int i = 0; i< list.size(); i++) {
        nameVector.push_back(list[i].getItemName());
    }
    return nameVector;
}

//get all item numbers
std::vector<std::string> ShoppingExpert::itemNumberGetter() {
    std::vector<std::string> numberVector;
    std::vector<Shoppingitem> list = getItems();
    for(unsigned int i = 0; i< list.size(); i++) {
        numberVector.push_back(list[i].getNumber());
    }
    return numberVector;
}

//get all items as Shoppingitem types
std::vector<Shoppingitem> ShoppingExpert::getItems() {
    return data->getAllItems();
}

ShoppingExpert::~ShoppingExpert(){
    instance = NULL;
}
