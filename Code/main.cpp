#include <QApplication>
#include "lib/mainscreen.h"
#include "userInterface/lib/startpage.h"
#include "lib/wg.h"

int main(int argc, char **argv){

    WG wg;

    wg.bewohnerErstellen();

    return 0;

    /*
    QApplication app (argc, argv);

    //MainScreen screen;
    StartPage mainWindow;

    mainWindow.run();

    //screen.run();

    return app.exec();
    */
}
