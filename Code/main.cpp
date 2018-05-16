#include <QApplication>
#include "userInterface/lib/GuiController.h"
#include "Database/lib/communitydata.h"


int main(int argc, char **argv){

    QApplication app (argc, argv);

    GuiController init;


    return app.exec();

}
