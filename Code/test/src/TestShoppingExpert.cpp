#include "../lib/TestShoppingExpert.h"

TestShoppingExpert::TestShoppingExpert(CommunityData *testData, TestDatabaseDeleter *destroyer) {
    this->testData = testData;
    this->destroyer = destroyer;
}

void TestShoppingExpert::testCreateItem() {
    destroyer->cleanShoppingList();

    ShoppingExpert* testShoppingExpert = ShoppingExpert::getInstance(testData);
    testShoppingExpert->createItem("Milch", "2");
    testShoppingExpert->createItem("Brot", "5");

    std::vector<Shoppingitem> items = testData->getAllItems();

    QVERIFY(items.size() == 2);
    QVERIFY(items.at(0).getItemName() == "Milch");
    QVERIFY(items.at(0).getNumber() == "2");
    QVERIFY(items.at(1).getItemName() == "Brot");
    QVERIFY(items.at(1).getNumber() == "5");
}

void TestShoppingExpert::testDeleteItem() {
    destroyer->cleanShoppingList();

    ShoppingExpert* testShoppingExpert = ShoppingExpert::getInstance(testData);
    testShoppingExpert->createItem("Milch", "2");
    testShoppingExpert->createItem("Brot", "5");

    testShoppingExpert->deleteItem("Milch");

    std::vector<Shoppingitem> items = testData->getAllItems();

    QVERIFY(items.size() == 1);
    QVERIFY(items.at(0).getItemName() == "Brot");
    QVERIFY(items.at(0).getNumber() == "5");
}

void TestShoppingExpert::testItemNameGetter() {
    destroyer->cleanShoppingList();

    ShoppingExpert* testShoppingExpert = ShoppingExpert::getInstance(testData);
    testShoppingExpert->createItem("Milch", "2");
    testShoppingExpert->createItem("Brot", "5");

    std::vector<std::string> items = testShoppingExpert->itemNameGetter();

    QVERIFY(items.size() == 2);
    QVERIFY(items.at(0) == "Milch");
    QVERIFY(items.at(1) == "Brot");
}

void TestShoppingExpert::testItemNumberGetter() {
    destroyer->cleanShoppingList();

    ShoppingExpert* testShoppingExpert = ShoppingExpert::getInstance(testData);
    testShoppingExpert->createItem("Milch", "2");
    testShoppingExpert->createItem("Brot", "5");

    std::vector<std::string> items = testShoppingExpert->itemNumberGetter();

    QVERIFY(items.size() == 2);
    QVERIFY(items.at(0) == "2");
    QVERIFY(items.at(1) == "5");
}

void TestShoppingExpert::testGetItems() {
    destroyer->cleanShoppingList();

    ShoppingExpert* testShoppingExpert = ShoppingExpert::getInstance(testData);
    testShoppingExpert->createItem("Milch", "2");
    testShoppingExpert->createItem("Brot", "5");

    std::vector<Shoppingitem> items = testShoppingExpert->getItems();

    QVERIFY(items.size() == 2);
    QVERIFY(items.at(0).getItemName() == "Milch");
    QVERIFY(items.at(0).getNumber() == "2");
    QVERIFY(items.at(1).getItemName() == "Brot");
    QVERIFY(items.at(1).getNumber() == "5");
}
