#include <QtTest>
#include "lib/TestRoom.h"
<<<<<<< HEAD
=======
#include "lib/TestResident.h"
>>>>>>> bda086e... Add first test

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    TestRoom testRoom;
    TestResident testResident;

    // multiple test suites can be ran like this
    return QTest::qExec(&testRoom, argc, argv) |
           QTest::qExec(&testResident, argc, argv);
}
