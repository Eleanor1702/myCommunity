#include "../lib/TestResidentExpert.h"

TestResidentExpert::TestResidentExpert(CommunityData *testData, TestDatabaseDeleter *destroyer) {
    this->testData = testData;
    this->destroyer = destroyer;
}

void TestResidentExpert::testCreateResident() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    QVERIFY(testResidentExpert->userNameGetter().size() == 1);
    QVERIFY(testResidentExpert->userNameGetter()[0] == "User");
}

void TestResidentExpert::testDeleteResident() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    testResidentExpert->deleteResident("User");
    QVERIFY(testResidentExpert->userNameGetter().size() == 0);
}

void TestResidentExpert::testEditResident() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    testResidentExpert->editResident("User", 4567);
    QVERIFY(testResidentExpert->verifyLogInData("User", 1234) == false);
    QVERIFY(testResidentExpert->verifyLogInData("User", 4567) == true);
}

void TestResidentExpert::testVerifyLogInData() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);

    //if matched
    QVERIFY(testResidentExpert->verifyLogInData("User", 1234) == true);

    //if not matched
    QVERIFY(testResidentExpert->verifyLogInData("User", 4567) == false);
}

void TestResidentExpert::testVerifyName() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);

    //if matched
    QVERIFY(testResidentExpert->verifyName("User") == true);

    //if not matched
    QVERIFY(testResidentExpert->verifyName("test") == false);
}

void TestResidentExpert::testUserNameGetter() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    testResidentExpert->createResident("test", 9999);

    //Data are alphabetic sorted in database
    QVERIFY(testResidentExpert->userNameGetter().at(0) == "test");
    QVERIFY(testResidentExpert->userNameGetter().at(1) == "User");
}

void TestResidentExpert::testCurrentUser() {
    destroyer->cleanResidents();
    ResidentExpert* testResidentExpert = ResidentExpert::getInstance(testData);

    testResidentExpert->createResident("User", 1234);
    testResidentExpert->setCurrentUser("User");

    QVERIFY(testResidentExpert->getCurrentUser() == "User");
}
