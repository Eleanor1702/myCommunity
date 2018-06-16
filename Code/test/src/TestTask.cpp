#include "../lib/TestTask.h"

void TestTask::testName() {
    Task testTask;

    testTask.setName("User");
    QVERIFY(testTask.getName() == "User");
}

void TestTask::testRoom() {
    Task testTask;

    testTask.setRoom("testRoom");
    QVERIFY(testTask.getRoom() == "testRoom");
}

void TestTask::testFrequency() {
    Task testTask;

    testTask.setFrequency("x mal");
    QVERIFY(testTask.getFrequency() == "x mal");
}



