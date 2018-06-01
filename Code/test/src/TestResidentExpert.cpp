#include "../lib/TestResidentExpert.h"

TestResidentExpert::TestResidentExpert(CommunityData *testData, TestDatabaseDeleter *destroyer) {
    this->testData = testData;
    this->destroyer = destroyer;
}

void TestResidentExpert::testCreateResident() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    QVERIFY(testResidentExpert->getResidents().size() == 1);
    QVERIFY(testResidentExpert->userNameGetter()[0] == "User");
}

void TestResidentExpert::testDeleteResident() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    testResidentExpert->deleteResident("User");
    QVERIFY(testResidentExpert->getResidents().size() == 0);
}

void TestResidentExpert::testEditResident() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    testResidentExpert->editResident("User", 4567);
    QVERIFY(testResidentExpert->getResidents()[0].getFirstname() == "User");
    QVERIFY(testResidentExpert->getResidents()[0].getPassword() == 4567);
}

void TestResidentExpert::testVerifyLogInData() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);

    //if matched
    testResidentExpert->verifyLogInData("User", 1234);
    QVERIFY(testResidentExpert->getResidents()[0].getFirstname() == "User");
    QVERIFY(testResidentExpert->getResidents()[0].getPassword() == 1234);

    //if not matched
    testResidentExpert->verifyLogInData("User", 4567);
    QVERIFY(testResidentExpert->getResidents()[0].getFirstname() == "User");
    QVERIFY(testResidentExpert->getResidents()[0].getPassword() != 4567);
}

void TestResidentExpert::testVerifyName() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    QVERIFY(testResidentExpert->getResidents()[0].getFirstname() == "User");
}

void TestResidentExpert::testUserNameGetter() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    QVERIFY(testResidentExpert->getResidents()[0].getFirstname()  == "User");
}

void TestResidentExpert::testGetResidents() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    QVERIFY(testResidentExpert->getResidents()[0].getFirstname() == "User");
    QVERIFY(testResidentExpert->getResidents()[0].getPassword() == 1234);
}

void TestResidentExpert::testCurrentUser() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    testResidentExpert->setCurrentUser("User");
    QVERIFY(testResidentExpert->getCurrentUser() == "User");
}
