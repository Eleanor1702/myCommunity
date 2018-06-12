#include "userInterface/lib/eventpage.h"
#include <QtWidgets>

EventPage::EventPage(QWidget *parent) : QWidget(parent)

{
    //declaration of window contents
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);


    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Kalender");


    calendarRow = new QGridLayout();

    ListArea = new QVBoxLayout();
    PrivLabel = new QLabel("Privat:");
    scrollArea = new QScrollArea(this);
    scrollWidget = new QWidget(this);
    scrollLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    PubLabel = new QLabel ("Gemeinschaftlich:");
    scrollAreaPub = new QScrollArea(this);
    scrolLWidgetPub = new QWidget(this);
    scrollLayoutPub = new QBoxLayout(QBoxLayout::TopToBottom);

    calendarArea = new QBoxLayout(QBoxLayout::TopToBottom);
    calendar = new QCalendarWidget;

    addEventRow = new QBoxLayout(QBoxLayout::LeftToRight);
    TimeLabel = new QLabel("Uhrzeit:");
    chooseHourCombo = new QComboBox();
    hourLabel = new QLabel(":");
    chooseMinuteCombo = new QComboBox();
    chosenTimeLabel = new QLabel("Uhr");
    eventDescriptionLabel = new QLabel ("Beschreibung:");
    giveNameEdit = new QLineEdit();
    checkLabel = new QLabel ("Mit der WG teilen:");
    checkPub = new QCheckBox();


    ButtonRow = new QBoxLayout(QBoxLayout::LeftToRight);
    addEventButton = new QPushButton("Termin hinzufügen");
    saveEventButton = new QPushButton("Zurück zum Hauptmenü");


    this->setMainWindowDesign();
    this->setMainLayoutDesign();

    QObject::connect(addEventButton,SIGNAL(clicked()),this,SLOT(setNewEventCalled()));
    QObject::connect(saveEventButton,SIGNAL(clicked()),this,SLOT(homePageCalled()));
}
void EventPage::setMainWindowDesign() {
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white");
    this->setWindowTitle(QString::fromUtf8("Kalender"));

    mainLayout->addLayout(this->mainLabelRow);
    mainLayout->addLayout(this->calendarRow);
    mainLayout->addLayout(this->addEventRow);
    mainLayout->addLayout(this->ButtonRow);
    this->setLayout(mainLayout);
}

void EventPage::setMainLayoutDesign(){
    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 30px; color: #aaa;");



    this->calendarRow->addLayout(this->ListArea, 0, 0, 450, 400, Qt::AlignLeft);
    this->calendarRow->addLayout(this->calendarArea, 0, 1, 450, 500, Qt::AlignRight);
    //set Layout Design for ListArea --> List of Private and Public Events
    this->ListArea->addWidget(this->PrivLabel, 0, Qt::AlignTop);
    this->PrivLabel->setStyleSheet("font-family: URW Bookman L; font-size: 10px;"
                                   "font-weight: bold; color: #aaa;");
    this->ListArea->addWidget(this->scrollArea, 1, Qt::AlignTop);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollArea->setWidgetResizable(true);
    this->scrollArea->setFixedWidth(350);
    this->scrollArea->setFixedHeight(175);
    this->scrollWidget->setLayout(this->scrollLayout);
    this->scrollLayout->setAlignment(Qt::AlignTop);

    this->ListArea->addWidget(this->PubLabel, 2, Qt::AlignBottom);
    this->PubLabel->setStyleSheet("font-family: URW Bookman L; font-size: 10px;"
                                  "font-weight: bold; color: #aaa;");
    this->ListArea->addWidget(this->scrollAreaPub, 3, Qt::AlignBottom);
    this->scrollAreaPub->setWidget(this->scrolLWidgetPub);
    this->scrollAreaPub->setWidgetResizable(true);
    this->scrollAreaPub->setFixedWidth(350);
    this->scrollAreaPub->setFixedHeight(175);
    this->scrolLWidgetPub->setLayout(this->scrollLayoutPub);
    this->scrollLayoutPub->setAlignment(Qt::AlignTop);

    //set Layout Design for Calendar Widget
    this->calendarArea->addWidget(this->calendar, 0, Qt::AlignRight);
    this->calendar->showToday();
    this->calendar->setFixedWidth(400);
    this->calendar->setFixedHeight(380);
    this->calendar->setStyleSheet("font-family: URW Bookman L; font-size: 17px;");
    this->fmt.setBackground(Qt::lightGray);
    this->calendar->setDateTextFormat(QDate::currentDate(), fmt);


    //set Layout Design for Time Selection
    this->addEventRow->addWidget(this->TimeLabel, 2, Qt::AlignRight);
    this->TimeLabel->setStyleSheet("color: #aaa; font-weight: bold");
    this->addEventRow->addWidget(this->chooseHourCombo, 2, Qt::AlignRight);
    this->chooseHourCombo->setFixedWidth(50);
    this->chooseHourCombo->setStyleSheet("selection-color: white; selection-background-color: #1aa3ff;"
                                         " color: black; background-color: White;");
    QStringList hour;
    for(int i = 0; i<24; i++){
        QString temp;
        if (i<=9) temp = "0" + QString::number(i);
        else temp = QString::number(i);
        hour << temp;
    }
    chooseHourCombo->addItems(hour);

    this->addEventRow->addWidget(this->hourLabel, 2, Qt::AlignCenter);
    this->hourLabel->setStyleSheet("color: #aaa; font-weight: bold");
    this->addEventRow->addWidget(this->chooseMinuteCombo, 2, Qt::AlignLeft);
    this->chooseMinuteCombo->setFixedWidth(50);
    this->chooseMinuteCombo->setStyleSheet("selection-color: white; selection-background-color: #1aa3ff;"
                                         " color: black; background-color: White;");
    QStringList minute;
    for(int i = 0; i<60; ){
        QString temp;
        if(i<10){ temp="0" + QString::number(i);}
        else{
        temp = QString::number(i);}
        minute << temp;
        i=i+5;
    }
    chooseMinuteCombo->addItems(minute);

    this->addEventRow->addWidget(this->chosenTimeLabel, 2, Qt::AlignLeft);
    this->chosenTimeLabel->setStyleSheet("color: #aaa; font-weight:bold;");

    //set Layout Design for adding event Description and CheckBox
    this->addEventRow->addWidget(this->eventDescriptionLabel, 2, Qt::AlignRight);
    this->eventDescriptionLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    this->addEventRow->addWidget(this->giveNameEdit, 2, Qt::AlignLeft);
    this->giveNameEdit->setMaxLength(18);
    this->giveNameEdit->setFixedWidth(200);
    this->addEventRow->addWidget(this->checkLabel, 2, Qt::AlignRight);
    this->checkLabel->setStyleSheet("font-family: URW Bookman L; font-size: 10px;"
                                    "font-weight: bold; color: #aaa;");
    this->addEventRow->addWidget(this->checkPub, 2, Qt::AlignLeft);



    //set Layout Design ButtonRow --> add and save Button
    this->ButtonRow->addWidget(addEventButton, 3, Qt::AlignLeft);
    this->ButtonRow->addWidget(saveEventButton, 3, Qt::AlignRight);
    this->addEventButton->setFixedSize(200, 50);
    this->addEventButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                                        "border-radius: 5px; background-color: #00b300; "
                                        "color: white; font-weight: bold;}");
    this->saveEventButton->setFixedSize(200, 50);
    this->saveEventButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                                    "border-radius: 5px; background-color: #00b300; "
                                    "color: white; font-weight: bold;}");
}


//get Input -> turn to std::string
std::string EventPage::getEventTimeInput(){
    std::string hour_str = this->chooseHourCombo->currentText().toStdString();
    std::string min_str = this->chooseMinuteCombo->currentText().toStdString();
    std::string time = hour_str + ":" + min_str;

    return time;
}

std::string EventPage::getEventDateInput(){
   QDate Date_select = calendar->selectedDate();
   QString date = Date_select.toString("yyyy.MM.dd");

   return date.toStdString();
}

std::string EventPage::getEventDescriptionInput(){
    return this->giveNameEdit->text().toStdString();
}

std::string EventPage::getEventUserInput(){
    if(this->checkPub->isChecked()){
        return "gemeinschaftlich";              //Alle User??
    } else {
        return "privat";                        //current UserName
    }
}

void EventPage::appear(std::vector<std::string> timeVec,
                       std::vector<std::string> dateVec,
                       std::vector<std::string> descrVec,
                       std::vector<std::string> userVec, int size){
    //this->show();
    if(this->getEventUserInput() == "gemeinschaftlich"){
        for(unsigned int i = 0; i<EventListItemPubList.size(); i++){
            scrollLayoutPub->removeWidget(EventListItemPubList[i]);
        }

        EventListItemPubList.clear();
        for(int i = 0; i < size; i++){
           newPubEvent = new EventListItem(QString::fromStdString(timeVec[i]),
                                                 QString::fromStdString(dateVec[i]),
                                                 QString::fromStdString(descrVec[i]),
                                                 QString::fromStdString(userVec[i]));

            connect(newPubEvent, SIGNAL(deleteEventSignal(QString, QString, QString, QString)),this,
                    SLOT(deleteEventCalled(QString, QString, QString, QString)));

            EventListItemPubList.push_back(newPubEvent);

            scrollLayoutPub->addWidget(newPubEvent);

        }
        checkPub->setChecked(false);
    }else{
        for(unsigned int i = 0; i<EventListItemPrivList.size(); i++){
            scrollLayout->removeWidget(EventListItemPrivList[i]);
        }
        EventListItemPrivList.clear();
        for(int i = 0; i < size; i++){
            newPrivEvent = new EventListItem(QString::fromStdString(timeVec[i]),
                                                 QString::fromStdString(dateVec[i]),
                                                 QString::fromStdString(descrVec[i]),
                                                 QString::fromStdString(userVec[i]));
            connect(newPrivEvent, SIGNAL(deleteEventSignal(QString, QString, QString, QString)),this,
                    SLOT(deleteEventCalled(QString, QString, QString, QString)));

            EventListItemPrivList.push_back(newPrivEvent);
            scrollLayout->addWidget(newPrivEvent);
        }  
    }
    giveNameEdit->clear();
    chooseHourCombo->setCurrentText("00");
    chooseMinuteCombo->setCurrentText("00");

}


void EventPage::setNewEventCalled(){
    emit setNewEventSignal();
}

void EventPage::homePageCalled(){
    emit homePageCallSignal();
}

void EventPage::deleteEventCalled(QString time , QString date, QString description, QString user){
    emit deleteEventSignal(time, date, description, user);
}
