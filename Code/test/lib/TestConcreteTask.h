#ifndef TESTCONCRETETASK_H
#define TESTCONCRETETASK_H

#include <QTest>
#include "../../lib/concretetask.h"
#include "../../lib/Task.h"

class TestConcreteTask : public QObject {
    Q_OBJECT
private slots:
    void testTask();
    void testResident();
    void testCalendarWeek();
};

#endif // TESTCONCRETETASK_H
