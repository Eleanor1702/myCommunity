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

  con = this->con->getInstance();

  //Events
  //mainPage Events
  QObject::connect(main->signInButton,SIGNAL(clicked()),this,SLOT(signInButtonClicked()));
  QObject::connect(main->signUpButton,SIGNAL(clicked()),this,SLOT(signUpButtonClicked()));

  //SignIn Events
  QObject::connect(in->backButton,SIGNAL(clicked()),this,SLOT(backButtonClicked()));
  QObject::connect(in->logInButton,SIGNAL(clicked()),this,SLOT(logInButtonClicked()));

  //SignUp Events
  QObject::connect(up->backButton,SIGNAL(clicked()),this,SLOT(backButtonClicked()));
  QObject::connect(up->saveButton,SIGNAL(clicked()),this, SLOT(saveButtonClicked()));

  //HomePage Events
  QObject::connect(home->userSettingButton,SIGNAL(clicked()),this,SLOT(userSettingsButtonClicked()));
  QObject::connect(home->roomSettingButton,SIGNAL(clicked()),this,SLOT(roomSettingsButtonClicked()));
  QObject::connect(home->logOut,SIGNAL(clicked()),this,SLOT(signOutButtonClicked()));
  QObject::connect(home->calendarButton,SIGNAL(clicked()),this,SLOT(calendarButtonClicked()));

  //SetUpRoomsEvents
  QObject::connect(rooms->addButton,SIGNAL(clicked()),this,SLOT(addRoomButtonClicked()));
  QObject::connect(rooms->saveButton,SIGNAL(clicked()),this,SLOT(saveRoomButtonClicked()));

  //SetUpUsers Events
  //QObject::connect(users->addButton,SIGNAL(clicked()),this,SLOT(addUserButtonClicked()));
  QObject::connect(users->saveButton,SIGNAL(clicked()),this,SLOT(saveUserButtonClicked()));

  //EventPage Events
  QObject::connect(events->saveEventButton,SIGNAL(clicked()),this,SLOT(saveEventButtonClicked()));

  //show main page
  this->main->show();

}

void GuiController::signUpButtonClicked(){
  up->show();
  main->hide();
}

void GuiController::signInButtonClicked(){
  in->show();
  main->hide();
}

void GuiController::backButtonClicked() {
  up->giveNameEdit->clear();
  up->givePasswordEdit->clear();

  in->giveNameEdit->clear();
  in->givePasswordEdit->clear();

  in->wrongPassLabel->hide();

  main->show();
  up->close();
  in->close();
}

void GuiController::saveButtonClicked() {
  QString na = up->giveNameEdit->text();
  if(na.size() == 0 || na[0] == ' '){
      return;
  }
  QString pa = up->givePasswordEdit->text();
  if(pa.size() < 4 || pa[0] == ' '){
      return;
  }

  std::string name = na.toUtf8().constData();
  int password = pa.toInt();

  if(na == NULL || pa == NULL || pa.size() != 4){

  }else if(!(this->con->searchNameResident(name))) {
      this->con->addResident(name, password);

      up->giveNameEdit->clear();
      up->givePasswordEdit->clear();

      in->show();
      up->hide();
  }
}

void GuiController::logInButtonClicked() {
  QString na = in->giveNameEdit->text();
  QString pa = in->givePasswordEdit->text();

  //convert from QString to String
  std::string name = na.toUtf8().constData();

  //Convert to int
  int password = pa.toInt();

  if(con->searchResident(name, password)) {
      in->giveNameEdit->clear();
      in->givePasswordEdit->clear();

      in->wrongPassLabel->hide();

      home->show();
      in->hide();
  } else {
      in->wrongPassLabel->show();
  }
}

void GuiController::signOutButtonClicked() {
  main->show();
  home->hide();
}

void GuiController::userSettingsButtonClicked() {
  users->show();
  home->hide();
}

void GuiController::calendarButtonClicked() {
    events->show();
    home->hide();
}

void GuiController::roomSettingsButtonClicked() {
  rooms->show();
  home->hide();
  //Daten aus dem Room vector in Roomexpert über Controller holen & anzeigen ->function
  int size = con->GetSizeAndUpdate();
  for(int i = 0; i < size; i++) {
     QString roomName = QString::fromStdString(con->RoomGetterName(i));
     QString roomType= QString::fromStdString(con->RoomGetterArt(i));
     this->rooms->newRoom = new RoomListItem(roomName, roomType);
     this->rooms->RoomListItemList.push_back(this->rooms->newRoom);
     this->rooms->scrollLayout->addWidget(this->rooms->newRoom);
     connect(this->rooms->newRoom, SIGNAL(deleteButtonClickedSignal(QString)), this, SLOT(deleteRoomButtonClicked(QString)));
  }
}

void GuiController::addRoomButtonClicked(){
  QString roomType = rooms->chooseRoomTypeCombo->currentText();

  //proceed only with a room name
  QString roomName = rooms->giveNameEdit->text();
  if(roomName.size() == 0 || roomName[0] == ' '){
      return;
  }

  this->rooms->newRoom = new RoomListItem(roomName, roomType);
  this->rooms->RoomListItemList.push_back(this->rooms->newRoom);

  //if delete Room methode was called
  connect(this->rooms->newRoom, SIGNAL(deleteButtonClickedSignal(QString)), this, SLOT(deleteRoomButtonClicked(QString)));

  //here should contect of vector be saved in Databank
    con->addRoom(roomType.toStdString(), roomName.toStdString());

  //Viewing in Gui
  this->rooms->scrollLayout->addWidget(this->rooms->newRoom);
  this->rooms->giveNameEdit->clear();
}

void GuiController::deleteRoomButtonClicked(QString room) {
  // delete room from Databank
   con->deleteRoom(room.toStdString());
}

void GuiController::saveUserButtonClicked(){
    this->home->show();
    this->users->hide();

}
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
*/
void GuiController::deleteUserButtonClicked(QString name) {
  //do things with user delete signal

}

void GuiController::saveRoomButtonClicked() {
  this->home->show();
  this->rooms->hide();

  this->rooms->RoomListItemList.clear();
  //Remove all rooms from GUI by iterating over RoomListItemList (and using removeWidget?)


}


//EventPage Events
void GuiController::saveEventButtonClicked() {
    this->home->show();
    this->events->hide();
}

GuiController* GuiController::getInstance(QWidget *parent){
    if(instance == NULL){
        instance = new GuiController(parent);
    }
    return instance;
}

