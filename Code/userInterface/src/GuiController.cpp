#include "userInterface/lib/GuiController.h"

GuiController* GuiController::instance = NULL;

GuiController::GuiController(QWidget *parent) : QWidget(parent) {
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

  //Events
  //StartPage Events
  QObject::connect(main->signUpButton,SIGNAL(clicked()),this,SLOT(callSignUp()));
  QObject::connect(main->signInButton,SIGNAL(clicked()),this,SLOT(callSignIn()));

  //SignUp Events
  QObject::connect(up->backButton,SIGNAL(clicked()),this,SLOT(callStartPage()));
  QObject::connect(up->saveButton,SIGNAL(clicked()),this, SLOT(saveClicked()));

  //SignIn Events
  QObject::connect(in->backButton,SIGNAL(clicked()),this,SLOT(callStartPage()));
  QObject::connect(in->logInButton,SIGNAL(clicked()),this,SLOT(logInClicked()));

  //HomePage Events
  QObject::connect(home->roomSettingButton,SIGNAL(clicked()),this,SLOT(roomSettingClicked()));
  QObject::connect(home->userSettingButton,SIGNAL(clicked()),this,SLOT(userSettingClicked()));
  QObject::connect(home->logOut,SIGNAL(clicked()),this,SLOT(logOutClicked()));
  QObject::connect(home->calendarButton,SIGNAL(clicked()),this,SLOT(calendarClicked()));

  QObject::connect(home->cleanPlan,SIGNAL(clicked()),this,SLOT(cleanPlanButtonClicked()));

  //SetUpRoomsEvents
  QObject::connect(rooms->addButton,SIGNAL(clicked()),this,SLOT(addRoomButtonClicked()));
  QObject::connect(rooms->saveButton,SIGNAL(clicked()),this,SLOT(saveRoomButtonClicked()));
  //if Room is deleted
  connect(rooms->newRoom, SIGNAL(deleteButtonSignal(QString)), this, SLOT(roomDeleted(QString)));

  //SetUpUsers Events
  //QObject::connect(users->addButton,SIGNAL(clicked()),this,SLOT(addUserButtonClicked()));
  //QObject::connect(users->saveButton,SIGNAL(clicked()),this,SLOT(saveUserButtonClicked()));

  //EventPage Events
  QObject::connect(events->saveEventButton,SIGNAL(clicked()),this,SLOT(saveEventButtonClicked()));

  //CleaningPage Events
  QObject::connect(clean->setuptaskButton, SIGNAL(clicked()),this,SLOT(setupTaskButtonClicked()));
  QObject::connect(clean->backButton,SIGNAL(clicked()),this,SLOT(backToHomeButtonClicked()));

  //SetUpTask Events
  QObject::connect(task->addButton,SIGNAL(clicked()),this,SLOT(addTaskButtonClicked()));
  QObject::connect(task->saveButton,SIGNAL(clicked()),this,SLOT(saveTaskButtonClicked()));

  //show main page
  this->main->show();

}

//StartPage Events
void GuiController::callSignUp(){
    up->show();
    main->hide();
}

void GuiController::callSignIn(){
    in->show();
    main->hide();
}

//SignUp & SignIn Event
void GuiController::callStartPage() {
    up->clearContent();
    in->clearContent();

    main->show();
    up->close();
    in->close();
}

//SignUp Event
void GuiController::saveClicked() {
    //whether Input of name or password is acceptable
    if(up->getUserName() == "Error" || up->getUserPassword() == 1) {
        //Error message, maybe?
        return;
    }else{
        if(! (con->searchNameResident(up->getUserName())) ) {
            con->addResident(up->getUserName(), up->getUserPassword());

            up->clearContent();

            in->show();
            up->hide();
        }
    }
}

//SignIn Event
void GuiController::logInClicked() {
    if(con->searchResident(in->getUserName(), in->getUserPassword())) {
        in->clearContent();

        home->show();
        in->hide();
    } else {
        in->clearContent();
    }
}

//HomePage Events
void GuiController::roomSettingClicked() {
    rooms->show();
    home->hide();

    //Update Data from DataBank

}

void GuiController::userSettingClicked() {
    users->show();
    home->hide();
}

void GuiController::calendarClicked() {
    events->show();
    home->hide();
}

void GuiController::cleanPlanButtonClicked(){
    clean->show();
    home->hide();
}

void GuiController::logOutClicked() {
    main->show();
    home->hide();
}

//SetUpRooms Events
void GuiController::addRoomButtonClicked(){
    if(rooms->getRoomNameInput() == "Error") {
        //warning Label message, maybe?
        return;
    }else{
        //databank connection
        con->addRoom(rooms->getRoomTypeInput(), rooms->getRoomNameInput());
    }

    this->rooms->updateContent();
}

void GuiController::roomDeleted(QString room) {
    // delete room from Databank
    con->deleteRoom(room.toStdString());
}

void GuiController::saveRoomButtonClicked() {
  home->show();
  rooms->hide();
}

//SetUpUser Events
/*
void GuiController::addUserButtonClicked() {
  QString userName = users->giveNameEdit->text();
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

  connect(this->users->newUser,SIGNAL(deleteUserButtonClickedSignal(QString)),this,SLOT(deleteUserButtonClicked(QString)));
}

void GuiController::deleteUserButtonClicked(QString name) {
  //do things with user delete signal

}

void GuiController::saveUserButtonClicked(){
    home->show();
    users->hide();
}*/

//EventPage Events
void GuiController::saveEventButtonClicked() {
    home->show();
    events->hide();
}

//CleaningPage Events

void GuiController::setupTaskButtonClicked(){
    this->task->show();
    this->clean->hide();
}

void GuiController::backToHomeButtonClicked(){
    this->home->show();
    this->clean->hide();
}

//SetUpTask Events
void GuiController::addTaskButtonClicked(){
    QString taskFrequency = task->chooseTaskFrequencyCombo->currentText();
    QString taskRoom = task->chooseTaskRoomCombo->currentText();
    //proceed only with a task name
    QString taskName = task->giveNameEdit->text();
    if(taskName.size() == 0 || taskName[0] == ' '){
        return;
    }

    this->task->newTask = new TaskListItem(taskName, taskRoom, taskFrequency);
    this->task->TaskListItemList.push_back(this->task->newTask);

    //Datenbank
    //con->addTask(taskFrequency.toStdString(), taskRoom.toStdString(), taskName.toStdString());

    //deleteButton
    connect(this->task->newTask, SIGNAL(deleteButtonClickedSignal(QString)),this,SLOT(deleteTaskButtonClicked(QString)));

    //Viewing in Gui
    this->task->scrollLayout->addWidget(this->task->newTask);
    this->task->giveNameEdit->clear();
}


void GuiController::saveTaskButtonClicked(){
    this->clean->show();
    this->task->hide();
}


/* //delete from Database
void GuiController::deleteTaskButtonClicked(){
    con->deleteTask(task->toStdString());
}
*/


GuiController* GuiController::getInstance(QWidget *parent){
    if(instance == NULL){
        instance = new GuiController(parent);
    }
    return instance;
}

