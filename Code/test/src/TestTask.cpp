#include "../lib/TestTask.h"

void TestTask::testName() {
    Task testTask;

    testTask.setName("User");
    QVERIFY(testTask.getName() == "User");
}



