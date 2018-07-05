#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H

#include <QTest>
#include "../../lib/controller.h"
#include "../lib/TestDatabaseDeleter.h"

class TestController : public QObject {
    Q_OBJECT
private:
    CommunityData* testData;
    //allow the clean function to be called to clean databank
    TestDatabaseDeleter* destroyer;

public:
    TestController(CommunityData* testData, TestDatabaseDeleter* destroyer);

private slots:
    // Rooms
    void testAddRoom();
    void testDeleteRoom();
    void testGetRoomNames();
    void testGetRoomArts();
    void testGetRoomlistSize();

    // Residents
    void testAddResident();
    void testDeleteResident();
    void testEditResident();
    void testSearchResident();
    void testSearchNameResident();
    void testGetUserNames();
    void testGetUserlistSize();

    // Events
    void testAddEvent();
    void testDeleteEvent();
    void testGetEventTime();
    void testGetEventDate();
    void testGetEventDescription();
    void testGetEventUser();
    void testGetSizeEvent();
    void testGetAllDates();

    // Tasks
    void testAddTask();
    void testDeleteTask();
    void testGetTaskName();
    void testGetTaskRoom();
    void testGetTaskFrequency();
    void testGetTasklistSize();

    // ConcreteTasks
    void testAddConcreteTask();
    void testDeleteConcreteTask();
    void testGetConcreteTaskWeek();
    void testGetConcreteTaskName();
    void testGetConcreteTaskRes();
    void testGetConcreteTaskRoom();
    void testGetConcreteTaskListSize();

    // Shopping
    void testAddItem();
    void testDeleteItem();
    void testGetItemNames();
    void testGetItemNumber();
    void testGetItemlistSize();

    // MISC
    void testCurrentUser();
};

#endif // TESTCONTROLLER_H
