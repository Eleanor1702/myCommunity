#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

<<<<<<< HEAD
#include "RoomListItem.h"
#include "SetUpRooms.h"
#include "SetUpUsers.h"
#include "SignUp.h"
#include "UserList.h"
=======
#include <QApplication>
#include <QWidget>
>>>>>>> 85e2b20551bb013ca5174df67a9de20088a76f89

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
