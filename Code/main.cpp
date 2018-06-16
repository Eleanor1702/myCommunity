#include <QApplication>
#include "Database/lib/DatabaseConfig.h"
#include "userInterface/lib/SetUpConfiguration.h"
#include "userInterface/lib/GuiController.h"
#include "Database/lib/communitydata.h"
#include "lib/controller.h"
#include <QtDebug>

int main(int argc, char **argv){

    QApplication app (argc, argv);

    DatabaseConfig config;
    SetUpConfiguration startConfig;

    if (config.exist()) {
        config.read();
        CommunityData* data = CommunityData::getInstance(config.getUser(), config.getPassword(),
                                                         config.getHost(), config.getDatabase());
        Controller* con = Controller::getInstance(data);

        GuiController::startApplication(con);
    }else{
        startConfig.show();
    }

    return app.exec();
}

