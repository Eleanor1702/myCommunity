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

#include <QStyle>
#include <QDesktopWidget>

#include <userInterface/lib/RoomListItem.h>

//Inheritance from QWidget allows the class itself to react on events
//example (Button clicks.. etc)
class SetUpRooms : public QWidget {
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
    void deepDeleteLayout(QLayout* layout);

private slots:
    void setNewRoomCalled();
    void homePageCalled();
    void deleteRoomCalled(QString name);

signals:
    void setNewRoomSignal();
    void homePageCallSignal();
    void deleteRoomSignal(QString);

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SetUpRooms(QWidget *parent = NULL);

    std::string getRoomTypeInput();
    std::string getRoomNameInput();
    void appear(std::vector<std::string> nameVec, std::vector<std::string> typeVec, int size);

};

#endif // SETUPROOMS_H

