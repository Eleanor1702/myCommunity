#ifndef SHOPPINGEXPERT_H
#define SHOPPINGEXPERT_H

#include <vector>
#include "shoppingitem.h"
#include "Database/lib/communitydata.h"

class ShoppingExpert {
private:
    static ShoppingExpert* instance;

    CommunityData* data;

protected:
    ShoppingExpert(CommunityData* data);

public:
    void createItem(std::string itemname, std::string number);
    void deleteItem(std::string);

    std::vector<std::string> itemNameGetter();
    std::vector<std::string> itemNumberGetter();

    std::vector<Shoppingitem> getItems();

    static ShoppingExpert* getInstance(CommunityData* data);
};

#endif // SHOPPINGEXPERT_H
