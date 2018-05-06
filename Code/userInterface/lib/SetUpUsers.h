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
#include <userInterface/lib/SetUpRooms.h>

//Inheritance from QWidget allows the class itself to react on events
//example (Button clicks.. etc)
class SetUpUsers : public QWidget{
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

   QBoxLayout *addUsersRow;

   QBoxLayout *mainButtonsRow;
   QLabel *nameLabel;
   QLabel *passwordLabel;
   QLineEdit *giveNameEdit;
   QLineEdit *givePasswordEdit;
   QPushButton *addButton;
   QPushButton *saveButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();


private slots:
    void addButtonClicked();

signals:

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SetUpUsers(QWidget *parent = NULL);

public slots:

};

#endif // SETUPUSERS_H