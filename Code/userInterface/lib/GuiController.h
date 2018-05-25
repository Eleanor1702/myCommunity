#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <QApplication>
#include <QWidget>

#include "userInterface/lib/StartPage.h"
#include "userInterface/lib/SignUp.h"
#include "userInterface/lib/SignIn.h"
#include "userInterface/lib/HomePage.h"
#include "userInterface/lib/SetUpRooms.h"
#include "userInterface/lib/SetUpUsers.h"

#include "lib/controller.h"

#include <string>

//Inheritance from QWidget ist a must
//because this class has slots
class GuiController : public QWidget{
  Q_OBJECT

private:
  StartPage *main;
  SignUp *up;
  SignIn *in;

  HomePage *home;
  SetUpRooms *rooms;
  SetUpUsers *users;

  Controller* con;

  static GuiController* instance;   //Singleton

public slots:
  //class need to be QWidget to be able to call the actions
  void signUpButtonClicked();
  void signInButtonClicked();

  void saveButtonClicked();
  void logInButtonClicked();
  void backButtonClicked();

  void userSettingsButtonClicked();
  void roomSettingsButtonClicked();
  void signOutButtonClicked();

  void addRoomButtonClicked();
  void deleteRoomButtonClicked(QString room);
  void saveRoomButtonClicked();

  void deleteUserButtonClicked(QString name);
  void saveUserButtonClicked();

public:
  static GuiController* getInstance(QWidget *parent);     //Singleton
  explicit GuiController(QWidget *parent = NULL);

  void dataBankRoomUpdate(std::vector<std::string> nameVector, std::vector<std::string> artVector, int size);
  void clearScrollLayout();
};
#endif // GUICONTROLLER_H
