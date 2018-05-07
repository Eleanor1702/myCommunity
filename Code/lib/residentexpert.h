#ifndef RESIDENTEXPERT_H
#define RESIDENTEXPERT_H
#include <vector>
#include "resident.h"

class ResidentExpert{
    private:
    vector<Resident*> Residentlist;

    public:
    ResidentExpert();
    void createResident(string name, int password);
    void deleteResident(string name);
    void editResident(string username, int newPassword);

};

#endif // RESIDENTEXPERT_H
