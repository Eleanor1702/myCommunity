#include "userInterface/lib/GuiController.h"

GuiController* GuiController::instance = NULL;

GuiController* GuiController::getInstance(){
    if(instance == NULL){
        instance = new GuiController();
    }
    return instance;
}

GuiController::GuiController() : QWidget() {
    this->main = new StartPage();
    this->up = new SignUp();
    this->in = new SignIn();

    this->home = new HomePage();
    this->rooms = new SetUpRooms();
    this->users = new SetUpUsers();
    this->events = new EventPage();
    this->clean = new CleaningPage();
    this->task = new SetUpTasks();

    con = this->con->getInstance();

    //StartPage Events
    connect(main, SIGNAL(signUpCallSignal()), this, SLOT(callSignUp()));
    connect(main, SIGNAL(signInCallSignal()), this, SLOT(callSignIn()));

    //SignUp Events
    connect(up, SIGNAL(startPageCallSignal()), this, SLOT(callStartPage()));
    connect(up, SIGNAL(newUserSignUpSignal(std::string,int)),this, SLOT(signUpNewUser(std::string,int)));

    //SignIn Events
    connect(in, SIGNAL(startPageCallSignal()), this, SLOT(callStartPage()));
    connect(in, SIGNAL(userLogInSignal(std::string,int)), this, SLOT(logInUser(std::string, int)));

    //HomePage Events
    connect(home, SIGNAL(roomSettingsCallSignal()), this, SLOT(callRoomSettings()));
    connect(home, SIGNAL(userSettingsCallSignal()), this, SLOT(callUserSettings()));
    connect(home, SIGNAL(calendarCallSignal()), this, SLOT(callCalendar()));
    connect(home, SIGNAL(cleanPlanCallSignal()), this, SLOT(callCleanPlan()));
    connect(home, SIGNAL(logOutCallSignal()), this, SLOT(callLogOut()));

    //SetUpRoomsEvents
    connect(rooms, SIGNAL(setNewRoomSignal()), this, SLOT(newRoomSet()));
    connect(rooms, SIGNAL(deleteRoomSignal(QString)), this, SLOT(roomDeleted(QString)));
    connect(rooms, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));

    //SetUpUsers Events
    //QObject::connect(users->addButton,SIGNAL(clicked()),this,SLOT(addUserButtonClicked()));

    //EventPage Events
    connect(events, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));

    //CleaningPage Events
    connect(clean, SIGNAL(taskCallSignal()), this, SLOT(callTask()));
    connect(clean, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));

    //SetUpTask Events
    connect(task, SIGNAL(newTaskSignal()), this, SLOT(newTaskSet()));
    connect(task, SIGNAL(deleteTaskSignal(QString)), this, SLOT(taskDeleted(QString)));
    connect(task, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));

    //show main page
    this->main->show();
}

//StartPage Events
void GuiController::callSignUp(){
    up->show();
    main->hide();
}

//SignUp Event
void GuiController::signUpNewUser(std::string name, int password) {
    if( !(con->searchNameResident(name)) ) {
        con->addResident(name, password);

        in->show();
        up->hide();
    }
}

void GuiController::callSignIn(){
    in->show();
    main->hide();
}

//SignIn Event
void GuiController::logInUser(std::string name, int password) {
    if(con->searchResident(name, password)) {
        home->show();
        in->hide();
    }
}

//SignUp & SignIn Event
void GuiController::callStartPage() {
    main->show();
    in->hide();
    up->hide();
}

//HomePage Events
void GuiController::callRoomSettings() {
    //Show SetUpRooms and update room List
    rooms->appear(con->getRoomNames(), con->getRoomArts(), con->getSize());
    home->hide();
}

//SetUpRooms Events
void GuiController::newRoomSet() {
    if(rooms->getRoomNameInput() == "Error") {
        //Exception
        return;
    }else{
        //databank connection
        con->addRoom(rooms->getRoomTypeInput(), rooms->getRoomNameInput());
    }

    //update room list in Gui
    rooms->appear(con->getRoomNames(), con->getRoomArts(), con->getSize());
}

void GuiController::roomDeleted(QString room) {
    // delete room from Databank
    con->deleteRoom(room.toStdString());

    rooms->appear(con->getRoomNames(), con->getRoomArts(), con->getSize());
}

void GuiController::callUserSettings() {
    users->show();
    home->hide();
}

//SetUpUser Events
void GuiController::newUserSet() {
    /*QString userName = users->giveNameEdit->text();
    if(userName.size() == 0 || userName[0] == ' '){
        return;
    }

    QString userPassword = users->givePasswordEdit->text();
    if(userPassword.size() == 0 || userPassword[0] == ' '){
        return;
    }

    this->users->newUser = new UserList(userName);

    this->users->scrollLayout->addWidget(users->newUser);

    this->users->giveNameEdit->clear();
    this->users->givePasswordEdit->clear();

    connect(this->users->newUser,SIGNAL(deleteUserButtonClickedSignal(QString)),this,SLOT(deleteUserButtonClicked(QString)));*/
}

void GuiController::userDeleted(QString name) {
    //do things with user delete signal
}

//All back Events to HomePage
void GuiController::callHomePage() {
    home->show();
    task->hide();
    clean->hide();
    events->hide();
    rooms->hide();
    users->hide();
}

void GuiController::callCalendar() {
    events->show();
    home->hide();
}

void GuiController::callCleanPlan(){
    clean->show();
    home->hide();
}

//CleaningPage Events
void GuiController::callTask(){
    task->show();
    clean->hide();
}

void GuiController::callLogOut() {
    main->show();
    home->hide();
}

//SetUpTask Events
void GuiController::newTaskSet(){
  if(task->getTaskNameInput() == "Error") {
      //Exception
      return;
  }else{
      //databank connection
      //con->addTask(task->getTaskNameInput(), task->getSelectedRoomTask(), task->getSelectedTaskFrequency());
  }

  //update task list in Gui
  //task->appear(con->getTaskName(), con->getRoomTask(), con->getTaskFrequency(), con->getSize());
}

void GuiController::taskDeleted(QString task){
    // delete task from Databank
    //con->deleteTask(task.toStdString());

    //task->appear(con->getTaskName(), con->getRoomTask(), con->getTaskFrequency(), con->getSize());
}
