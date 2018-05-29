#ifndef TASKLISTITEM_H
#define TASKLISTITEM_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>


class TaskListItem : public QFrame {
  Q_OBJECT
private:
  //friend class GuiController;

  QLabel *task;
  QPushButton *deleteButton;
  QHBoxLayout *newTaskLayout;

  QString name;

  void setItemStyle();

private slots:
  void deleteTask();

signals:
  void deleteTaskSignal(QString name);

public:
  //QFrame ist ein QWidget
  explicit TaskListItem(QString taskName, QString taskRoom, QString taskFrequency, QWidget *parent = NULL);

public slots:

};

#endif // TASKLISTITEM_H
