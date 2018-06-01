#include "../lib/TestRoomExpert.h"

TestRoomExpert::TestRoomExpert(CommunityData *testData, TestDatabaseDeleter* destroyer) {
    this->testData = testData;
    this->destroyer = destroyer;
}

void TestRoomExpert::testCreateRoom() {
    destroyer->cleanRooms();
    RoomExpert* testRoomExpert = RoomExpert::getInstance(testData);

    testRoomExpert->createRoom("myBath", "Bath");
    QVERIFY(testRoomExpert->getRooms().size() == 1);
    QVERIFY(testRoomExpert->roomNameGetter()[0] == "myBath");
    QVERIFY(testRoomExpert->roomArtGetter()[0] == "Bath");
}

void TestRoomExpert::testDeleteRoom() {
    destroyer->cleanRooms();
    RoomExpert* testRoomExpert = RoomExpert::getInstance(testData);

    testRoomExpert->createRoom("myBath", "Bath");
    testRoomExpert->deleteRoom("myBath");
    QVERIFY(testRoomExpert->getRooms().size() == 0);
}

void TestRoomExpert::testRoomNameGetter() {
    destroyer->cleanRooms();
    RoomExpert* testRoomExpert = RoomExpert::getInstance(testData);

    testRoomExpert->createRoom("myBath", "Bath");
    QVERIFY(testRoomExpert->roomNameGetter()[0] == "myBath");
}

void TestRoomExpert::testRoomArtGetter() {
    destroyer->cleanRooms();
    RoomExpert* testRoomExpert = RoomExpert::getInstance(testData);

    testRoomExpert->createRoom("myBath", "Bath");
    QVERIFY(testRoomExpert->roomArtGetter()[0] == "Bath");
}

void TestRoomExpert::testGetRooms() {
    destroyer->cleanRooms();
    RoomExpert* testRoomExpert = RoomExpert::getInstance(testData);

    testRoomExpert->createRoom("myBath", "Bath");
    QVERIFY(testRoomExpert->getRooms()[0].getName() == "myBath");
    QVERIFY(testRoomExpert->getRooms()[0].getArt() == "Bath");
}
