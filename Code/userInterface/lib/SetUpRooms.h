#ifndef SETUPROOMS_H
#define SETUPROOMS_H

#include <vector>
#include <QApplication>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QStringList>
#include <QList>

#include <userInterface/lib/RoomListItem.h>

//Inheritance from QWidget allows the class itself to react on events
//example (Button clicks.. etc)
class SetUpRooms : public QWidget{
  //enable creation of slots and signals
  Q_OBJECT
private:
   friend class GuiController;

   RoomListItem *newRoom;

   QBoxLayout *mainLayout;
   QBoxLayout *mainLabelRow;
   QLabel *mainLabel;

   QBoxLayout *scrollAreaRow;
   QScrollArea *scrollArea;
   QWidget *scrollWidget;
   QBoxLayout *scrollLayout;

   QBoxLayout *addRoomsRow;

   QBoxLayout *mainButtonsRow;
   QLabel *roomTypeLabel;
   QComboBox *chooseRoomTypeCombo;
   QLabel *nameLabel;
   QLineEdit *giveNameEdit;
   QPushButton *addButton;
   QPushButton *saveButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SetUpRooms(QWidget *parent = NULL);
    std::vector<RoomListItem*> RoomListItemList;

    std::string getRoomTypeInput();
    std::string getRoomNameInput();
    void show(std::vector<std::string> nameVec, std::vector<std::string> typeVec, int size);

public slots:
    void setNewRoomCalled();
    void homePageCalled();

signals:
    void setNewRoomSignal();
    void homePageCallSignal();

#endif // SETUPROOMS_H
