#include <QApplication>
#include "userInterface/lib/GuiController.h"


int main(int argc, char **argv){

    QApplication app (argc, argv);

    GuiController init;

    return app.exec();

}
