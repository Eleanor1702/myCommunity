#ifndef RESIDENTEXPERT_H
#define RESIDENTEXPERT_H

#include <vector>
#include "resident.h"
#include <QTextStream>

class ResidentExpert{
private:
    Resident *re;
    std::vector<Resident*> Residentlist;

    public:
    ResidentExpert();
    void createResident(string name, int password);
    void deleteResident(string name);
    void editResident(string username, int newPassword);
    bool verifyLogInData(string username, int password);

    //Allow COUT
    QTextStream& qStdOut();
};

#endif // RESIDENTEXPERT_H
