#ifndef TESTRESIDENT_H
#define TESTRESIDENT_H

#include <QTest>
#include "../../lib/Resident.h"

class TestResident : public QObject {
  Q_OBJECT

private slots:
  void testPassword();
  void testFirstName();
};

#endif // TESTRESIDENT_H
