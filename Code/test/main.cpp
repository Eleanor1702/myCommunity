#include <QtTest>
#include "lib/TestRoom.h"
#include "lib/TestResident.h"
#include "lib/TestRoomExpert.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    TestRoom testRoom;
    TestResident testResident;
    TestRoomExpert testRoomExpert;

    // multiple test suites can be ran like this
    return QTest::qExec(&testRoom, argc, argv) |
           QTest::qExec(&testResident, argc, argv) |
           QTest::qExec(&testRoomExpert, argc, argv);
}
