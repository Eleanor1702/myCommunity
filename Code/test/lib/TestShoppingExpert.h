#ifndef TESTSHOPPINGEXPERT_H
#define TESTSHOPPINGEXPERT_H

#include <QTest>
#include "../../lib/shoppingexpert.h"
#include "../lib/TestDatabaseDeleter.h"

class TestShoppingExpert : public QObject {
    Q_OBJECT
private:
    CommunityData* testData;
    //allow the clean function to be called to clean databank
    TestDatabaseDeleter* destroyer;

public:
    TestShoppingExpert(CommunityData* testData, TestDatabaseDeleter* destroyer);

private slots:
    void testCreateItem();
    void testDeleteItem();
    void testItemNameGetter();
    void testItemNumberGetter();
    void testGetItems();
};

#endif // TESTSHOPPINGEXPERT_H
