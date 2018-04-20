#include <QApplication>
#include "lib/mainscreen.h"
#include "userInterface/lib/setUpRooms.h"
#include "lib/wg.h"

int main(int argc, char **argv){
    /*
    WG wg;

    wg.bewohnerErstellen();

    return 0;
    */

    QApplication app (argc, argv);

    //MainScreen screen;
    SetUpRooms main;

    main.run();

    return app.exec();

}
