#ifndef RESIDENTEXPERT_H
#define RESIDENTEXPERT_H
#include <vector>
#include "resident.h"
#include <iostream>
class ResidentExpert{
private:
    Resident *re;
    vector<Resident*> Residentlist;

    public:
    ResidentExpert();
    void createResident(string name, int password);
    void deleteResident(string name);
    void editResident(string username, int newPassword);
    bool verifyLogInData(string username, int password);

};

#endif // RESIDENTEXPERT_H
