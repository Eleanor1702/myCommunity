#include "userInterface/lib/SignIn.h"

SignIn::SignIn(QWidget *parent) : QWidget (parent){
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

  imageRow = new QBoxLayout(QBoxLayout::RightToLeft);
  pic = new QPixmap("/home/eleanor/Privat/studium/SWP/myCommunityGitlab/myCommunity/Code/media/avatar.png");
  picLabel = new QLabel(this);

  nameRow = new QBoxLayout(QBoxLayout::LeftToRight);
  nameLabel = new QLabel("Name:");
  giveNameEdit = new QLineEdit();

  passwordRow = new QBoxLayout(QBoxLayout::LeftToRight);
  passwordLabel = new QLabel("Passwort:");
  givePasswordEdit = new QLineEdit();

  buttonsRow = new QBoxLayout(QBoxLayout::RightToLeft);
  backButton = new QPushButton(QString::fromUtf8("zurück"));
  logInButton = new QPushButton("Log In");

  this->setMainWindowDesign();
  this->setMainLayoutDesign();

  //Events
}

void SignIn::setMainWindowDesign() {
  this->setFixedSize(700, 500);
  this->setStyleSheet("background-color: white;");
  this->setWindowTitle(QString::fromUtf8("Anmelden"));

  //mainLayout->addLayout(this->mainLabelRow);
  mainLayout->addLayout(this->imageRow);
  mainLayout->addLayout(this->nameRow);
  mainLayout->addLayout(this->passwordRow);
  mainLayout->addLayout(this->buttonsRow);
  this->setLayout(mainLayout);
}

void SignIn::setMainLayoutDesign() {
  //this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
  //this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
  //                               "font-weight: bold;");

  this->imageRow->addWidget(this->picLabel, 0, Qt::AlignVCenter);
  scaled = this->pic->scaled(130, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation);
  this->picLabel->setPixmap(scaled);
  this->picLabel->setFixedSize(200, 200);
  this->picLabel->setAlignment(Qt::AlignCenter);

  this->nameRow->addWidget(nameLabel, 0 , Qt::AlignCenter);
  this->nameRow->addWidget(giveNameEdit, 0, Qt::AlignCenter);
  this->giveNameEdit->setMaxLength(18);
  this->giveNameEdit->setFixedWidth(300);

  this->passwordRow->addWidget(passwordLabel, 0, Qt::AlignCenter);
  this->passwordRow->addWidget(givePasswordEdit, 0 , Qt::AlignCenter);
  this->givePasswordEdit->setEchoMode(QLineEdit::Password);
  this->givePasswordEdit->setMaxLength(4);
  this->givePasswordEdit->setFixedWidth(300);

  this->buttonsRow->addWidget(backButton);
  backButton->setFixedSize(200, 50);
  backButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                           "border-radius: 5px; background-color: #3399ff; "
                           "color: white;}");


  this->buttonsRow->addWidget(logInButton);
  logInButton->setFixedSize(200, 50);
  logInButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                            "border-radius: 5px; background-color: #00b300; "
                            "color: white;}");
}

/*
 void SignUp::saveButtonClicked(){

  //proceed only with a room name

  QString userName = giveNameEdit->text();
  if(userName.size() == 0 || userName[0] == ' '){
      return;
  }

  QString userPassword = givePasswordEdit->text();
  if(userPassword.size() == 0 || userPassword[0] == ' '){
      return;
  }

  UserList *newUser = new UserList(userName);

  this->scrollLayout->addWidget(newUser);

  this->giveNameEdit->clear();
  this->givePasswordEdit->clear();
}

 void SignUp::backButtonClicked(){

  //proceed only with a room name

  QString userName = giveNameEdit->text();
  if(userName.size() == 0 || userName[0] == ' '){
      return;
  }

  QString userPassword = givePasswordEdit->text();
  if(userPassword.size() == 0 || userPassword[0] == ' '){
      return;
  }

  UserList *newUser = new UserList(userName);

  this->scrollLayout->addWidget(newUser);

  this->giveNameEdit->clear();
  this->givePasswordEdit->clear();
}
*/

