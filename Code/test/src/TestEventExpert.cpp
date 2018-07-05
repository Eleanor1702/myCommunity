#include "../lib/TestEventExpert.h"
#include <iostream>

TestEventExpert::TestEventExpert(CommunityData *testData, TestDatabaseDeleter *destroyer) {
    this->testData = testData;
    this->destroyer = destroyer;
}

void TestEventExpert::testCreateEvent() {
    destroyer->cleanEvents();
    EventExpert* testEventExpert = EventExpert::getInstance(testData);

    testEventExpert->createEvent(" 10:00", "2018-01-01", "Test-Event", "Test-User");
    Event testEvent = testData->getAllEvents("Test-User", "2018-01-01").at(0);

    QVERIFY(testEvent.getTime() == " 10:00");
    QVERIFY(testEvent.getDate() == "2018-01-01");
    QVERIFY(testEvent.getDescription() == "Test-Event");
    QVERIFY(testEvent.getUser() == "Test-User");
}

void TestEventExpert::testDeleteEvent() {
    destroyer->cleanEvents();
    EventExpert* testEventExpert = EventExpert::getInstance(testData);

    testEventExpert->createEvent(" 10:00", "2018-01-01", "Test-Event", "Test-User");
    testEventExpert->deleteEvent(" 10:00", "2018-01-01", "Test-Event", "Test-User");

    QVERIFY(testData->getAllEvents("Test-User", "2018-01-01").size() == 0);
}

void TestEventExpert::testEditEvent() {
    destroyer->cleanEvents();
    EventExpert* testEventExpert = EventExpert::getInstance(testData);

    testEventExpert->createEvent(" 10:00", "2018-01-01", "Test-Event", "Test-User");
    testEventExpert->editEvent(" 10:00", "2018-01-01", "Test-Event", "Test-User", " 12:00", "2018-01-02", "Test-Event updated");

    Event testEvent = testData->getAllEvents("Test-User", "2018-01-02").at(0);

    QVERIFY(testEvent.getTime() == " 12:00");
    QVERIFY(testEvent.getDate() == "2018-01-02");
    QVERIFY(testEvent.getDescription() == "Test-Event updated");
    QVERIFY(testEvent.getUser() == "Test-User");
}

void TestEventExpert::testEventTimeGetter() {
    destroyer->cleanEvents();
    EventExpert* testEventExpert = EventExpert::getInstance(testData);

    testEventExpert->createEvent(" 10:00", "2018-01-01", "Test-Event1", "Test-User");
    testEventExpert->createEvent(" 11:00", "2018-01-02", "Test-Event2", "Test-User");

    std::vector<std::string> times = testEventExpert->eventTimeGetter("Test-User", "2018-01-01");

    QVERIFY(times.size() == 1);
    QVERIFY(times.at(0) == " 10:00");
}

void TestEventExpert::testEventDateGetter() {
    destroyer->cleanEvents();
    EventExpert* testEventExpert = EventExpert::getInstance(testData);

    testEventExpert->createEvent(" 10:00", "2018-01-01", "Test-Event1", "Test-User");
    testEventExpert->createEvent(" 11:00", "2018-01-02", "Test-Event2", "Test-User");

    std::vector<std::string> times = testEventExpert->eventTimeGetter("Test-User", "2018-01-01");

    QVERIFY(times.size() == 1);
    QVERIFY(times.at(0) == " 10:00");
}

void TestEventExpert::testEventDescriptionGetter() {
    destroyer->cleanEvents();
    EventExpert* testEventExpert = EventExpert::getInstance(testData);

    testEventExpert->createEvent(" 10:00", "2018-01-01", "Test-Event1", "Test-User");
    testEventExpert->createEvent(" 11:00", "2018-01-02", "Test-Event2", "Test-User");

    std::vector<std::string> descriptions = testEventExpert->eventDescriptionGetter("Test-User", "2018-01-01");

    QVERIFY(descriptions.size() == 1);
    QVERIFY(descriptions.at(0) == "Test-Event1");
}

void TestEventExpert::testEventUserGetter() {
    destroyer->cleanEvents();
    EventExpert* testEventExpert = EventExpert::getInstance(testData);

    testEventExpert->createEvent(" 10:00", "2018-01-01", "Test-Event1", "Test-User");
    testEventExpert->createEvent(" 11:00", "2018-01-02", "Test-Event2", "Test-User");

    std::vector<std::string> user = testEventExpert->eventUserGetter("Test-User", "2018-01-01");

    QVERIFY(user.size() == 1);
    QVERIFY(user.at(0) == "Test-User");
}

void TestEventExpert::testEventSizeGetter() {
    destroyer->cleanEvents();
    EventExpert* testEventExpert = EventExpert::getInstance(testData);

    testEventExpert->createEvent(" 10:00", "2018-01-01", "Test-Event1", "Test-User");
    testEventExpert->createEvent(" 11:00", "2018-01-02", "Test-Event2", "Test-User");

    QVERIFY(testEventExpert->eventSizeGetter("Test-User", "2018-01-01") == 1);
}

void TestEventExpert::testGetAllDates() {
    destroyer->cleanEvents();
    EventExpert* testEventExpert = EventExpert::getInstance(testData);

    testEventExpert->createEvent(" 10:00", "2018-01-01", "Test-Event1", "Test-User");
    testEventExpert->createEvent(" 11:00", "2018-01-02", "Test-Event2", "Test-User");

    std::vector<std::string> dates = testEventExpert->getAllDates("Test-User");

    QVERIFY(dates.size() == 2);
    QVERIFY(dates.at(0) == "2018-01-01");
    QVERIFY(dates.at(1) == "2018-01-02");
}
