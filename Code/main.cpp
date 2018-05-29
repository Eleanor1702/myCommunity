#include <QApplication>
#include "userInterface/lib/GuiController.h"

int main(int argc, char **argv){

    QApplication app (argc, argv);

    GuiController* gui = gui->getInstance();

    return app.exec();
}

