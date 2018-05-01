#ifndef ROOMLISTITEM_H
#define ROOMLISTITEM_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class RoomListItem : public QFrame
{
  Q_OBJECT
private:
  QLabel *room;
  QPushButton *deleteButton;
  QHBoxLayout *newRoomLayout;

  void setItemStyle();

private slots:
  void deleteButtonClicked();

signals:

public:
  //QFrame ist ein QWidget
  explicit RoomListItem(QString roomName, QWidget *parent = NULL);

public slots:
};

#endif // ROOMLISTITEM_H
