#include <QApplication>
#include "userInterface/lib/GuiController.h"
//#include "lib/communitydata.h"


int main(int argc, char **argv){

    QApplication app (argc, argv);

    GuiController init;

    //CommunityData Data;


    return app.exec();

}
