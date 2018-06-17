#include <QtTest>
#include "Database/lib/communitydata.h"
#include "test/lib/TestDatabaseDeleter.h"
#include "lib/TestResident.h"
#include "lib/TestRoom.h"
#include "lib/TestTask.h"
#include "lib/TestEvent.h"
#include "lib/TestRoomExpert.h"
#include "lib/TestResidentExpert.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    std::string user = "user";
    std::string password = "mycommunity";
    std::string host = "localhost";
    std::string database = "TestMyCommunity";

    CommunityData* testData = CommunityData::getInstance(user, password, host, database);
    TestDatabaseDeleter* destroyer = new TestDatabaseDeleter(user, password, host, database);

    TestRoom room;
    TestResident resident;
    TestTask task;
    TestEvent event;
    TestRoomExpert roomExpert(testData, destroyer);
    TestResidentExpert residentExpert(testData, destroyer);

    // multiple test suites can be ran like this
    return QTest::qExec(&room, argc, argv) |
           QTest::qExec(&resident, argc, argv) |
           QTest::qExec(&task, argc, argv) |
           QTest::qExec(&event, argc, argv) |
           QTest::qExec(&roomExpert, argc, argv) |
           QTest::qExec(&residentExpert, argc, argv);
}
