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
  friend class GuiController;

  QLabel *user;
  QPushButton *deleteButton;
  QHBoxLayout *newUserLayout;

  void setItemStyle();

signals:
  void deleteUserButtonClickedSignal(QString name);

private slots:
  void deleteUserButtonClicked();

public:
  //QFrame ist ein QWidget
  explicit UserList(QString userName, QWidget *parent = NULL);

public slots:
};

#endif // USERLIST_H
