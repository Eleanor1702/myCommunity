#include "userInterface/lib/TaskListItem.h"

TaskListItem::TaskListItem(QString taskName, QString taskRoom, QString taskFrequency, QWidget *parent) : QFrame(parent){
  this->newTaskLayout = new QHBoxLayout();
  this->task = new QLabel(taskName + " - " + taskRoom + " - " + taskFrequency);
  this->deleteButton = new QPushButton(QString::fromUtf8("Löschen"));
  name = taskName;

  setItemStyle();

  //events
  QObject::connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteTask()));
}

void TaskListItem::setItemStyle() {
  //Frame Design
  this->setFixedHeight(50);
  this->setStyleSheet("border: 1px solid #aaa; border-radius: 5px;");

  //Layout Design
  this->setLayout(this->newTaskLayout);
  this->newTaskLayout->addWidget(this->task);
  this->newTaskLayout->addWidget(this->deleteButton);

  //Task Design
  this->task->setFixedSize(550, 30);
  this->task->setStyleSheet("text-align: center; font-size: 20px; border: 0px; color: #aaa;");

  //Button Design
  this->deleteButton->setFixedHeight(30);
  this->deleteButton->setStyleSheet(".QPushButton{border: 1px solid red;"
                                    "border-radius: 5px; background-color: red;"
                                    " color: white; font-weight: bold;}");
}

void TaskListItem::deleteTask() {
  emit deleteTaskSignal(name);
}
