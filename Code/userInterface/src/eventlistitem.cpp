#include "userInterface/lib/eventlistitem.h"

EventListItem::EventListItem(QString eventTime, QString eventDateStr, QString eventDescription, QString eventUser, QWidget*parent) : QFrame(parent)
{

    this->newEventLayout = new QHBoxLayout();
    this->eventLabel = new QLabel (eventDateStr + "\n" + eventTime + "Uhr" + "\n" + eventDescription);
    this->editEventButton = new QPushButton(QString::fromUtf8("Bearbeiten"));
    this->deleteEventButton = new QPushButton(QString::fromUtf8("Löschen"));

    time = eventTime;
    date = eventDateStr;
    description = eventDescription;
    user = eventUser;


    setItemStyle();

//    QObject::connect(editEventButton,SIGNAL(clicked()),this,SLOT(editEvent()));
    QObject::connect(deleteEventButton,SIGNAL(clicked()),this,SLOT(deleteEvent));
}

void EventListItem::setItemStyle(){
    this->setFixedHeight(65);
    this->setFixedWidth(315);
    this->setStyleSheet("border: 0.5px solid #aaa; border-radius: 2px");

    this->setLayout(this->newEventLayout);
    this->newEventLayout->addWidget(this->eventLabel); //, 40, Qt::AlignLeft);
    this->newEventLayout->addWidget(this->editEventButton);
    this->newEventLayout->addWidget(this->deleteEventButton);

    this->eventLabel->setFixedSize(100, 50);
    this->eventLabel->setStyleSheet("text-align: top; font-size 10px; border: 0px; color: #aaa;");
    this->editEventButton->setFixedHeight(40);
    this->editEventButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff;"
                                         "border-radius: 5px; background-color: #3399ff;"
                                         " color: white; font-weight: bold;}");

    this->deleteEventButton->setFixedHeight(40);
    this->deleteEventButton->setStyleSheet(".QPushButton{border: 1px solid red;"
                                           "border-radius: 5px; background-color: red;"
                                           " color: white; font-weight: bold;}");
}

/*
void EventListItem::editEvent(){
    emit editEventSignal(this-> hour, this->min, this->description);
    //Name wieder in eingabezeile ??
    this->close();
}
*/

void EventListItem::deleteEvent(){
    emit deleteEventSignal(time, date, description, user);
    this->close();
}

