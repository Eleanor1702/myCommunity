#ifndef RESIDENTEXPERT_H
#define RESIDENTEXPERT_H

#include <vector>
#include "resident.h"
#include <QTextStream>

class ResidentExpert{
private:
    Resident re;
    std::vector<Resident> Residentlist;
    static ResidentExpert* instance;

protected:
    ResidentExpert();
public:

    void createResident(string name, int password);
    void deleteResident(string name);
    void editResident(string username, int newPassword);
    bool verifyLogInData(string username, int password);
    bool verifyName(string username);

    static ResidentExpert* getInstance();
    //Allow COUT
    QTextStream& qStdOut();
};

#endif // RESIDENTEXPERT_H
