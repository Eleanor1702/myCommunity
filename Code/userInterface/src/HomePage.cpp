#include "userInterface/lib/HomePage.h"

HomePage::HomePage(QWidget *parent) : QWidget(parent) {
  this->mainLayout = new QBoxLayout(QBoxLayout::LeftToRight);

  this->contentColumn = new QBoxLayout(QBoxLayout::TopToBottom);

  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainLabel = new QLabel("Willkommen zu myCommunity");

  settingsButtonLayout = new QBoxLayout(QBoxLayout::TopToBottom);
  userSettingButton = new QPushButton("User Verwalten");
  roomSettingButton = new QPushButton(QString::fromUtf8("Räume Verwalten"));

  this->buttonColumn = new QBoxLayout(QBoxLayout::TopToBottom);
  this->settings = new QPushButton("WG \n Einstellungen");
  this->shoppingList = new QPushButton("Einkaufsliste");
  this->cleanPlan = new QPushButton("Putzplan");
  this->saveFormat = new QPushButton("Export");
  this->logOut = new QPushButton("Ausloggen");

  this->setMainScreenDesign();
  this->setMainLayoutDesign();

  //Event
  QObject::connect(settings,SIGNAL(clicked()),this,SLOT(callSettings()));

}

void HomePage::setMainScreenDesign(){
  this->setFixedSize(800, 600);
  this->setStyleSheet("background-color: white;");
  this->setWindowTitle("Home Page");

  this->mainLayout->addLayout(this->buttonColumn);
  this->mainLayout->addLayout(this->contentColumn);
  this->contentColumn->setAlignment(Qt::AlignCenter);
  this->buttonColumn->setAlignment(Qt::AlignLeft);
  this->setLayout(this->mainLayout);
}

void HomePage::setMainLayoutDesign(){
  this->contentColumn->addLayout(this->mainLabelRow);
  this->mainLabelRow->setAlignment(Qt::AlignTop);

  this->mainLabelRow->addWidget(mainLabel, 4, Qt::AlignCenter);
  this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                 "color: #aaa; font-weight: bold; margin-top: 5px;"
                                 "margin-right: 20px;");

  this->buttonColumn->addWidget(settings, 4, Qt::AlignTop);
  this->buttonColumn->addWidget(shoppingList, 4, Qt::AlignCenter);
  this->buttonColumn->addWidget(cleanPlan, 4, Qt::AlignCenter);
  this->buttonColumn->addWidget(saveFormat, 4, Qt::AlignCenter);
  this->buttonColumn->addWidget(logOut, 4, Qt::AlignBottom);

  this->settings->setFixedSize(100, 100);
  this->settings->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                "border-radius: 5px; background-color: #3399ff; "
                                "color: white; font-weight: bold;}");

  this->shoppingList->setFixedSize(100, 100);
  this->shoppingList->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                "border-radius: 5px; background-color: #3399ff; "
                                "color: white; font-weight: bold;}");

  this->cleanPlan->setFixedSize(100, 100);
  this->cleanPlan->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                "border-radius: 5px; background-color: #3399ff; "
                                "color: white; font-weight: bold;}");

  this->saveFormat->setFixedSize(100, 100);
  this->saveFormat->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                "border-radius: 5px; background-color: #3399ff; "
                                "color: white; font-weight: bold;}");

  this->logOut->setFixedSize(100, 100);
  this->logOut->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                "border-radius: 5px; background-color: #3399ff; "
                                "color: white; font-weight: bold;}");
}

void HomePage::callSettings() {
  this->contentColumn->addLayout(this->settingsButtonLayout);
  this->settingsButtonLayout->setAlignment(Qt::AlignBottom);

  this->settingsButtonLayout->addWidget(this->userSettingButton, 4, Qt::AlignCenter);
  this->settingsButtonLayout->addWidget(this->roomSettingButton, 4, Qt::AlignCenter);

  this->userSettingButton->setFixedSize(325, 100);
  this->userSettingButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                "border-radius: 5px; background-color: #3399ff; "
                                "color: white; font-weight: bold; margin-left: 10px;}");

  this->roomSettingButton->setFixedSize(325, 100);
  this->roomSettingButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                "border-radius: 5px; background-color: #3399ff; "
                                "color: white; font-weight: bold; margin-left: 10px;}");

}
