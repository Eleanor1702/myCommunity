#ifndef EVENTPAGE_H
#define EVENTPAGE_H

#include <QBoxLayout>
#include <QLabel>
#include <QCalendarWidget>
#include <QPushButton>

class EventPage : public QWidget {
    Q_OBJECT
public:
    EventPage(QWidget *parent=NULL);
private:
    friend class GuiController;
    QBoxLayout *mainLayout;

    QBoxLayout *mainLabelRow;
    QLabel *mainLabel;

    QBoxLayout *calendarRow;
    QCalendarWidget *calendar;

    QBoxLayout *ButtonRow;
    QPushButton *saveEventButton;
    QPushButton *addEventButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

private slots:
    void homePageCalled();

signals:
    void homePageCallSignal();
};

#endif // EVENTPAGE_H
