#include "../lib/TestRoom.h"

void TestRoom::testArt() {
  Room testRoom;

  testRoom.setArt("Bath");
  QVERIFY(testRoom.getArt() == "Bath");
}

void TestRoom::testName() {
  Room testRoom;

  testRoom.setName("test");
  QVERIFY(testRoom.getName() == "test");
}
