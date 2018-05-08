#include "userInterface/lib/GuiController.h"

GuiController::GuiController(QWidget *parent) : QWidget(parent) {
  this->main = new StartPage();
  this->up = new SignUp();
  this->in = new SignIn();
  this->home = new HomePage();

  this->con = new Controller();

  //Events
  QObject::connect(main->signInButton,SIGNAL(clicked()),this,SLOT(signInButtonClicked()));
  QObject::connect(main->signUpButton,SIGNAL(clicked()),this,SLOT(signUpButtonClicked()));

  QObject::connect(in->backButton,SIGNAL(clicked()),this,SLOT(backButtonClicked()));
  QObject::connect(in->logInButton,SIGNAL(clicked()),this,SLOT(logInButtonClicked()));

  QObject::connect(up->backButton,SIGNAL(clicked()),this,SLOT(backButtonClicked()));
  QObject::connect(up->saveButton,SIGNAL(clicked()),this, SLOT(speichernButtonClicked()));

  QObject::connect(home->logOut,SIGNAL(clicked()),this,SLOT(signOutButtonClicked()));

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
  main->show();
  up->close();
  in->close();
}

void GuiController::speichernButtonClicked() {
  QString na = up->giveNameEdit->text();
  QString pa = up->givePasswordEdit->text();

  std::string name = na.toUtf8().constData();
  int password = pa.toInt();

  con->addResident(name, password);

  up->giveNameEdit->clear();
  up->givePasswordEdit->clear();

  in->show();
  up->hide();
}

void GuiController::logInButtonClicked() {
  QString na = in->giveNameEdit->text();
  QString pa = in->givePasswordEdit->text();

  std::string name = na.toUtf8().constData();
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
