#include "userInterface/lib/UserList.h"

UserList::UserList(std::string currentUser,QString userName, QWidget *parent) : QFrame(parent){
  this->newUserLayout = new QHBoxLayout();
  this->user = new QLabel(userName);
  this->deleteButton = new QPushButton(QString::fromUtf8("Löschen"));

  setItemStyle(currentUser, userName);    //delete button should not exist for current user

  //events
  QObject::connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteUserButtonClicked()));

}

void UserList::setItemStyle(std::string currentUser, QString userName) {
  //Frame Design

  this->setFixedHeight(50);
  this->setStyleSheet("border: 1px solid #aaa; border-radius: 5px;");

  //Layout Design
  this->setLayout(this->newUserLayout);
  this->newUserLayout->addWidget(this->user);
    if(currentUser == userName.toUtf8().constData()){       //User should only be able to delete himself

  this->newUserLayout->addWidget(this->deleteButton);
}
  //User Design
  this->user->setFixedSize(550, 30);
  this->user->setStyleSheet("text-align: center; font-size: 20px; border: 0px; color: #aaa;");
  //Button Design

  this->deleteButton->setFixedHeight(30);
  this->deleteButton->setStyleSheet(".QPushButton{border: 1px solid red;"
                                    "border-radius: 5px; background-color: red;"
                                    " color: white; font-weight: bold;}");

}

void UserList::deleteUserButtonClicked() {
  emit deleteUserButtonClickedSignal(this->user->text());
  this->close();
}

