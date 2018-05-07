#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <QApplication>
#include <QWidget>

#include "userInterface/lib/StartPage.h"
#include "userInterface/lib/SignUp.h"
#include "userInterface/lib/SignIn.h"
#include "userInterface/lib/HomePage.h"

#include "lib/controller.h"
#include <string>

//Inheritance from QWidget ist a must
//Reason-> this class has slots
class GuiController : public QWidget{
  Q_OBJECT

private:
  StartPage *main;
  SignUp *up;
  SignIn *in;
  HomePage *home;

  Controller* con;

protected:

public:
  explicit GuiController(QWidget *parent = NULL);

public slots:
  //class need to be QWidget to be able to call the actions
  void signUpButtonClicked();
  void signInButtonClicked();
  void backButtonClicked();
  void speichernButtonClicked();
  void logInButtonClicked();

};
#endif // GUICONTROLLER_H
