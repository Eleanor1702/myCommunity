#ifndef TESTSHOPPINGITEM_H
#define TESTSHOPPINGITEM_H

#include <QtTest>
#include "../../lib/shoppingitem.h"

class TestShoppingItem : public QObject {
    Q_OBJECT

private slots:
    void testItemName();
    void testNumber();
};

#endif // TESTSHOPPINGITEM_H
