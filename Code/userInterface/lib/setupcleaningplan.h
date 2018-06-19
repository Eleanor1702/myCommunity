#ifndef SETUPCLEANINGPLAN_H
#define SETUPCLEANINGPLAN_H

#include <vector>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>
#include <QScrollArea>
#include <QCalendarWidget>
#include <QComboBox>
#include <QWidget>
#include <QLineEdit>
#include <QTextCharFormat>
#include "userInterface/lib/concretetasklistitem.h"

class SetUpCleaningPlan : public QWidget {
    Q_OBJECT
private:

    ConcreteTaskListItem *newConcreteTask;

    //Design Elements
    QBoxLayout *mainLayout;

    QBoxLayout *mainLabelRow;
    QLabel *mainLabel;

    QGridLayout *selectedRow;

    QBoxLayout *selectWeekArea;
    QLabel *selectWeekLabel;
    QLineEdit *giveCWEdit;

    QBoxLayout *calendarArea;
    QCalendarWidget *calendar;

    QVBoxLayout *ListArea;
    QLabel *selectedTasksLabel;
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QBoxLayout *scrollLayout;

    QBoxLayout *addTaskLabelRow;
    QLabel *addTaskLabel;

    QBoxLayout *selectionArea;
    QLabel *selectTaskLabel;
    QComboBox *selectTaskCombo;
    QLabel *selectResLabel;
    QComboBox *selectResCombo;

    QBoxLayout *buttonRow;
    QPushButton *addTaskButton;
    QPushButton *backButton;

    QTextCharFormat frmt;

    void setMainWindowDesign();
    void setMainLayoutDesign();
public:
    explicit SetUpCleaningPlan(QWidget *parent = NULL);

    std::vector<ConcreteTaskListItem*> ConcreteTaskListItemList;

    void setTaskCombobox(std::vector<std::string> Tasks, std::vector<std::string> Rooms);
    void setResidentCombobox(std::vector<std::string> Residents);

    int getTaskWeekInput();
    std::string getTaskNameInput();
    std::string getTaskRoomInput();
    std::string getResInput();

    void appear(std::vector<int> weekVec,
                std::vector<std::string> taskVec,
                std::vector<std::string> resVec,
                std::vector<std::string> roomVec,
                int size);

    void deepDeleteLayout(QLayout *layout);

private slots:
    void CleanPlanCalled();
    void deleteTaskCalled(QString week, QString task, QString res);
    void editTaskCalled(QString week, QString task, QString res);
    void setNewTaskCalled();
signals:
    void CleanPlanCallSignal();
    void deleteTaskSignal(QString, QString, QString);
    void editTaskSignal(QString, QString, QString);
    void setNewTaskSignal();

};

#endif // SETUPCLEANINGPLAN_H
