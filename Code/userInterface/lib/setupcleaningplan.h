#ifndef SETUPCLEANINGPLAN_H
#define SETUPCLEANINGPLAN_H

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

class SetUpCleaningPlan : public QWidget {
    Q_OBJECT
private:

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

    void setTaskCombobox(std::vector<std::string> Tasks, std::vector<std::string> Rooms);
    void setResidentCombobox(std::vector<std::string> Residents);
private slots:
    void CleanPlanCalled();
signals:
    void CleanPlanCallSignal();
};

#endif // SETUPCLEANINGPLAN_H
