#include "userInterface/lib/StartPage.h"

//calling the constructor, calls the parent constructor too
//in this case QWidget
StartPage::StartPage(QWidget *parent) : QWidget(parent) {

  //declarations of window contents
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainLabel = new QLabel("myCommunity");

  ButtonsRow = new QBoxLayout(QBoxLayout::TopToBottom);
  signUpButton = new QPushButton (QString::fromUtf8("Sign Up"), this);
  signInButton = new QPushButton ("Sign In", this);

  this->setMainWindowDesign();
  this->setMainLayoutDesign();

}

void StartPage::setMainWindowDesign() {
  this->setFixedSize(700, 500);
  this->setStyleSheet("background-color: white;");
  this->setWindowTitle(QString::fromUtf8("myCommunity"));

  this->mainLayout->addLayout(mainLabelRow);
  this->mainLayout->addLayout(ButtonsRow);
  this->setLayout(mainLayout);
}

void StartPage::setMainLayoutDesign() {

  this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
  this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 50px;"
                                 "font-weight: bold;");

  this->ButtonsRow->addWidget(signUpButton, 0, Qt::AlignCenter);
  this->signUpButton->setFixedSize(200, 50);
  this->signUpButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                           "border-radius: 5px; background-color: #3399ff; "
                           "color: white;}");


  this->ButtonsRow->addWidget(signInButton, 0 , Qt::AlignCenter);
  this->signInButton->setFixedSize(200, 50);
  this->signInButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                            "border-radius: 5px; background-color: #00b300; "
                            "color: white;}");

}




