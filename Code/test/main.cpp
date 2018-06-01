#include <QtTest>
#include "Database/lib/communitydata.h"
#include "test/lib/testdatabasedeleter.h"
#include "lib/TestRoom.h"
#include "lib/TestResident.h"
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

    TestRoom testRoom;
    TestResident testResident;
    TestRoomExpert testRoomExpert(testData, destroyer);
    TestResidentExpert testResidentExpert(testData, destroyer);

    // multiple test suites can be ran like this
    return QTest::qExec(&testRoom, argc, argv) |
           QTest::qExec(&testResident, argc, argv) |
           QTest::qExec(&testRoomExpert, argc, argv) |
           QTest::qExec(&testResidentExpert, argc, argv);
}
