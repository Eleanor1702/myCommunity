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

#include <QStyle>
#include <QDesktopWidget>

#include "userInterface/lib/TaskListItem.h"

//Inheritance from QWidget allows the class itself to react on events
//example (Button clicks.. etc)
class SetUpTasks : public QWidget {
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

   QBoxLayout *addTasksRow;

   QBoxLayout *mainButtonsRow;
   QLabel *TaskFrequencyLabel;
   QComboBox *chooseTaskFrequencyCombo;
   QLabel *TaskRoomLabel;
   QComboBox *chooseTaskRoomCombo;
   QLabel *nameLabel;
   QLineEdit *giveNameEdit;
   QPushButton *addButton;
   QPushButton *saveButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();
    void deepDeleteLayout(QLayout* layout);

private slots:
    void setNewTaskCalled();
    void deleteTaskCalled(QString name, QString room);
    void homePageCalled();

signals:
    void newTaskSignal();
    void deleteTaskSignal(QString name, QString room);
    void homePageCallSignal();

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SetUpTasks(QWidget *parent = NULL);  //geänderter Name

    std::string getSelectedTaskFrequency();
    std::string getSelectedRoomTask();
    std::string getTaskNameInput();
    void appear(std::vector<std::string> nameVec, std::vector<std::string> roomVec, std::vector<std::string> frequencyVec, int size);
    void setRoomCombobox(std::vector<std::string> Rooms);
};

#endif // SETUPTASKS_H
