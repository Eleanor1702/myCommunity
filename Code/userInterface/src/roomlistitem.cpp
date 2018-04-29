#include "userInterface/lib/roomlistitem.h"

RoomListItem::RoomListItem(QString roomName, QWidget *parent) : QFrame(parent){
  this->newRoomLayout = new QHBoxLayout();
  this->room = new QLabel(roomName);
  this->deleteButton = new QPushButton(QString::fromUtf8("Löschen"));

  setItemStyle();

  //events
  QObject::connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteButtonClicked()));

}

void RoomListItem::setItemStyle() {
  //Frame Design
  this->setFixedHeight(50);
  this->setStyleSheet(".QFrame{border: 1px solid #aaa; border-radius: 5px;}");

  //Layout Design
  this->setLayout(this->newRoomLayout);
  this->newRoomLayout->addWidget(this->room);
  this->newRoomLayout->addWidget(this->deleteButton);

  //Room Design
  this->room->setFixedSize(550, 30);
  this->room->setStyleSheet("text-align: center; font-size: 20px;");

  //Button Design
  this->deleteButton->setFixedHeight(30);
  this->deleteButton->setStyleSheet(".QPushButton{border: 1px solid red;"
                                    "border-radius: 5px; background-color: red;"
                                    " color: white;}");
}

void RoomListItem::deleteButtonClicked() {
  this->close();
}
