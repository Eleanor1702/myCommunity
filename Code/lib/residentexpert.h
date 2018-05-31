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

    void createResident(std::string name, int password);
    void deleteResident(std::string name);
    void editResident(std::string username, int newPassword);
    bool verifyLogInData(std::string username, int password);
    bool verifyName(std::string username);

    std::vector<std::string> userNameGetter();

    std::vector<Resident> getResidents();

    static ResidentExpert* getInstance();
};

#endif // RESIDENTEXPERT_H
