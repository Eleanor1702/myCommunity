#ifndef TESTTASKEXPERT_H
#define TESTTASKEXPERT_H

#include <QTest>
#include "../../lib/taskexpert.h"
#include "../lib/TestDatabaseDeleter.h"

class TestTaskExpert : public QObject {
    Q_OBJECT
private:
    CommunityData* testData;
    //allow the clean function to be called to clean databank
    TestDatabaseDeleter* destroyer;

public:
    TestTaskExpert(CommunityData* testData, TestDatabaseDeleter* destroyer);

private slots:
    void testCreateTask();
    void testDeleteTask();
    void testTaskNameGetter();
    void testTaskRoomGetter();
    void testTaskFrequencyGetter();
    void testGetTasks();
    void testCreateConcreteTask();
    void testDeleteConcreteTask();
    void testConcreteTaskGetter();
    void testConcreteTaskNameGetter();
    void testConcreteTaskRoomGetter();
    void testConcreteTaskWeekGetter();
    void testConcreteTaskResGetter();
};

#endif // TESTTASKEXPERT_H
