#include <QApplication>
#include "userInterface/lib/setUpRooms.h"

int main(int argc, char **argv){

    WG wg;
/*
    wg.bewohnerErstellen();

    return 0;
    */

    QApplication app (argc, argv);

   // MainScreen screen;
    SetUpRooms main;

    main.run();

    //screen.run();
    return app.exec();

}
