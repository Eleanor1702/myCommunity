#ifndef TESTRESIDENTEXPERT_H
#define TESTRESIDENTEXPERT_H

#include <QTest>
#include "../../lib/ResidentExpert.h"
#include "../lib/TestDatabaseDeleter.h"

class TestResidentExpert : public QObject {
    Q_OBJECT
private:
    CommunityData* testData;
    //allow the clean function to be called to clean databank
    TestDatabaseDeleter* destroyer;

public:
    TestResidentExpert(CommunityData* testData, TestDatabaseDeleter* destroyer);

private slots:
    void testCreateResident();
    void testDeleteResident();
    void testEditResident();
    void testVerifyLogInData();
    void testVerifyName();
    void testUserNameGetter();
    void testGetResidents();
    void testCurrentUser();
};

#endif // TESTRESIDENTEXPERT_H
