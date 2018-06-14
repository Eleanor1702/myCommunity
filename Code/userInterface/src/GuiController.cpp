#include "userInterface/lib/GuiController.h"

GuiController* GuiController::instance = NULL;

void GuiController::startApplication(Controller* con) {
    getInstance(con);
}

GuiController* GuiController::getInstance(Controller* con){
    if(instance == NULL){
        instance = new GuiController(con);
    }
    return instance;
}

GuiController::GuiController(Controller* con) : QWidget() {
    this->main = new StartPage();
    this->up = new SignUp();
    this->in = new SignIn();

    this->home = new HomePage();
    this->rooms = new SetUpRooms();
    this->users = new SetUpUsers();
    this->events = new SetUpEvents();
    this->pwpage = new changePwPage();
    this->clean = new CleaningPage();
    this->task = new SetUpTasks();

    this->con = con;

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
    connect(users, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));
    connect(users, SIGNAL(deleteUserSignal(QString)), this, SLOT(userDeleted(QString)));    //n
    connect(users, SIGNAL(pwpageSignal()), this, SLOT(callPwPage()));

    //PwPage Events
    connect(pwpage, SIGNAL(changepwSignal()), this, SLOT(changePW()));
    connect(pwpage, SIGNAL(setupusersSignal()), this, SLOT(callUserSettingsFromPwPage()));


    //SetUpEvents Events
    connect(events, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));
    connect(events, SIGNAL(setNewEventSignal()), this, SLOT(newEventSet()));
    connect(events, SIGNAL(appearCalledSignal()), this,SLOT(eventAppeared()));
    connect(events, SIGNAL(deleteEventSignal(QString, QString, QString, QString)), this, SLOT(eventDeleted(QString, QString, QString, QString)));
    //connect event edit

    //CleaningPage Events
    connect(clean, SIGNAL(taskCallSignal()), this, SLOT(callTask()));
    connect(clean, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));

    //SetUpTask Events
    connect(task, SIGNAL(newTaskSignal()), this, SLOT(newTaskSet()));
    connect(task, SIGNAL(deleteTaskSignal(QString, QString)), this, SLOT(taskDeleted(QString, QString)));
    connect(task, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));

    //show main page
    this->main->show();
}

//StartPage Events
void GuiController::callSignUp(){
    up->appear();
    main->hide();
}

//SignUp Event
void GuiController::signUpNewUser(std::string name, int password) {
    if( !(con->searchNameResident(name)) ) {
        con->addResident(name, password);

        in->appear();
        up->hide();
    }else{
        up->usernameExist();
    }
}

void GuiController::callSignIn(){
    in->appear();
    main->hide();
}

//SignIn Event
void GuiController::logInUser(std::string name, int password) {
    if(con->searchResident(name, password)) {
        con->setCurrentUser(name);              //Set Current User to logged in user
        home->show();
        in->hide();
    }else{
        in->falseData();
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
    rooms->appear(con->getRoomNames(), con->getRoomArts(), con->getRoomlistSize());
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
    rooms->appear(con->getRoomNames(), con->getRoomArts(), con->getRoomlistSize());
}

void GuiController::roomDeleted(QString room) {
    // delete room from Databank
    con->deleteRoom(room.toStdString());
    rooms->appear(con->getRoomNames(), con->getRoomArts(), con->getRoomlistSize());
}

void GuiController::callUserSettings() {
    users->appear(con->getUserNames(), con->getUserlistSize(), con->getCurrentUser());
    home->hide();
}

void GuiController::callUserSettingsFromPwPage(){
    users->appear(con->getUserNames(), con->getUserlistSize(), con->getCurrentUser());
    pwpage->giveOldpwEdit->clear();
    pwpage->giveNewpwEdit->clear();
    pwpage->hide();
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
    // delete user from Databank
    con->deleteResident(name.toStdString());
   users->hide();
   main->show();
    //users->appear(con->getUserNames(), con->getRoomlistSize(), con->getCurrentUser());
}

void GuiController::callPwPage(){
    users->hide();
    pwpage->show();
}

//PWPage Events

void GuiController::changePW(){
    if(con->rsExpert->verifyLogInData(con->rsExpert->getCurrentUser(), std::stoi(pwpage->getOldPwInput()))){    //old pw = pw
        con->editResident(con->rsExpert->getCurrentUser(), std::stoi(pwpage->getNewPwInput()));
        users->show();
        pwpage->giveOldpwEdit->clear();
        pwpage->giveNewpwEdit->clear();
        pwpage->hide();

    }
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

//SetUpEvents Events
void GuiController::newEventSet(){
    if(events->getEventDescriptionInput() == "Error"){
        //Exception
        return;
    } else {
        //database connection
        con->addEvent(events->getEventTimeInput(), events->getEventDateInput(),
                      events->getEventDescriptionInput(), events->getEventUserInput());
    }
    //udate eventlist in Gui
    events->appear(con->getEventTime(events->getEventUserInput(), events->getEventDateInput()),
                   con->getEventDate(events->getEventUserInput(), events->getEventDateInput()),
                   con->getEventDescription(events->getEventUserInput(), events->getEventDateInput()),
                   con->getEventUser(events->getEventUserInput(), events->getEventDateInput()),
                   con->getSizeEvent(events->getEventUserInput(), events->getEventDateInput()));
}

void GuiController::eventAppeared(){
    events->appearAll(con->getEventTime(events->getEventUserInput(), events->getEventDateInput()),
                   con->getEventDate(events->getEventUserInput(), events->getEventDateInput()),
                   con->getEventDescription(events->getEventUserInput(), events->getEventDateInput()),
                   con->getEventUser(events->getEventUserInput(), events->getEventDateInput()),
                   con->getSizeEvent(events->getEventUserInput(), events->getEventDateInput()));
}

void GuiController::eventDeleted(QString time, QString date, QString description, QString user){
    //delete event from database
    con->deleteEvent(time.toStdString(), date.toStdString(), description.toStdString(), user.toStdString());

    events->appear(con->getEventTime(events->getEventUserInput(), events->getEventDateInput()),
                   con->getEventDate(events->getEventUserInput(), events->getEventDateInput()),
                   con->getEventDescription(events->getEventUserInput(), events->getEventDateInput()),
                   con->getEventUser(events->getEventUserInput(), events->getEventDateInput()),
                   con->getSizeEvent(events->getEventUserInput(), events->getEventDateInput()));
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
    task->appear(con->getTaskName(), con->getTaskRoom(), con->getTaskFrequency(), con->getTasklistSize());
    task->setRoomCombobox(con->getRoomNames());
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
      con->addTask(task->getTaskNameInput(), task->getSelectedRoomTask(), task->getSelectedTaskFrequency());
  }
  //update task list in Gui
  task->appear(con->getTaskName(), con->getTaskRoom(), con->getTaskFrequency(), con->getTasklistSize());
}

void GuiController::taskDeleted(QString taskname, QString room){
    // delete task from Databank
    con->deleteTask(taskname.toStdString(), room.toStdString());
    task->appear(con->getTaskName(), con->getTaskRoom(), con->getTaskFrequency(), con->getTasklistSize());
}

