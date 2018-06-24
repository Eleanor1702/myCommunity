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
    this->setGeometry(        // To center window
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    QObject::connect(addEventButton,SIGNAL(clicked()),this,SLOT(setNewEventCalled()));
    QObject::connect(saveEventButton,SIGNAL(clicked()),this,SLOT(homePageCalled()));
    QObject::connect(calendar,SIGNAL(selectionChanged()),this,SLOT(appearCalled())); //changes shown events, if another date was selected
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
    this->mainLabel->setStyleSheet("font-family: Arial; font-size: 30px;"
                                   "font-weight: bold; margin-top: 30px; color: #555;");



    this->calendarRow->addLayout(this->ListArea, 0, 0, 450, 400, Qt::AlignLeft);
    this->calendarRow->addLayout(this->calendarArea, 0, 1, 450, 500, Qt::AlignRight);
    //set Layout Design for ListArea --> List of Private and Public Events
    this->ListArea->addWidget(this->PrivLabel, 0, Qt::AlignTop);
    this->PrivLabel->setStyleSheet("font-family: Arial; font-size: 10px;"
                                   "font-weight: bold; color: #555;");
    this->ListArea->addWidget(this->scrollArea, 1, Qt::AlignTop);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollArea->setWidgetResizable(true);
    this->scrollArea->setFixedWidth(350);
    this->scrollArea->setFixedHeight(175);
    this->scrollWidget->setLayout(this->scrollLayout);
    this->scrollLayout->setAlignment(Qt::AlignTop);

    this->ListArea->addWidget(this->PubLabel, 2, Qt::AlignBottom);
    this->PubLabel->setStyleSheet("font-family: Arial; font-size: 10px;"
                                  "font-weight: bold; color: #555;");
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
    this->calendar->setStyleSheet("font-family: Arial; font-size: 17px; color: black");
    this->fmt.setBackground(Qt::lightGray);
    this->calendar->setDateTextFormat(QDate::currentDate(), fmt);


    //set Layout Design for Time Selection
    this->addEventRow->addWidget(this->TimeLabel, 2, Qt::AlignRight);
    this->TimeLabel->setStyleSheet("color: #555; font-weight: bold");
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
    this->hourLabel->setStyleSheet("color: #555; font-weight: bold");
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
    this->chosenTimeLabel->setStyleSheet("color: #555; font-weight:bold;");

    //set Layout Design for adding event Description and CheckBox
    this->addEventRow->addWidget(this->eventDescriptionLabel, 2, Qt::AlignRight);
    this->eventDescriptionLabel->setStyleSheet("color: #555; font-weight: bold;");
    this->addEventRow->addWidget(this->giveNameEdit, 2, Qt::AlignLeft);
    this->giveNameEdit->setMaxLength(18);
    this->giveNameEdit->setFixedWidth(200);
    this->addEventRow->addWidget(this->checkLabel, 2, Qt::AlignRight);
    this->checkLabel->setStyleSheet("font-family: Arial; font-size: 10px;"
                                    "font-weight: bold; color: #555;");
    this->addEventRow->addWidget(this->checkPub, 2, Qt::AlignLeft);



    //set Layout Design ButtonRow --> add and save Button
    this->ButtonRow->addWidget(addEventButton, 3, Qt::AlignLeft);
    this->ButtonRow->addWidget(saveEventButton, 3, Qt::AlignRight);
    this->addEventButton->setFixedSize(200, 50);
    this->addEventButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                        "border-radius: 5px; background-color: #3399ff; "
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
    if (this->giveNameEdit->text().size() == 0 || this->giveNameEdit->text()[0] == ' '){
        return "Error";
    }
    return this->giveNameEdit->text().toStdString();
}

std::string EventPage::getEventUserInput(){
    if(this->checkPub->isChecked()){
        return "gemeinschaftlich";              //Alle User??
    } else {
        return "privat";                        //current UserName
    }
}

void EventPage::deepDeleteLayout(QLayout *layout) {
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

void EventPage::appear(std::vector<std::string> timeVec,
                       std::vector<std::string> dateVec,
                       std::vector<std::string> descrVec,
                       std::string user, int size){

    this->date_fmt.setFontUnderline(true);
    if(user == "gemeinschaftlich"){
        deepDeleteLayout(scrollLayoutPub);

        EventListItemPubList.clear();
        for(int i = 0; i < size; i++){
           newPubEvent = new EventListItem(QString::fromStdString(timeVec[i]),
                                                 QString::fromStdString(dateVec[i]),
                                                 QString::fromStdString(descrVec[i]),
                                                 QString::fromStdString(user));

            connect(newPubEvent, SIGNAL(deleteEventSignal(QString, QString, QString, QString)),this,
                    SLOT(deleteEventCalled(QString, QString, QString, QString)));
            connect(newPubEvent, SIGNAL(editEventSignal(QString,QString,QString,QString)),this, SLOT(editEventCalled(QString,QString,QString,QString)));

            EventListItemPubList.push_back(newPubEvent);

            scrollLayoutPub->addWidget(newPubEvent);
            this->calendar->setDateTextFormat(QDate::fromString(QString::fromStdString(dateVec[i]), "yyyy-MM-dd"), date_fmt);

        }
        checkPub->setChecked(false);
    }else{
        deepDeleteLayout(scrollLayout);
        EventListItemPrivList.clear();
        for(int i = 0; i < size; i++){
            newPrivEvent = new EventListItem(QString::fromStdString(timeVec[i]),
                                                 QString::fromStdString(dateVec[i]),
                                                 QString::fromStdString(descrVec[i]),
                                                 QString::fromStdString(user));
            connect(newPrivEvent, SIGNAL(deleteEventSignal(QString, QString, QString, QString)),this,
                    SLOT(deleteEventCalled(QString, QString, QString, QString)));
            connect(newPrivEvent, SIGNAL(editEventSignal(QString,QString,QString,QString)),this, SLOT(editEventCalled(QString,QString,QString,QString)));

            EventListItemPrivList.push_back(newPrivEvent);
            scrollLayout->addWidget(newPrivEvent);
            this->calendar->setDateTextFormat(QDate::fromString(QString::fromStdString(dateVec[i]), "yyyy-MM-dd"), date_fmt);
        }  
    }

    giveNameEdit->clear();
    chooseHourCombo->setCurrentText("00");
    chooseMinuteCombo->setCurrentText("00");

}

void EventPage::appearDate(std::vector<std::string> dateVec){
    this->date_fmt.setFontUnderline(true);
    for(int i=0; i<dateVec.size(); i++){
        this->calendar->setDateTextFormat(QDate::fromString(QString::fromStdString(dateVec[i]), "yyyy-MM-dd"), date_fmt);
    }
}


void EventPage::setNewEventCalled(){
    emit setNewEventSignal();
}

void EventPage::homePageCalled(){
    emit homePageCallSignal();
}

void EventPage::deleteEventCalled(QString time , QString date, QString description, QString user){
    this->dateNot_fmt.setFontUnderline(false);
    this->calendar->setDateTextFormat(QDate::fromString (date, "yyyy-MM-dd"), dateNot_fmt);
    emit deleteEventSignal(time, date, description, user);
}

void EventPage::appearCalled(){
    emit appearCalledSignal();
}

void EventPage::editEventCalled(QString time , QString date, QString description, QString user) {
    emit deleteEventSignal(time, date, description, user);

    std::string stime = time.toStdString();
    char min[2];
    char hour[3];
    std::size_t length = stime.copy(hour, 2, 1);
    hour[length] = '\0';
    int index = chooseHourCombo->findText(hour);
    chooseHourCombo->setCurrentIndex(index);

    length = stime.copy(min, 3, 4);
    min[length] = '\0';
    index = chooseMinuteCombo->findText(min);
    chooseMinuteCombo->setCurrentIndex(index);


    giveNameEdit->setText(description);
    if(user == "gemeinschaftlich") {
        checkPub->setChecked(true);
    }
}
