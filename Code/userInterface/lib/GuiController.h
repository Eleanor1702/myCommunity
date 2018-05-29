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
#include "userInterface/lib/SetUpTasks.h"
#include "userInterface/lib/cleaningpage.h"

#include "lib/controller.h"

//Inheritance from QWidget is a must
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

public slots:
  //class need to be QWidget to be able to call the actions

  //StartPage Slots
  void callSignUp();
  void callSignIn();

  //SignUp Slots
  void signUpNewUser(std::string name, int password);

  //SignIn Slots
  void logInUser(std::string name, int password);

  //SignUp & SignIn Slots
  void callStartPage();

  //HomePage Slots
  void callRoomSettings();
  void callUserSettings();
  void callCalendar();
  void callCleanPlan();
  void callLogOut();

  //SetUpRooms Slots
  void newRoomSet();
  void roomDeleted(QString room);

  //SetUpUsers Slots:
  void newUserSet();
  void userDeleted(QString name);
  //void deleteUserButtonClicked(QString name);

  //Back To HomePage Slot:
  void callHomePage();

  //Cleaning Plan Slots:
  void callTask();
  //void createPlanButtonClicked();

  //SetUpTask Slots:
  void taskDeleted(QString task);
  void newTaskSet();

public:
  static GuiController* getInstance();     //Singleton

protected:
  explicit GuiController();
};

#endif // GUICONTROLLER_H
