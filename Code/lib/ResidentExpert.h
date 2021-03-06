#ifndef RESIDENTEXPERT_H
#define RESIDENTEXPERT_H

#include <vector>

#include "Resident.h"
#include "Database/lib/communitydata.h"

class ResidentExpert{
private:
    static ResidentExpert* instance;

    Resident re;
    CommunityData* data;

    std::string currentUser;                                      //current loged in User

protected:
    ResidentExpert(CommunityData* data);

public:
    void createResident(std::string name, int password);
    void deleteResident(std::string name);
    void editResident(std::string username, int newPassword);
    bool verifyLogInData(std::string username, int password);
    bool verifyName(std::string username);

    void setCurrentUser(std::string newUser);
    std::string getCurrentUser();
    std::string getCurrentUserPassword();

    std::vector<std::string> userNameGetter();

    static ResidentExpert* getInstance(CommunityData* data);
    ~ResidentExpert();
};

#endif // RESIDENTEXPERT_H
