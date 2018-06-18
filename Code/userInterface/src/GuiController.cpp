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
    this->events = new EventPage();
    this->pwpage = new changePwPage();
    this->clean = new CleaningPage();
    this->task = new SetUpTasks();
    this->plan = new SetUpCleaningPlan();
    this->shop = new SetUpShoppinglist();

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
    connect(home, SIGNAL(shoppingListCallSignal()), this, SLOT(callShoppingList()));

    //SetUpRoomsEvents
    connect(rooms, SIGNAL(setNewRoomSignal()), this, SLOT(newRoomSet()));
    connect(rooms, SIGNAL(deleteRoomSignal(QString)), this, SLOT(roomDeleted(QString)));
    connect(rooms, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));

    //SetUpUsers Events
    connect(users, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));
    connect(users, SIGNAL(deleteUserSignal(QString)), this, SLOT(userDeleted(QString)));
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
    connect(clean, SIGNAL(createPlanSignal()),this,SLOT(callCreatePlan()));

    //SetUpTask Events
    connect(task, SIGNAL(newTaskSignal()), this, SLOT(newTaskSet()));
    connect(task, SIGNAL(deleteTaskSignal(QString, QString)), this, SLOT(taskDeleted(QString, QString)));
    connect(task, SIGNAL(CleanPlanCallSignal()), this, SLOT(callCleanPlan()));

    //SetUpPlan Events
    connect(plan, SIGNAL(CleanPlanCallSignal()), this,SLOT(callCleanPlan()));

    //SetUpShoppinglist Events
    connect(shop, SIGNAL(setNewItemSignal()), this, SLOT(newItemSet()));
    connect(shop, SIGNAL(deleteItemSignal(QString)), this, SLOT(ItemDeleted(QString)));
    connect(shop, SIGNAL(homePageCallSignal()), this, SLOT(callHomePage()));

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
    //Show SetUpRooms and update room list
    rooms->appear(con->getRoomNames(), con->getRoomArts(), con->getRoomlistSize());
    home->hide();
}

void GuiController::callUserSettings() {
    //Show SetUpUsers and update user list
    users->appear(con->getUserNames(), con->getUserlistSize(), con->getCurrentUser());
    home->hide();
}

void GuiController::callCalendar() {
    //Show Calendar
    events->show();
    home->hide();
}

void GuiController::callCleanPlan(){
    //Show cleaningplan
    clean->show();
    home->hide();
    task->hide();
    plan->hide();
}

void GuiController::callShoppingList() {
    //Show shoppinglist and update item list
    shop->appear(con->getItemNames(), con->getItemNumbers(), con->getItemlistSize());
    home->hide();
}

void GuiController::callLogOut() {
    //close homepage and show startpage
    main->show();
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

//SetUpUser Events
void GuiController::userDeleted(QString name) {
    //delete user from Databank
   con->deleteResident(name.toStdString());
   users->hide();
   main->show();
}

void GuiController::callPwPage(){
    pwpage->appear();
}

void GuiController::callUserSettingsFromPwPage(){
    users->appear(con->getUserNames(), con->getUserlistSize(), con->getCurrentUser());
    pwpage->giveOldpwEdit->clear();
    pwpage->giveNewpwEdit->clear();
    pwpage->hide();
}

//PWPage Events
void GuiController::changePW(){
    //change password of current user
    if(con->searchResident(con->getCurrentUser(), std::stoi(pwpage->getOldPwInput()))){    //old pw = pw
        con->editResident(con->rsExpert->getCurrentUser(), std::stoi(pwpage->getNewPwInput()));
        users->show();
        pwpage->clearContent();
        pwpage->hide();

    }
    else{
        pwpage->falseData();
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
    pwpage->hide();
    shop->hide();
}

//SetUpEvents Events

//add new event to calendar
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
    std::string user;
    if(events->getEventUserInput() == "privat") {
        user = con->getCurrentUser();
    }
    else user = "gemeinschaftlich";

    events->appear(con->getEventTime(user, events->getEventDateInput()),
                   con->getEventDate(user, events->getEventDateInput()),
                   con->getEventDescription(user, events->getEventDateInput()),
                   user, con->getSizeEvent(user, events->getEventDateInput()));
}

void GuiController::eventAppeared(){
    //show all events for a specific date
    std::string user = con->getCurrentUser();
    //get private events
    events->appear(con->getEventTime(user, events->getEventDateInput()),
                   con->getEventDate(user, events->getEventDateInput()),
                   con->getEventDescription(user, events->getEventDateInput()),
                   user,
                   con->getSizeEvent(user, events->getEventDateInput()));
    //get community events
    user = "gemeinschaftlich";
    events->appear(con->getEventTime(user, events->getEventDateInput()),
                   con->getEventDate(user, events->getEventDateInput()),
                   con->getEventDescription(user, events->getEventDateInput()),
                   user,
                   con->getSizeEvent(user, events->getEventDateInput()));


}

void GuiController::eventDeleted(QString time, QString date, QString description, QString username){
    //delete event from database
    con->deleteEvent(time.toStdString(), date.toStdString(), description.toStdString(), username.toStdString());
    std::string user = username.toStdString();
    events->appear(con->getEventTime(user, events->getEventDateInput()),
                   con->getEventDate(user, events->getEventDateInput()),
                   con->getEventDescription(user, events->getEventDateInput()),
                   user,
                   con->getSizeEvent(user, events->getEventDateInput()));
}

//CleaningPage Events
void GuiController::callTask(){
    task->appear(con->getTaskName(), con->getTaskRoom(), con->getTaskFrequency(), con->getTasklistSize());
    task->setRoomCombobox(con->getRoomNames());
    clean->hide();
}

void GuiController::callCreatePlan(){
    plan->show();
    plan->setTaskCombobox(con->getTaskName(), con->getTaskRoom());
    plan->setResidentCombobox(con->getUserNames());
    clean->hide();
}

//SetUpTask Events

//new cleaning task
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

//SetUpShoppinglist Events

//new item
void GuiController::newItemSet() {
    if(shop->getItemNameInput() == "Error" || shop->getItemNumberInput() == "Error") {
        return;
    }
    else {
        //database connection
        con->addItem(shop->getItemNameInput(), shop->getItemNumberInput());
    }
    //update list in Gui
    shop->appear(con->getItemNames(), con->getItemNumbers(), con->getItemlistSize());
}

//delete item
void GuiController::ItemDeleted(QString name) {
    //delete item from database
    con->deleteItem(name.toStdString());
    //update gui
    shop->appear(con->getItemNames(), con->getItemNumbers(), con->getItemlistSize());
}

