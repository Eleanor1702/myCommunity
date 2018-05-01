#ifndef SETUPROOMS_H
#define SETUPROOMS_H

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
#include <userInterface/lib/Roomlistitem.h>
#include <userInterface/lib/SetUpUsers.h>

//Inheritance from QWidget allows the class itself to react on events
//example (Button clicks.. etc)
class SetUpRooms : public QWidget{
  //enable creation of slots and signals
  Q_OBJECT
private:
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

private slots:
    void addButtonClicked();
    void saveButtonClicked();

signals:

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SetUpRooms(QWidget *parent = NULL);


public slots:

};

#endif // SETUPROOMS_H

