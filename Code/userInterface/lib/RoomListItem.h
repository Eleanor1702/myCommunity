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
  friend class GuiController;

  QLabel *room;
  QPushButton *deleteButton;
  QHBoxLayout *newRoomLayout;

  void setItemStyle();

private slots:
  void deleteButtonClicked();

signals:
  void deleteButtonClickedSignal(QString name);

public:
  //QFrame ist ein QWidget
  explicit RoomListItem(QString roomName, QWidget *parent = NULL);

public slots:
};

#endif // ROOMLISTITEM_H
