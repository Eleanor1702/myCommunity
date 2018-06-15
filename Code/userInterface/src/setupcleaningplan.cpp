#include "userInterface/lib/setupcleaningplan.h"
#include <QWidget>

SetUpCleaningPlan::SetUpCleaningPlan(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Putzplan erstellen");

    selectedRow = new QGridLayout();

    selectWeekArea = new QHBoxLayout();
    selectWeekLabel = new QLabel("Woche wählen:");
    giveCWEdit = new QLineEdit();

    calendarArea = new QVBoxLayout();
    calendar = new QCalendarWidget;

    ListArea = new QVBoxLayout();
    selectedTasksLabel = new QLabel("Hinzugefügte Aufgaben:");
    scrollArea = new QScrollArea();
    scrollWidget = new QWidget();
    scrollLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    addTaskLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    addTaskLabel = new QLabel("Aufgabe hinzufügen:");

    selectionArea = new QBoxLayout(QBoxLayout::LeftToRight);
    selectTaskLabel = new QLabel("Aufgabe:");
    selectTaskCombo = new QComboBox();
    selectResLabel = new QLabel("Bewohner:");
    selectResCombo = new QComboBox();

    buttonRow = new QBoxLayout(QBoxLayout::LeftToRight);
    addTaskButton = new QPushButton("Aufgabe hinzufügen");
    backButton = new QPushButton("Zurück");

    this->setMainWindowDesign();
    this->setMainLayoutDesign();

    QObject::connect(backButton,SIGNAL(clicked()),this,SLOT(CleanPlanCalled()));
}

void SetUpCleaningPlan::setMainWindowDesign(){
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white");
    this->setWindowTitle(QString::fromUtf8("Putzplan erstellen"));

    mainLayout->addLayout(this->mainLabelRow);
    mainLayout->addLayout(this->selectedRow);
    mainLayout->addLayout(this->addTaskLabelRow);
    mainLayout->addLayout(this->selectionArea);
    mainLayout->addLayout(this->buttonRow);
    this->setLayout(mainLayout);
}

void SetUpCleaningPlan::setMainLayoutDesign(){
    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 30pc; color: #aaa");


    this->selectedRow->addLayout(this->selectWeekArea, 0, 0, 450, 100, Qt::AlignJustify);
    this->selectedRow->addLayout(this->calendarArea, 1, 0, 450, 300, Qt::AlignLeft);
    this->selectedRow->addLayout(this->ListArea, 0, 1, 450, 300, Qt::AlignRight);

    this->selectWeekArea->addWidget(this->selectWeekLabel, 0, Qt::AlignTop);
    this->selectWeekLabel->setStyleSheet("font-family: URW Bookman L; font-size: 12px;"
                                         "font-weight: bold; color: #aaa;");
    this->selectWeekArea->addWidget(this->giveCWEdit, 1, Qt::AlignTop);
    this->giveCWEdit->setFixedWidth(180);
    this->giveCWEdit->setMaxLength(2);
    this->calendarArea->addWidget(this->calendar, 0, Qt::AlignBottom);
    this->calendar->showToday();
    this->calendar->setSelectionMode(calendar->NoSelection);
    this->calendar->setFixedSize(300, 290);
    this->calendar->setStyleSheet("font-family: URW Bookman L; font-size:12px; color: black");

    this->ListArea->addWidget(this->selectedTasksLabel, 0, Qt::AlignTop);
    this->selectedTasksLabel->setStyleSheet("font-family: URW Bookman L; font-size: 12px;"
                                            "font-weight: bold; color: #aaa;");
    this->ListArea->addWidget(this->scrollArea,1, Qt::AlignTop);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollArea->setWidgetResizable(true);
    this->scrollArea->setFixedSize(450,300);
    this->scrollWidget->setLayout(this->scrollLayout);
    this->scrollLayout->setAlignment(Qt::AlignTop);

    this->addTaskLabelRow->addWidget(this->addTaskLabel,0, Qt::AlignLeft);
    this->addTaskLabel->setStyleSheet("font-family: URW Bookman L; font-size: 13px;"
                                      "font-weight: bold; color: #aaa;");

    this->selectionArea->addWidget(this->selectTaskLabel,1, Qt::AlignTop);
    this->selectTaskLabel->setStyleSheet("font-family: URW Bookman L; font-size: 12px;"
                                         "font-weight: bold; color: #aaa;");
    this->selectionArea->addWidget(this->selectTaskCombo, 2, Qt::AlignTop);
    this->selectTaskCombo->setFixedWidth(350);
    this->selectTaskCombo->setStyleSheet("selection-color: white; selection-background-color: #1aa3ff;"
                                         "color: black; background-color: White;");
    this->selectionArea->addWidget(this->selectResLabel,3,Qt::AlignTop);
    this->selectResLabel->setStyleSheet("font-family: URW Bookman L; font-size: 12px;"
                                        "font-weight: bold; color: #aaa;");
    this->selectionArea->addWidget(this->selectResCombo, 4, Qt::AlignTop);
    this->selectResCombo->setFixedWidth(280);
    this->selectResCombo->setStyleSheet("selection-color: white; selection-background-color: #1aa3ff;"
                                        "color: black; background-color: White;");

    this->buttonRow->addWidget(addTaskButton,2,Qt::AlignLeft);
    this->addTaskButton->setFixedSize(200, 50);
    this->addTaskButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                       "border-radius: 5px; background-color: #3399ff; "
                                       "color: white; font-weight: bold;}");
    this->buttonRow->addWidget(backButton, 2, Qt::AlignRight);
    this->backButton->setFixedSize(200, 50);
    this->backButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                               "border-radius: 5px; background-color: #00b300; "
                               "color: white; font-weight: bold;}");
}


void SetUpCleaningPlan::CleanPlanCalled(){
    emit CleanPlanCallSignal();
}
