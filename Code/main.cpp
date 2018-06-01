#include <QApplication>
#include "userInterface/lib/GuiController.h"
#include "Database/lib/communitydata.h"
#include "lib/controller.h"

int main(int argc, char **argv){

    QApplication app (argc, argv);

    //For an easier testing including databank
    std::string user = "user";
    std::string password = "bmns2018!!";
    std::string host = "172.104.230.99";
    std::string database ="MyCommunity";

    CommunityData* data = CommunityData::getInstance(user, password, host, database);
    Controller* con = Controller::getInstance(data);

    GuiController::startApplication(con);

    return app.exec();
}

