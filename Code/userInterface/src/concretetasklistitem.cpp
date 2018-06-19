#include "userInterface/lib/concretetasklistitem.h"

ConcreteTaskListItem::ConcreteTaskListItem(QString cTaskWeek, QString cTask, QString cTaskRes, QString cTaskRoom, QWidget *parent) : QFrame(parent)
{
    this->newConcreteTaskLayout = new QHBoxLayout();
    this->concreteTaskLabel = new QLabel ("Woche: " + cTaskWeek + "\n" + cTask + cTaskRoom + "\n" + cTaskRes);
    this->editButton = new QPushButton(QString::fromUtf8("Bearbeiten"));
    this->deleteButton = new QPushButton(QString::fromUtf8("Löschen"));

    week = cTaskWeek;
    task = cTask;
    res = cTaskRes;
    room = cTaskRoom;

    setItemStyle();

    QObject::connect(editButton,SIGNAL(clicked()),this,SLOT(editConcreteTask()));
    QObject::connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteConcreteTask()));
}

void ConcreteTaskListItem::setItemStyle(){
    this->setFixedHeight(65);
    this->setFixedWidth(300);
    this->setStyleSheet("border: 0.5px solid #aaa; border-radius: 2px");

    this->setLayout(this->newConcreteTaskLayout);
    this->newConcreteTaskLayout->addWidget(this->concreteTaskLabel);
    this->newConcreteTaskLayout->addWidget(this->editButton);
    this->newConcreteTaskLayout->addWidget(this->deleteButton);

    this->concreteTaskLabel->setFixedSize(50, 50);;
    this->concreteTaskLabel->setStyleSheet("text-align: top; font-size: 10px; border: 0px; color: #aaa;");
    this->editButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff;"
                                    "border-radius: 5px; background-color: #3399ff;"
                                    " color: white; font-weight: bold}");

    this->deleteButton->setStyleSheet(".QPushButton{border: 1px solid red;"
                                      "border-radius: 5px; background-color: red;"
                                      " color: white; font-weight: bold}");

}

void ConcreteTaskListItem::editConcreteTask(){
    emit editConcreteTaskSignal(week, task, res);
}

void ConcreteTaskListItem::deleteConcreteTask(){
    emit deleteConcreteTaskSignal(week, task, res, room);
}

