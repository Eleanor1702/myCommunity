#ifndef TESTTASK_H
#define TESTTASK_H

#include <QTest>
#include "../../lib/Task.h"

class TestTask : public QObject {
    Q_OBJECT

private slots:
    void testName();
};

#endif // TESTTASK_H
