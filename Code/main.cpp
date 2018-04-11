#include <QApplication>
#include "lib/mainscreen.h"

int main(int argc, char **argv){
    QApplication app (argc, argv);

    MainScreen screen;

    screen.run();

    return app.exec();
}
