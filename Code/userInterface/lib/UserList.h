#ifndef USERLIST_H
#define USERLIST_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class UserList : public QFrame
{
  Q_OBJECT
private:
  QLabel *user;
  QPushButton *deleteButton;
  QHBoxLayout *newUserLayout;

  void setItemStyle();

private slots:
  void deleteButtonClicked();

signals:

public:
  //QFrame ist ein QWidget
  explicit UserList(QString userName, QWidget *parent = NULL);

public slots:
};

#endif // USERLIST_H
