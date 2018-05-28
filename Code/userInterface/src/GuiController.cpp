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

    //StartPage Events
    connect(main, SIGNAL(signUpCallSignal()), this, SLOT(callSignUp()));
    connect(main, SIGNAL(signInCallSignal()), this, SLOT(callSignIn()));

    //SignUp Events
    connect(up, SIGNAL(startPageCallSignal()), this, SLOT(callStartPage()));
    connect(up, SIGNAL(newUserSignUpSignal(std::string name, int password)), this, SLOT(signUpNewUser(std::string,int)));

    //SignIn Events
    connect(in, SIGNAL(startPageCallSignal()), this, SLOT(callStartPage()));
    connect(in, SIGNAL(userLogInSignal(std::string,int)), this, SLOT(logInUser(std::string name, int password)));

    //HomePage Events
    connect(home, SIGNAL(roomSettingsCallSignal()), this, SLOT(callRoomSettings()));
    connect(home, SIGNAL(userSettingsCallSignal(), this, SLOT(callUserSettings()));
    QObject::connect(home->calendarButton,SIGNAL(clicked()),this,SLOT(calendarClicked()));
    QObject::connect(home->cleanPlan,SIGNAL(clicked()),this,SLOT(cleanPlanButtonClicked()));
    QObject::connect(home->logOut,SIGNAL(clicked()),this,SLOT(logOutClicked()));

    //SetUpRoomsEvents
    connect(rooms, SIGNAL(setNewRoomSignal()), this, SLOT(newRoomSet()));
    connect(rooms->newRoom, SIGNAL(deleteRoomSignal(QString)), this, SLOT(roomDeleted(QString)));
    connect(rooms, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));

    //SetUpUsers Events
    QObject::connect(users->addButton,SIGNAL(clicked()),this,SLOT(addUserButtonClicked()));

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
void GuiController::lognInUser(std::string name, int password) {
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
    rooms->show(con->getRoomNames(), con->getRoomArts(), con->getSize());
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
    rooms->show(con->getRoomNames(), con->getRoomArts(), con->getSize());
}

void GuiController::roomDeleted(QString room) {
    // delete room from Databank
    con->deleteRoom(room.toStdString());

    rooms->show(con->getRoomNames(), con->getRoomArts(), con->getSize());
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

//SetUpRooms & SetUpUsers Event
void GuiController::callHomePage() {
    /*home->show();
    rooms->hide();
    user->hide();*/
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

