#include <QApplication>
#include "userInterface/lib/SetUpRooms.h"


int main(int argc, char **argv){

/*
    wg.bewohnerErstellen();

    return 0;
    */

    QApplication app (argc, argv);

   // MainScreen screen;
    SetUpRooms setUpRooms;

    setUpRooms.show();

    return app.exec();

}
