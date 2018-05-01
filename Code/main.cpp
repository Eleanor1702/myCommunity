#include <QApplication>
#include "userInterface/lib/SignUp.h"


int main(int argc, char **argv){

/*
    wg.bewohnerErstellen();

    return 0;
    */

    QApplication app (argc, argv);

   // MainScreen screen;
    SignUp signup;
    signup.show();

    return app.exec();

}
