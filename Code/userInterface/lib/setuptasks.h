#ifndef SETUPTASKS_H
#define SETUPTASKS_H

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

#include "tasklistitem.h"



//Inheritance from QWidget allows the class itself to react on events
//example (Button clicks.. etc)
class SetUpTasks : public QWidget{
  //enable creation of slots and signals
  Q_OBJECT
private:
   friend class GuiController;

   TaskListItem *newTask;

   QBoxLayout *mainLayout;
   QBoxLayout *mainLabelRow;
   QLabel *mainLabel;

   QBoxLayout *scrollAreaRow;
   QScrollArea *scrollArea;
   QWidget *scrollWidget;
   QBoxLayout *scrollLayout;

   QBoxLayout *addTasksRow; //geänderter Name

   QBoxLayout *mainButtonsRow;
   QLabel *TaskFrequencyLabel; //geänderterName
   QComboBox *chooseTaskFrequencyCombo; //geänderter Name
   QLabel *TaskRoomLabel;
   QComboBox *chooseTaskRoomCombo;
   QLabel *nameLabel;
   QLineEdit *giveNameEdit;
   QPushButton *addButton;
   QPushButton *saveButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SetUpTasks(QWidget *parent = NULL);  //geänderter Name
    std::vector<TaskListItem*> TaskListItemList;

public slots:

};

#endif // SETUPTASKS_H
