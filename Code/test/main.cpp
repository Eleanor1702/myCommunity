#include <QtTest>
#include "Database/lib/communitydata.h"
#include "test/lib/TestDatabaseDeleter.h"
#include "lib/TestResident.h"
#include "lib/TestRoom.h"
#include "lib/TestTask.h"
#include "lib/TestEvent.h"
#include "lib/TestShoppingItem.h"
#include "lib/TestRoomExpert.h"
#include "lib/TestResidentExpert.h"
#include "lib/TestConcreteTask.h"
#include "lib/TestEventExpert.h"
#include "lib/TestShoppingExpert.h"
#include "lib/TestTaskExpert.h"
#include "lib/TestController.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    std::string user = "user";
    std::string password = "mycommunity";
    std::string host = "localhost";
    std::string database = "TestMyCommunity";

    CommunityData* testData = CommunityData::getInstance(user, password, host, database);
    TestDatabaseDeleter* destroyer = new TestDatabaseDeleter(user, password, host, database);

    TestConcreteTask concreteTask;
    TestRoom room;
    TestResident resident;
    TestTask task;
    TestEvent event;
    TestShoppingItem shoppingItem;
    TestRoomExpert roomExpert(testData, destroyer);
    TestResidentExpert residentExpert(testData, destroyer);
    TestEventExpert eventExpert(testData, destroyer);
    TestShoppingExpert shoppingExpert(testData, destroyer);
    TestTaskExpert taskExpert(testData, destroyer);
    TestController controller(testData, destroyer);

    // multiple test suites can be ran like this
    return QTest::qExec(&concreteTask, argc, argv) |
           QTest::qExec(&room, argc, argv) |
           QTest::qExec(&resident, argc, argv) |
           QTest::qExec(&task, argc, argv) |
           QTest::qExec(&event, argc, argv) |
           QTest::qExec(&shoppingItem, argc, argv) |
           QTest::qExec(&roomExpert, argc, argv) |
           QTest::qExec(&residentExpert, argc, argv) |
           QTest::qExec(&eventExpert, argc, argv) |
           QTest::qExec(&shoppingExpert, argc, argv) |
           QTest::qExec(&taskExpert, argc, argv) |
           QTest::qExec(&controller, argc, argv);
}
