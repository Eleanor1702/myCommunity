#include "userInterface/lib/GuiController.h"

GuiController::GuiController(QWidget *parent) : QWidget(parent) {
  this->main = new StartPage();
  this->up = new SignUp();
  this->in = new SignIn();

  //Events
  QObject::connect(main->signInButton,SIGNAL(clicked()),this,SLOT(signInButtonClicked()));
  QObject::connect(main->signUpButton,SIGNAL(clicked()),this,SLOT(signUpButtonClicked()));
  QObject::connect(in->backButton,SIGNAL(clicked()),this,SLOT(backButtonClicked()));
  QObject::connect(up->backButton,SIGNAL(clicked()),this,SLOT(backButtonClicked()));

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
