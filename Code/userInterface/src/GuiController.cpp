#include "userInterface/lib/GuiController.h"

GuiController::GuiController(QWidget *parent) : QWidget(parent) {
  this->main = new StartPage();
  this->up = new SignUp();
  this->in = new SignIn();
  this->home = new HomePage();

  //Events
  QObject::connect(main->signInButton,SIGNAL(clicked()),this,SLOT(signInButtonClicked()));
  QObject::connect(main->signUpButton,SIGNAL(clicked()),this,SLOT(signUpButtonClicked()));

  QObject::connect(in->backButton,SIGNAL(clicked()),this,SLOT(backButtonClicked()));
  QObject::connect(in->logInButton,SIGNAL(clicked()),this,SLOT(logInButtonClicked()));

  QObject::connect(up->backButton,SIGNAL(clicked()),this,SLOT(backButtonClicked()));
  QObject::connect(up->saveButton,SIGNAL(clicked()),this, SLOT(speichernButtonClicked()));

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
  in->show();
  up->hide();
}

void GuiController::logInButtonClicked() {
  home->show();
  in->hide();
}