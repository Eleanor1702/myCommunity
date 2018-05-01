#include "userInterface/lib/SignUp.h"

//calling the constructor, calls the parent constructor too
//in this case QWidget
SignUp::SignUp(QWidget *parent) : QWidget(parent){

  //declarations of window contents
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainLabel = new QLabel("Willkommen");

  imageRow = new QBoxLayout(QBoxLayout::LeftToRight);
  image = new QWidget(this);

  addUsersRow = new QBoxLayout(QBoxLayout::LeftToRight);
  nameLabel = new QLabel("Name:");
  passwordLabel = new QLabel("Passwort:");
  giveNameEdit = new QLineEdit();
  givePasswordEdit = new QLineEdit();

  mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
  backButton = new QPushButton (QString::fromUtf8("Zurück zum Startbildschirm"), this);
  saveButton = new QPushButton ("Speichern");

  this->setMainWindowDesign();
  this->setMainLayoutDesign();

  //Events
 // QObject::connect(saveButton,SIGNAL(clicked()),this,SLOT(saveButtonClicked()));
 // QObject::connect(backButton,SIGNAL(clicked()),this,SLOT(backButtonClicked()));

}

void SignUp::setMainWindowDesign() {
    this->setFixedSize(700, 500);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Registrieren"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(imageRow);
    mainLayout->addLayout(addUsersRow);
    mainLayout->addLayout(mainButtonsRow);
    this->setLayout(mainLayout);
}

void SignUp::setMainLayoutDesign() {

    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 5px;");

    this->imageRow->addWidget(image);
    this->image->setGeometry(120,120,500,500);
    this->image->setStyleSheet("background-image: url(:/media/SignUp.png)");

    this->addUsersRow->addWidget(nameLabel);
    this->addUsersRow->addWidget(giveNameEdit);
    this->giveNameEdit->setMaxLength(18);

    this->addUsersRow->addWidget(passwordLabel);
    this->addUsersRow->addWidget(givePasswordEdit);
    this->givePasswordEdit->setEchoMode(QLineEdit::Password);
    this->givePasswordEdit->setMaxLength(18);

    this->mainButtonsRow->addWidget(backButton);
    backButton->setFixedSize(200, 50);
    backButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                             "border-radius: 5px; background-color: #3399ff; "
                             "color: white;}");


    this->mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(200, 50);
    saveButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
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
