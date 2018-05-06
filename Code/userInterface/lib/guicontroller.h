#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include "RoomListItem.h"
#include "SetUpRooms.h"
#include "SetUpUsers.h"
#include "SignUp.h"
#include "UserList.h"
#include <QApplication>
#include <QWidget>

#include "userInterface/lib/StartPage.h"
#include "userInterface/lib/SignUp.h"
#include "userInterface/lib/SignIn.h"

class GuiController : public QWidget{
  Q_OBJECT

private:
  StartPage *main;
  SignUp *up;
  SignIn *in;

protected:

public:
  explicit GuiController(QWidget *parent = NULL);

public slots:
  void signUpButtonClicked();
  void signInButtonClicked();
  void backButtonClicked();

};
#endif // GUICONTROLLER_H
