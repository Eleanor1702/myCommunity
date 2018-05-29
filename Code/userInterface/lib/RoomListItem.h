#ifndef ROOMLISTITEM_H
#define ROOMLISTITEM_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class RoomListItem : public QFrame {
  Q_OBJECT
private:
  friend class GuiController;

  QLabel *room;
  QPushButton *deleteButton;
  QHBoxLayout *newRoomLayout;

  QString name;

  void setItemStyle();

private slots:
  void deleteRoom();

signals:
  void deleteRoomSignal(QString name);

public:
  //QFrame ist ein QWidget
  explicit RoomListItem(QString roomName, QString roomType, QWidget *parent = NULL);
};

#endif // ROOMLISTITEM_H
