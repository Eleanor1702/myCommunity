#ifndef USERLISTITEM_H
#define USERLISTITEM_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class UserListItem : public QFrame {
  Q_OBJECT
private:
  friend class GuiController;

  QLabel *user;
  QPushButton *deleteButton;
  QHBoxLayout *newUserLayout;

  void setItemStyle(std::string currentUser, QString userName);

signals:
  void deleteUserSignal(QString name);


private slots:
  void deleteUser();

public:
  //QFrame ist ein QWidget
  explicit UserListItem(std::string currentUser, QString userName, QWidget *parent = NULL);

public slots:

};

#endif // USERLISTITEM_H
