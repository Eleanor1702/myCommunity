#ifndef SETUPEVENTS_H
#define SETUPEVENTS_H

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

#include <QCalendarWidget>
#include <QDate>
#include <QGridLayout>
#include <QCheckBox>
#include "eventlistitem.h"

class SetUpEvents : public QWidget {
    Q_OBJECT

private:
    EventListItem* newPrivEvent;
    EventListItem* newPubEvent;

    //Design Elements
    QBoxLayout* mainLayout;

    QBoxLayout* mainLabelRow;
    QLabel* mainLabel;

    QGridLayout* calendarRow;
    QBoxLayout* calendarArea;
    QCalendarWidget* calendar;

    QVBoxLayout* ListArea;
    QLabel* PrivLabel;
    QScrollArea* scrollAreaPriv;
    QWidget* scrollWidgetPriv;
    QBoxLayout* scrollLayoutPriv;

    QLabel* PubLabel;
    QScrollArea* scrollAreaPub;
    QWidget* scrolLWidgetPub;
    QBoxLayout* scrollLayoutPub;

    QBoxLayout* addEventRow;
    QLabel* TimeLabel;
    QComboBox* chooseHourCombo;
    QLabel* hourLabel;
    QComboBox* chooseMinuteCombo;
    QLabel* chosenTimeLabel;

    QLabel* eventDescriptionLabel;
    QLineEdit* giveNameEdit;

    QLabel* checkLabel;
    QCheckBox* checkPub;

    QBoxLayout *ButtonRow;
    QPushButton *addEventButton;
    QPushButton *saveEventButton;

    QTextCharFormat fmt;

    void setMainWindowDesign();
    void setMainLayoutDesign();
    void deepDeleteLayout(QLayout* layout);

private slots:
    void setNewEventCalled();
    void deleteEventCalled(QString time, QString date, QString description, QString user);
    void homePageCalled();

signals:
    void setNewEventSignal();
    void deleteEventSignal(QString, QString, QString, QString);
    void homePageCallSignal();

public:
    explicit SetUpEvents(QWidget *parent = NULL);
    std::string getEventTimeInput();
    std::string getEventDateInput();
    std::string getEventDescriptionInput();
    std::string getEventUserInput();
    void appear(std::vector<std::string> timeVec, std::vector<std::string> dateVec,
                std::vector<std::string> descrVec, std::vector<std::string> userVec, int size);
};
#endif // SETUPEVENTS_H
