#include <QtTest>
#include "lib/TestRoom.h"
<<<<<<< HEAD
=======
#include "lib/TestResident.h"
>>>>>>> bda086e93d0dd34653c16004ad3affd2ee321fc5

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    TestRoom testRoom;
<<<<<<< HEAD

    // multiple test suites can be ran like this
    return QTest::qExec(&testRoom, argc, argv); //|
            //QTest::qExec(&testParser, argc, argv);
=======
    TestResident testResident;

    // multiple test suites can be ran like this
    return QTest::qExec(&testRoom, argc, argv) |
           QTest::qExec(&testResident, argc, argv);
>>>>>>> bda086e93d0dd34653c16004ad3affd2ee321fc5
}
