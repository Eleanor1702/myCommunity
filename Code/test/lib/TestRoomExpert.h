#ifndef TESTROOMEXPERT_H
#define TESTROOMEXPERT_H

#include <QTest>
#include "../../lib/RoomExpert.h"
#include "../lib/TestDatabaseDeleter.h"

class TestRoomExpert : public QObject {
    Q_OBJECT
private:
    CommunityData* testData;
    //allow the clean function to be called to clean databank
    TestDatabaseDeleter* destroyer;

public:
    TestRoomExpert(CommunityData* testData, TestDatabaseDeleter* destroyer);

private slots:
    void testCreateRoom();
    void testDeleteRoom();
    void testRoomNameGetter();
    void testRoomArtGetter();
    void testGetRooms();
};

#endif // TESTROOMEXPERT_H
