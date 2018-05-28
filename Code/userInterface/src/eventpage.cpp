#include "userInterface/lib/eventpage.h"
#include <QtWidgets>

EventPage::EventPage(QWidget *parent) : QWidget(parent) {
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Kalender");

    calendarRow = new QBoxLayout(QBoxLayout::TopToBottom);
    calendar = new QCalendarWidget;

    ButtonRow = new QBoxLayout(QBoxLayout::LeftToRight);
    saveEventButton = new QPushButton("Speichern");
    addEventButton = new QPushButton("Termin hinzufügen");


    this->setMainWindowDesign();
    this->setMainLayoutDesign();
}

void EventPage::setMainWindowDesign() {
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white");
    this->setWindowTitle(QString::fromUtf8("Kalender"));

    mainLayout->addLayout(this->mainLabelRow);
    mainLayout->addLayout(this->calendarRow);
    mainLayout->addLayout(this->ButtonRow);


    this->setLayout(mainLayout);
}

void EventPage::setMainLayoutDesign() {
    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 30px; color: #aaa;");

    this->calendarRow->addWidget(this->calendar, 1, Qt::AlignCenter);
    this->calendar->showToday();
    this->calendar->setStyleSheet("font-family: URW Bookman L; font-size: 23px;");

    this->ButtonRow->addWidget(addEventButton, 2, Qt::AlignLeft);
    this->addEventButton->setFixedSize(200, 50);
    this->addEventButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff;"
                                        "border-radius: 5px; background-color: #3399ff;"
                                        "color:white; font-weight: bold;}");


    this->ButtonRow->addWidget(saveEventButton, 2, Qt::AlignRight);
    this->saveEventButton->setFixedSize(200, 50);
    this->saveEventButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                                    "border-radius: 5px; background-color: #00b300; "
                                    "color: white; font-weight: bold;}");
}
