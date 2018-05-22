#ifndef RESIDENTEXPERT_H
#define RESIDENTEXPERT_H

#include <vector>
#include "resident.h"
#include "Database/lib/communitydata.h"

class ResidentExpert{
private:
    static ResidentExpert* instance;
    Resident re;
    std::vector<Resident> Residentlist;
    CommunityData* data;

protected:
    ResidentExpert();

public:

    void createResident(string name, int password);
    void deleteResident(string name);
    void editResident(string username, int newPassword);
    bool verifyLogInData(string username, int password);
    bool verifyName(string username);

    static ResidentExpert* getInstance();
};

#endif // RESIDENTEXPERT_H
