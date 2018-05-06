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

  //Events
 //QObject::connect(signInButton,SIGNAL(clicked()),this,SLOT(signInButtonClicked()));
 //QObject::connect(signUpButton,SIGNAL(clicked()),this,SLOT(signUpButtonClicked()));

}

void StartPage::setMainWindowDesign() {
  this->setFixedSize(700, 500);
  this->setStyleSheet("background-color: white;");
  this->setWindowTitle(QString::fromUtf8("myCommunity"));

  mainLayout->addLayout(mainLabelRow);
  mainLayout->addLayout(ButtonsRow);
  this->setLayout(mainLayout);
}

void StartPage::setMainLayoutDesign() {

  this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
  this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 50px;"
                                 "font-weight: bold;");

  this->ButtonsRow->addWidget(signUpButton, 0, Qt::AlignCenter);
  signUpButton->setFixedSize(200, 50);
  signUpButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                           "border-radius: 5px; background-color: #3399ff; "
                           "color: white;}");


  this->ButtonsRow->addWidget(signInButton, 0 , Qt::AlignCenter);
  signInButton->setFixedSize(200, 50);
  signInButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                            "border-radius: 5px; background-color: #00b300; "
                            "color: white;}");

}

void StartPage::openWindow() {
  this->show();
}




