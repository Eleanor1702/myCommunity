#include <QApplication>
#include "userInterface/lib/GuiController.h"


int main(int argc, char **argv){

/*
    wg.bewohnerErstellen();

    return 0;
    */

    QApplication app (argc, argv);

    GuiController g;

    return app.exec();

}
