#include "userInterface/lib/SetUpEvents.h"

SetUpEvents::SetUpEvents(QWidget *parent) : QWidget(parent) {
    //declaration of window contents
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Kalender");

    calendarRow = new QGridLayout();
    calendarArea = new QBoxLayout(QBoxLayout::TopToBottom);
    calendar = new QCalendarWidget;

    ListArea = new QVBoxLayout();
    PrivLabel = new QLabel("Privat:");
    scrollAreaPriv = new QScrollArea(this);
    scrollWidgetPriv = new QWidget(this);
    scrollLayoutPriv = new QBoxLayout(QBoxLayout::TopToBottom);

    PubLabel = new QLabel ("Gemeinschaftlich:");
    scrollAreaPub = new QScrollArea(this);
    scrolLWidgetPub = new QWidget(this);
    scrollLayoutPub = new QBoxLayout(QBoxLayout::TopToBottom);

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

    QObject::connect(addEventButton, SIGNAL(clicked()), this, SLOT(setNewEventCalled()));
    QObject::connect(saveEventButton, SIGNAL(clicked()), this, SLOT(homePageCalled()));
}

void SetUpEvents::setMainWindowDesign() {
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white");
    this->setWindowTitle(QString::fromUtf8("Kalender"));

    mainLayout->addLayout(this->mainLabelRow);
    mainLayout->addLayout(this->calendarRow);
    mainLayout->addLayout(this->addEventRow);
    mainLayout->addLayout(this->ButtonRow);
    this->setLayout(mainLayout);
}

void SetUpEvents::setMainLayoutDesign(){
    mainLabelRow->addWidget(mainLabel, 0, Qt::AlignCenter);
    mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                             "font-weight: bold; margin-top: 30px; color: #aaa;");


    calendarRow->addLayout(ListArea, 0, 0, 450, 400, Qt::AlignLeft);
    calendarRow->addLayout(calendarArea, 0, 1, 450, 500, Qt::AlignRight);

    //set Layout Design for Calendar Widget
    calendarArea->addWidget(calendar, 0, Qt::AlignRight);
    calendar->showToday();
    calendar->setFixedWidth(400);
    calendar->setFixedHeight(380);
    calendar->setStyleSheet("font-family: URW Bookman L; font-size: 17px;"
                            "background-color: #2E8B57;");
    fmt.setBackground(Qt::lightGray);
    calendar->setDateTextFormat(QDate::currentDate(), fmt);

    //set Layout Design for ListArea --> List of Private and Public Events
    ListArea->addWidget(PrivLabel, 0, Qt::AlignTop);
    PrivLabel->setStyleSheet("font-family: URW Bookman L; font-size: 10px;"
                             "font-weight: bold; color: #aaa;");
    ListArea->addWidget(scrollAreaPriv, 1, Qt::AlignTop);
    scrollAreaPriv->setWidget(scrollWidgetPriv);
    scrollAreaPriv->setWidgetResizable(true);
    scrollAreaPriv->setFixedWidth(350);
    scrollAreaPriv->setFixedHeight(175);
    scrollWidgetPriv->setLayout(scrollLayoutPriv);
    scrollLayoutPriv->setAlignment(Qt::AlignTop);

    ListArea->addWidget(PubLabel, 2, Qt::AlignBottom);
    PubLabel->setStyleSheet("font-family: URW Bookman L; font-size: 10px;"
                            "font-weight: bold; color: #aaa;");
    ListArea->addWidget(scrollAreaPub, 3, Qt::AlignBottom);
    scrollAreaPub->setWidget(scrolLWidgetPub);
    scrollAreaPub->setWidgetResizable(true);
    scrollAreaPub->setFixedWidth(350);
    scrollAreaPub->setFixedHeight(175);
    scrolLWidgetPub->setLayout(scrollLayoutPub);
    scrollLayoutPub->setAlignment(Qt::AlignTop);

    //set Layout Design for Time Selection
    addEventRow->addWidget(TimeLabel, 2, Qt::AlignRight);
    TimeLabel->setStyleSheet("color: #aaa; font-weight: bold");
    addEventRow->addWidget(chooseHourCombo, 2, Qt::AlignRight);
    chooseHourCombo->setFixedWidth(50);
    chooseHourCombo->setStyleSheet("selection-color: white; selection-background-color: #1aa3ff;"
                                   " color: black; background-color: White;");

    QStringList hour;

    for(int i = 0; i < 24; i++){
        QString temp;

        if (i <= 9){
            temp = "0" + QString::number(i);
        }else{
            temp = QString::number(i);
        }

        hour << temp;
    }

    chooseHourCombo->addItems(hour);

    addEventRow->addWidget(hourLabel, 2, Qt::AlignCenter);
    hourLabel->setStyleSheet("color: #aaa; font-weight: bold");
    addEventRow->addWidget(chooseMinuteCombo, 2, Qt::AlignLeft);
    chooseMinuteCombo->setFixedWidth(50);
    chooseMinuteCombo->setStyleSheet("selection-color: white; selection-background-color: #1aa3ff;"
                                     " color: black; background-color: White;");
    QStringList minute;

    for(int i = 0; i < 60; ){
        QString temp;

        if(i < 10){
            temp="0" + QString::number(i);
        }else{
            temp = QString::number(i);
        }

        minute << temp;
        i=i+5;
    }

    chooseMinuteCombo->addItems(minute);

    addEventRow->addWidget(chosenTimeLabel, 2, Qt::AlignLeft);
    chosenTimeLabel->setStyleSheet("color: #aaa; font-weight:bold;");

    //set Layout Design for adding event Description and CheckBox
    addEventRow->addWidget(eventDescriptionLabel, 2, Qt::AlignRight);
    eventDescriptionLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    addEventRow->addWidget(giveNameEdit, 2, Qt::AlignLeft);
    giveNameEdit->setMaxLength(18);
    giveNameEdit->setFixedWidth(200);
    addEventRow->addWidget(checkLabel, 2, Qt::AlignRight);
    checkLabel->setStyleSheet("font-family: URW Bookman L; font-size: 10px;"
                              "font-weight: bold; color: #aaa;");
    addEventRow->addWidget(checkPub, 2, Qt::AlignLeft);

    //set Layout Design ButtonRow --> add and save Button
    ButtonRow->addWidget(addEventButton, 3, Qt::AlignLeft);
    ButtonRow->addWidget(saveEventButton, 3, Qt::AlignRight);
    addEventButton->setFixedSize(200, 50);
    addEventButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                                  "border-radius: 5px; background-color: #00b300; "
                                  "color: white; font-weight: bold;}");
    saveEventButton->setFixedSize(200, 50);
    saveEventButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                                   "border-radius: 5px; background-color: #00b300; "
                                   "color: white; font-weight: bold;}");
}
/*
std::string SetUpEvents::getEventHourInput(){
    return this->chooseHourCombo->currentText().toStdString();
}

std::string SetUpEvents::getEventMinInput(){
    return this->chooseMinuteCombo->currentText().toStdString();
}*/

//get Input -> turn to std::string
std::string SetUpEvents::getEventTimeInput(){
    std::string hour_str = chooseHourCombo->currentText().toStdString();
    std::string min_str = chooseMinuteCombo->currentText().toStdString();
    std::string time = hour_str + ":" + min_str;

    return time;
}

std::string SetUpEvents::getEventDateInput(){
   QDate Date_select = calendar->selectedDate();
   QString Date_select_str = Date_select.toString("dd.MM.yy");

   return Date_select_str.toStdString();
}

std::string SetUpEvents::getEventDescriptionInput(){
    return this->giveNameEdit->text().toStdString();
}

std::string SetUpEvents::getEventUserInput(){
    if(checkPub->isChecked()){
        return "gemeinschaftlich";              //Alle User??
    }else{
        return "privat";                        //current UserName
    }
}

void SetUpEvents::deepDeleteLayout(QLayout *layout) {
    QLayoutItem* item;

    while((item = layout->takeAt(0))) {
        if(item->layout()){
            deepDeleteLayout(item->layout());
            delete item->layout();
        }

        if(item->widget()) {
            delete item->widget();
        }

        delete item;
    }
}

void SetUpEvents::appear(std::vector<std::string> timeVec, std::vector<std::string> dateVec,
                       std::vector<std::string> descrVec, std::vector<std::string> userVec, int size){
    //this->show();
    if(this->getEventUserInput() == "gemeinschaftlich"){
        deepDeleteLayout(scrollLayoutPub);

        for(int i = 0; i < size; i++){
            newPubEvent = new EventListItem(QString::fromStdString(timeVec[i]), QString::fromStdString(dateVec[i]),
                                            QString::fromStdString(descrVec[i]), QString::fromStdString(userVec[i]));

            connect(newPubEvent, SIGNAL(deleteEventSignal(QString, QString, QString, QString)), this,
                    SLOT(deleteEventCalled(QString, QString, QString, QString)));

            scrollLayoutPub->addWidget(newPubEvent);
        }
    }else{
        deepDeleteLayout(scrollLayoutPriv);

        for(int i = 0; i < size; i++){
            newPrivEvent = new EventListItem(QString::fromStdString(timeVec[i]), QString::fromStdString(dateVec[i]),
                                             QString::fromStdString(descrVec[i]), QString::fromStdString(userVec[i]));

            connect(newPrivEvent, SIGNAL(deleteEventSignal(QString, QString, QString, QString)), this,
                    SLOT(deleteEventCalled(QString, QString, QString, QString)));

            scrollLayoutPriv->addWidget(newPrivEvent);
        }

        checkPub->setChecked(false);
    }

    giveNameEdit->clear();
    chooseHourCombo->setCurrentText("00");
    chooseMinuteCombo->setCurrentText("00");

    this->show();
}

void SetUpEvents::setNewEventCalled(){
    emit setNewEventSignal();
}

void SetUpEvents::homePageCalled(){
    emit homePageCallSignal();
}

void SetUpEvents::deleteEventCalled(QString time , QString date, QString description, QString user){
    emit deleteEventSignal(time, date, description, user);
}
