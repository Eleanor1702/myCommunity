#include "userInterface/lib/UserList.h"

UserList::UserList(QString userName, QWidget *parent) : QFrame(parent){
  this->newUserLayout = new QHBoxLayout();
  this->user = new QLabel(userName);
  this->deleteButton = new QPushButton(QString::fromUtf8("Löschen"));

  setItemStyle();

  //events
  QObject::connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteButtonClicked()));

}

void UserList::setItemStyle() {
  //Frame Design
  this->setFixedHeight(50);
  this->setStyleSheet("border: 1px solid #aaa; border-radius: 5px;");

  //Layout Design
  this->setLayout(this->newUserLayout);
  this->newUserLayout->addWidget(this->user);
  this->newUserLayout->addWidget(this->deleteButton);

  //User Design
  this->user->setFixedSize(550, 30);
  this->user->setStyleSheet("text-align: center; font-size: 20px; border: 0px;");

  //Button Design
  this->deleteButton->setFixedHeight(30);
  this->deleteButton->setStyleSheet(".QPushButton{border: 1px solid red;"
                                    "border-radius: 5px; background-color: red;"
                                    " color: white;}");
}

void UserList::deleteButtonClicked() {
  this->close();
}
