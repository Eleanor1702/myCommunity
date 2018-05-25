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
#include "userInterface/lib/eventpage.h"
#include "userInterface/lib/setuptasks.h"
#include "userInterface/lib/cleaningpage.h"

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

  EventPage *events;

  CleaningPage *clean;
  SetUpTasks *task;

  Controller* con;

  static GuiController* instance;   //Singleton

public:
 static GuiController* getInstance(QWidget *parent);     //Singleton
 explicit GuiController(QWidget *parent = NULL);

public slots:
  //class need to be QWidget to be able to call the actions

  //StartPage Slots
  void callSignUp();
  void callSignIn();

  //SignUp Slots
  void saveClicked();

  //SignIn Slots
  void logInClicked();

  //SignUp & SignIn Slots
  void callStartPage();

  //HomePage Slots
  void roomSettingClicked();
  void userSettingClicked();
  void calendarClicked();
  void cleanPlanButtonClicked();
  void logOutClicked();

  //SetUpRooms Slots
  void addRoomButtonClicked();
  void roomDeleted(QString room);
  void saveRoomButtonClicked();

  //SetUpUsers Slots:
  //void deleteUserButtonClicked(QString name);
  //void saveUserButtonClicked();

  //Events Slots
  void saveEventButtonClicked();

  //Putzplan
  void setupTaskButtonClicked();
  //void createPlanButtonClicked();
  void backToHomeButtonClicked();

  void saveTaskButtonClicked();
  //void deleteTaskButtonClicked();
  void addTaskButtonClicked();

};
#endif // GUICONTROLLER_H
