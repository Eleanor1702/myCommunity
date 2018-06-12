#include "userInterface/lib/UserListItem.h"

UserListItem::UserListItem(std::string currentUser, QString userName, QWidget *parent) : QFrame(parent){
    this->newUserLayout = new QHBoxLayout();
    this->user = new QLabel(userName);
    this->deleteButton = new QPushButton(QString::fromUtf8("Löschen"));

    setItemStyle(currentUser, userName);    //delete button should not exist for current user

    //events
    QObject::connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteUser()));
}

void UserListItem::setItemStyle(std::string currentUser, QString userName) {
    //Frame Design

    this->setFixedHeight(50);
    this->setStyleSheet("border: 1px solid #aaa; border-radius: 5px;");

    //Layout Design
    this->setLayout(newUserLayout);
    newUserLayout->addWidget(user);

    if(currentUser == userName.toUtf8().constData()){       //User should only be able to delete himself
        newUserLayout->addWidget(deleteButton);
    }

    //User Design
    user->setFixedSize(550, 30);
    user->setStyleSheet("text-align: center; font-size: 20px; border: 0px; color: #aaa;");

    //Button Design
    deleteButton->setFixedHeight(30);
    deleteButton->setStyleSheet(".QPushButton{border: 1px solid red;"
                                    "border-radius: 5px; background-color: red;"
                                    " color: white; font-weight: bold;}");
}

void UserListItem::deleteUser() {
    emit deleteUserSignal(this->user->text());
}

