#include "userInterface/lib/GuiController.h"

GuiController* GuiController::instance = NULL;

GuiController::GuiController(QWidget *parent) : QWidget(parent) {
  this->main = new StartPage();
  this->up = new SignUp();
  this->in = new SignIn();

  this->home = new HomePage();
  this->rooms = new SetUpRooms();
  this->users = new SetUpUsers();

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

  //SetUpRoomsEvents
  QObject::connect(rooms->addButton,SIGNAL(clicked()),this,SLOT(addRoomButtonClicked()));
  QObject::connect(rooms->saveButton,SIGNAL(clicked()),this,SLOT(saveRoomButtonClicked()));

  //SetUpUsers Events
  QObject::connect(users->addButton,SIGNAL(clicked()),this,SLOT(addUserButtonClicked()));
  QObject::connect(users->saveButton,SIGNAL(clicked()),this,SLOT(saveUserButtonClicked()));

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

  main->show();
  up->close();
  in->close();
}

void GuiController::saveButtonClicked() {
  QString na = up->giveNameEdit->text();
  QString pa = up->givePasswordEdit->text();

  std::string name = na.toUtf8().constData();
  int password = pa.toInt();

  if(!(con->searchNameResident(name))){

  con->addResident(name, password);

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

      home->show();
      in->hide();
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

void GuiController::roomSettingsButtonClicked() {
  rooms->show();
  home->hide();
}

void GuiController::addRoomButtonClicked(){
  QString roomType = rooms->chooseRoomTypeCombo->currentText();

  //proceed only with a room name

  QString roomName = rooms->giveNameEdit->text();
  if(roomName.size() == 0 || roomName[0] == ' '){
      return;
  }

  this->rooms->newRoom = new RoomListItem(roomType + " - " + roomName);
  this->rooms->RoomListItemList.push_back(this->rooms->newRoom);

  this->rooms->scrollLayout->addWidget(this->rooms->newRoom);

  this->rooms->giveNameEdit->clear();

  connect(this->rooms->newRoom, SIGNAL(deleteButtonClickedSignal(QString)), this, SLOT(deleteRoomButtonClicked(QString)));
}

void GuiController::deleteRoomButtonClicked(QString room) {
  // do things with room delete signal
}

void GuiController::saveUserButtonClicked(){
    this->home->show();
    this->users->hide();
}

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

void GuiController::saveRoomButtonClicked() {
  this->home->show();
  this->rooms->hide();
}

GuiController* GuiController::getInstance(QWidget *parent){
    if(instance == NULL){
        instance = new GuiController(parent);
    }
    return instance;
}
