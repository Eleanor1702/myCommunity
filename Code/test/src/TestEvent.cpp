#include "../lib/TestEvent.h"

void TestEvent::testDescription() {
    Event testEvent;

    testEvent.setDescription("test Description");
    QVERIFY(testEvent.getDescription() == "test Description");
}

void TestEvent::testUser() {
    Event testEvent;

    testEvent.setUser("testUser");
    QVERIFY(testEvent.getUser() == "testUser");
}

void TestEvent::testTime() {
    Event testEvent;

    testEvent.setTime("17:00");
    QVERIFY(testEvent.getTime() == "17:00");
}

void TestEvent::testDate() {
    Event testEvent;

    testEvent.setDate("17.12.2018");
    QVERIFY(testEvent.getDate() == "17.12.2018");
}

void TestEvent::testDateTime() {
    Event testEvent;

    testEvent.setDatetime("171220181700");
    QVERIFY(testEvent.getDatetime() == "171220181700");
}
