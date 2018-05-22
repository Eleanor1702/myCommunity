#include <QtTest>
#include "lib/TestRoom.h"
#include "lib/TestResident.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    TestRoom testRoom;
    TestResident testResident;

    // multiple test suites can be ran like this
    return QTest::qExec(&testRoom, argc, argv) |
           QTest::qExec(&testResident, argc, argv);
}
