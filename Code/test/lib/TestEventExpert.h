#ifndef TESTEVENTEXPERT_H
#define TESTEVENTEXPERT_H

#include <QTest>
#include "../../lib/EventExpert.h"
#include "../lib/TestDatabaseDeleter.h"

class TestEventExpert : public QObject {
    Q_OBJECT
private:
    CommunityData* testData;
    //allow the clean function to be called to clean databank
    TestDatabaseDeleter* destroyer;

public:
    TestEventExpert(CommunityData* testData, TestDatabaseDeleter* destroyer);

private slots:
    void testCreateEvent();
    void testDeleteEvent();
    void testEditEvent();
    void testEventTimeGetter();
    void testEventDateGetter();
    void testEventDescriptionGetter();
    void testEventUserGetter();
    void testEventSizeGetter();
    void testGetAllDates();
};

#endif // TESTEVENTEXPERT_H
