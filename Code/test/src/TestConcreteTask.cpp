#include "../lib/TestConcreteTask.h"

void TestConcreteTask::testTask() {
    Task newTask;
    newTask.setName("TestTask");

    ConcreteTask testConcreteTask;
    testConcreteTask.setTask(newTask);

    QVERIFY(testConcreteTask.getTask().getName() == newTask.getName());
}

void TestConcreteTask::testResident() {
    ConcreteTask testConcreteTask;
    testConcreteTask.setResident("TestResident");

    QVERIFY(testConcreteTask.getResident() == "TestResident");
}

void TestConcreteTask::testCalendarWeek() {
    ConcreteTask testConcreteTask;
    testConcreteTask.setCalendarweek(20);

    QVERIFY(testConcreteTask.getCalendarweek() == 20);
}
