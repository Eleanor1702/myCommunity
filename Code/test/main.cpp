#include <QtTest>
#include "lib/TestRoom.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    TestRoom testRoom;

    // multiple test suites can be ran like this
    return QTest::qExec(&testRoom, argc, argv); //|
            //QTest::qExec(&testParser, argc, argv);
}
