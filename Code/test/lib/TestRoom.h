#ifndef TESTROOM_H
#define TESTROOM_H

#include <QtTest>
#include "../../lib/room.h"

class TestRoom : public QObject {
    Q_OBJECT

private slots:
    void testArt();
    void testName();
};

#endif // TESTROOM_H
