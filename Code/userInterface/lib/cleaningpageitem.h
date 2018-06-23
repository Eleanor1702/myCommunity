#ifndef CLEANINGPAGEITEM_H
#define CLEANINGPAGEITEM_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QObject>

class CleaningPageItem : public QFrame
{
    Q_OBJECT
private:
    QLabel *taskLabel;
    QGridLayout *newPlanLayout;

    QString week;
    QString room;
    QString res;
    QString task;

    void setItemStyle();

public:
    explicit CleaningPageItem(QString roomClean, QString taskClean, QString resClean, QWidget *parent = NULL);
};

#endif // CLEANINGPAGEITEM_H
