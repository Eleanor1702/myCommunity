#ifndef EVENTLISTITEM_H
#define EVENTLISTITEM_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDate>

class EventListItem : public QFrame
{
    Q_OBJECT
private:
    friend class GuiController;

    QLabel *eventLabel;
    QPushButton *deleteEventButton;
    QPushButton *editEventButton;
    QHBoxLayout *newEventLayout;

    QString time;
    QString date;
    QString description;
    QString user;

    void setItemStyle();

private slots:
    void deleteEvent();

//    void editEvent();

    //    void deleteEventButtonClicked();

signals:
    void deleteEventSignal(QString time, QString date, QString description, QString user);
//    void editEventSignal(QString hour, QString min, QString name);


public:
    explicit EventListItem(QString eventTime, QString eventDateStr,
                           QString eventDescription, QString eventUser, QWidget *parent = NULL);
};

#endif // EVENTLISTITEM_H