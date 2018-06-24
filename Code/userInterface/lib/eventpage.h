#ifndef EVENTPAGE_H
#define EVENTPAGE_H

#include <vector>
#include <QApplication>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QStringList>
#include <QList>

#include <QStyle>
#include <QDesktopWidget>

#include <QCalendarWidget>
#include <QDate>
#include <QGridLayout>
#include <QCheckBox>
#include "eventlistitem.h"


class EventPage : public QWidget
{
    Q_OBJECT

private:
   friend class GuiController;

    EventListItem *newPrivEvent;
    EventListItem *newPubEvent;

    //Design Elements
    QBoxLayout *mainLayout;

    QBoxLayout *mainLabelRow;
    QLabel *mainLabel;

    QGridLayout *calendarRow;
    QBoxLayout *calendarArea;
    QLabel *PrivLabel;
    QVBoxLayout *ListArea;
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QBoxLayout *scrollLayout;
    QLabel *PubLabel;
    QScrollArea *scrollAreaPub;
    QWidget *scrolLWidgetPub;
    QBoxLayout *scrollLayoutPub;
    QCalendarWidget *calendar;


    QBoxLayout *addEventRow;
    QLabel *TimeLabel;
    QComboBox *chooseHourCombo;
    QLabel *hourLabel;
    QComboBox *chooseMinuteCombo;
    QLabel *chosenTimeLabel;
    QLabel *eventDescriptionLabel;
    QLineEdit *giveNameEdit;
    QLabel *checkLabel;
    QCheckBox *checkPub;

    QBoxLayout *ButtonRow;
    QPushButton *addEventButton;
    QPushButton *saveEventButton;

    QTextCharFormat fmt;
    QTextCharFormat date_fmt;
    QTextCharFormat dateNot_fmt;

    void setMainWindowDesign();
    void setMainLayoutDesign();

private slots:
    void setNewEventCalled();
    void deleteEventCalled(QString time, QString date, QString description, QString user);
    void homePageCalled();
    void appearCalled();
    void editEventCalled(QString time,QString date,QString description,QString user);

signals:
    void deleteEventSignal(QString, QString, QString, QString);
    void homePageCallSignal();
    void setNewEventSignal();
    void appearCalledSignal();



public:
    explicit EventPage(QWidget *parent=NULL);
    std::vector<EventListItem*> EventListItemPrivList;
    std::vector<EventListItem*> EventListItemPubList;
    std::string getEventTimeInput();
    std::string getEventDateInput();
    std::string getEventDescriptionInput();
    std::string getEventUserInput();
    void deepDeleteLayout (QLayout *layout);
    void appear(std::vector<std::string> timeVec,
                std::vector<std::string> dateVec,
                std::vector<std::string> descrVec,
                std::string user, int size);

    void appearDate(std::vector<std::string> dateVec);


};


#endif // EVENTPAGE_H
