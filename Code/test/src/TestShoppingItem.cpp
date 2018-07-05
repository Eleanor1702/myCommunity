#include "../lib/TestShoppingItem.h"

void TestShoppingItem::testItemName() {
  Shoppingitem testShoppingItem;

  testShoppingItem.setItemName("Milch");
  QVERIFY(testShoppingItem.getItemName() == "Milch");
}

void TestShoppingItem::testNumber() {
  Shoppingitem testShoppingItem;

  testShoppingItem.setNumber("2");
  QVERIFY(testShoppingItem.getNumber() == "2");
}
