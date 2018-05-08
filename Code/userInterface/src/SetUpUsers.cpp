#include "userInterface/lib/SetUpUsers.h"

//calling the constructor, calls the parent constructor too
//in this case QWidget
SetUpUsers::SetUpUsers(QWidget *parent) : QWidget(parent){

  //declarations of window contents
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainLabel = new QLabel("Let's add your Residents..");

  scrollAreaRow = new QBoxLayout(QBoxLayout::LeftToRight);
  scrollArea = new QScrollArea(this);
  scrollWidget = new QWidget(this);
  scrollLayout = new QBoxLayout(QBoxLayout::TopToBottom, this->scrollWidget);

  addUsersRow = new QBoxLayout(QBoxLayout::LeftToRight);

  mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
  nameLabel = new QLabel("Name:");
  passwordLabel = new QLabel("Passwort:");
  giveNameEdit = new QLineEdit();
  givePasswordEdit = new QLineEdit();
  addButton = new QPushButton (QString::fromUtf8("Bewohner hinzufügen"), this);
  saveButton = new QPushButton ("Speichern");

  this->setMainWindowDesign();
  this->setMainLayoutDesign();

}

void SetUpUsers::setMainWindowDesign() {
    this->setFixedSize(700, 500);
    this->setStyleSheet("background-color: black;");
    this->setWindowTitle(QString::fromUtf8("Bewohner Verwalten"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(scrollAreaRow);
    mainLayout->addLayout(addUsersRow);
    mainLayout->addLayout(mainButtonsRow);
    this->setLayout(mainLayout);
}

void SetUpUsers::setMainLayoutDesign() {

    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 5px; color: #aaa;");

    this->scrollAreaRow->addWidget(scrollArea);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollWidget->setLayout(this->scrollLayout);
    this->scrollLayout->setAlignment(Qt::AlignTop);
    this->scrollArea->setWidgetResizable(true);


    this->addUsersRow->addWidget(nameLabel);
    this->addUsersRow->addWidget(giveNameEdit);

    this->addUsersRow->addWidget(passwordLabel);
    this->addUsersRow->addWidget(givePasswordEdit);
    this->givePasswordEdit->setEchoMode(QLineEdit::Password);
    this->giveNameEdit->setMaxLength(18);
    this->givePasswordEdit->setMaxLength(4);
    this->nameLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    this->passwordLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    this->givePasswordEdit->setStyleSheet("color: white;");
    this->giveNameEdit->setStyleSheet("color: white;");


    this->mainButtonsRow->addWidget(addButton);
    addButton->setFixedSize(200, 50);
    addButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                             "border-radius: 5px; background-color: #3399ff; "
                             "color: white; font-weight: bold;}");


    this->mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(200, 50);
    saveButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                              "border-radius: 5px; background-color: #00b300; "
                              "color: white; font-weight: bold;}");

}
