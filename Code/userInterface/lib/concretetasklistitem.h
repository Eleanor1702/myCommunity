#ifndef CONCRETETASKLISTITEM_H
#define CONCRETETASKLISTITEM_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class ConcreteTaskListItem : public QFrame {
  Q_OBJECT
private:
    QLabel *concreteTaskLabel;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QHBoxLayout *newConcreteTaskLayout;

    QString week;
    QString task;
    QString res;
    QString room;

    void setItemStyle();

private slots:
    void deleteConcreteTask();
    void editConcreteTask();

signals:
    void deleteConcreteTaskSignal(QString week, QString task, QString res);
    void editConcreteTaskSignal(QString week, QString task, QString res);

public:
    explicit ConcreteTaskListItem(QString cTaskWeek, QString cTask,
                                  QString cTaskRes, QString cTaskRoom, QWidget *parent = NULL);

};

#endif // CONCRETETASKLISTITEM_H
