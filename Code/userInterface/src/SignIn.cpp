#include "userInterface/lib/SignIn.h"

SignIn::SignIn(QWidget *parent) : QWidget (parent){
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainLabel = new QLabel("Anmelden");

  imageRow = new QBoxLayout(QBoxLayout::RightToLeft);
  pic = new QPixmap(":/avatar.png");
  picLabel = new QLabel(this);

  nameRow = new QBoxLayout(QBoxLayout::LeftToRight);
  nameLabel = new QLabel("Name:");
  giveNameEdit = new QLineEdit();

  passwordRow = new QBoxLayout(QBoxLayout::LeftToRight);
  passwordLabel = new QLabel("Passwort:");
  givePasswordEdit = new QLineEdit();

  buttonsRow = new QBoxLayout(QBoxLayout::RightToLeft);
  backButton = new QPushButton(QString::fromUtf8("Zurück"));
  logInButton = new QPushButton("Anmelden");

  this->setMainWindowDesign();
  this->setMainLayoutDesign();

}

void SignIn::setMainWindowDesign() {
  this->setFixedSize(700, 500);
  this->setStyleSheet("background-color: white;");
  this->setWindowTitle(QString::fromUtf8("Anmelden"));

  mainLayout->addLayout(this->mainLabelRow);
  mainLayout->addLayout(this->imageRow);
  mainLayout->addLayout(this->nameRow);
  mainLayout->addLayout(this->passwordRow);
  mainLayout->addLayout(this->buttonsRow);
  this->setLayout(mainLayout);
}

void SignIn::setMainLayoutDesign() {
  this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
  this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                 "font-weight: bold; margin-top: 30px;");

  this->imageRow->addWidget(this->picLabel, 0, Qt::AlignVCenter);
  scaled = this->pic->scaled(130, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation);
  this->picLabel->setPixmap(scaled);
  this->picLabel->setFixedSize(200, 200);
  this->picLabel->setAlignment(Qt::AlignCenter);

  this->nameRow->addWidget(nameLabel, 4 , Qt::AlignRight);
  this->nameRow->addWidget(giveNameEdit, 11, Qt::AlignLeft);
  this->giveNameEdit->setMaxLength(18);
  this->giveNameEdit->setFixedWidth(300);
  //left margin to keep space between label and LineEdit
  this->giveNameEdit->setStyleSheet("margin-left: 10px;");

  this->passwordRow->addWidget(passwordLabel, 4, Qt::AlignRight);
  this->passwordRow->addWidget(givePasswordEdit, 11 , Qt::AlignLeft);
  this->givePasswordEdit->setEchoMode(QLineEdit::Password);
  this->givePasswordEdit->setMaxLength(4);
  this->givePasswordEdit->setFixedWidth(300);
  //these Margins are for the design of both label and lineEdit
  //the bottom margin it to keep space between passwordRow and buttons
  //left margin to keep space between label and lineEdit
  this->givePasswordEdit->setStyleSheet("margin-left: 10px; margin-bottom: 50px;");
  this->passwordLabel->setStyleSheet("margin-bottom: 50px;");


  this->buttonsRow->addWidget(logInButton);
  logInButton->setFixedSize(200, 50);
  logInButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                            "border-radius: 5px; background-color: #00b300; "
                            "color: white;}");

  this->buttonsRow->addWidget(backButton);
  backButton->setFixedSize(200, 50);
  backButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                           "border-radius: 5px; background-color: #3399ff; "
                           "color: white;}");
}

