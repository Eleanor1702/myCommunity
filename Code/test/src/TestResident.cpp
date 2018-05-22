#include "../lib/TestResident.h"

void TestResident::testPassword() {
  Resident testResident;

  testResident.setPassword(1234);
  QVERIFY(testResident.getPassword() == 1234);
}

void TestResident::testFirstName() {
  Resident testResident;

  testResident.setFirstname("testUser");
  QVERIFY(testResident.getFirstname() == "testUser");
}
