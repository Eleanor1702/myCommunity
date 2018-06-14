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
#include "userInterface/lib/changepwpage.h"
#include "userInterface/lib/setupshoppinglist.h"

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
  changePwPage *pwpage;

  EventPage *events;

  CleaningPage *clean;
  SetUpTasks *task;

  SetUpShoppinglist* shop;

  Controller* con;

  static GuiController* instance;               //Singleton

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
  void callUserSettingsFromPwPage();
  void callCalendar();
  void callCleanPlan();
  void callLogOut();
  void callShoppingList();

  //SetUpRooms Slots
  void newRoomSet();
  void roomDeleted(QString room);

  //SetUpUsers Slots:
  void newUserSet();
  void userDeleted(QString name);
  void callPwPage();
  //void deleteUserButtonClicked(QString name);

  //PwPage Slots
  void changePW();

  //Back To HomePage Slot:
  void callHomePage();

  //EventPage Slots:
  void newEventSet();
  void eventAppeared();
  void eventDeleted(QString time, QString date, QString description, QString user);
  //void eventEdited();

  //Cleaning Plan Slots:
  void callTask();
  //void createPlanButtonClicked();

  //SetUpTask Slots:
  void taskDeleted(QString task, QString room);
  void newTaskSet();

  //SetUpShoppinglist Slots:
  void newItemSet();
  void ItemDeleted(QString name);

public:
    static void startApplication(Controller* con);
    std::vector<std::string>getRooms();

protected:
    static GuiController* getInstance(Controller* con);        //Singleton
    explicit GuiController(Controller* con);
};

#endif // GUICONTROLLER_H

