#ifndef SETUPUSERS_H
#define SETUPUSERS_H

#include <QApplication>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QStringList>
#include <QList>

#include <userInterface/lib/UserList.h>

//Inheritance from QWidget allows the class itself to react on events
//example (Button clicks.. etc)
class SetUpUsers : public QWidget{
  //enable creation of slots and signals
  Q_OBJECT
private:
   friend class GuiController;

   UserList *newUser;

   QBoxLayout *mainLayout;
   QBoxLayout *mainLabelRow;
   QLabel *mainLabel;

   QBoxLayout *mainRow;

   QBoxLayout *scrollAreaRow;
   QScrollArea *scrollArea;
   QWidget *scrollWidget;
   QBoxLayout *scrollLayout;

   QBoxLayout *mainButtonsRow;
   QPushButton *saveButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SetUpUsers(QWidget *parent = NULL);

public slots:

};

#endif // SETUPUSERS_H
