#include "userInterface/lib/setupcleaningplan.h"
#include <QWidget>

SetUpCleaningPlan::SetUpCleaningPlan(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Putzplan erstellen");

    selectedRow = new QGridLayout();

    selectWeekArea = new QHBoxLayout();
    selectWeekLabel = new QLabel("Kalenderwoche wählen:");
    giveCWEdit = new QLineEdit();

    calendarArea = new QVBoxLayout();
    calendar = new QCalendarWidget;

    ListArea = new QVBoxLayout();
    selectedTasksLabel = new QLabel("Hinzugefügte Aufgaben:");
    scrollArea = new QScrollArea(this);
    scrollWidget = new QWidget(this);
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
    backButton = new QPushButton("Zum Putzplan \n hinzufügen");

    this->setMainWindowDesign();
    this->setMainLayoutDesign();

    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
         )
    );

    QObject::connect(addTaskButton,SIGNAL(clicked()),this,SLOT(setNewTaskCalled()));
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
                                   "font-weight: bold; margin-top: 30px; color: #aaa");


    this->selectedRow->addLayout(this->selectWeekArea, 0, 0, 450, 100, Qt::AlignJustify);
    this->selectedRow->addLayout(this->calendarArea, 1, 0, 450, 300, Qt::AlignLeft);
    this->selectedRow->addLayout(this->ListArea, 0, 1, 450, 300, Qt::AlignRight);

    this->selectWeekArea->addWidget(this->selectWeekLabel, 0, Qt::AlignTop);
    this->selectWeekLabel->setStyleSheet("font-family: URW Bookman L; font-size: 12px;"
                                         "font-weight: bold; color: #aaa; margin-right: -80px;"
                                         "margin-left: 15px;");
    this->selectWeekArea->addWidget(this->giveCWEdit, 1, Qt::AlignTop);
    this->giveCWEdit->setFixedWidth(80);
    this->giveCWEdit->setMaxLength(2);
    this->giveCWEdit->setValidator(new QIntValidator(0, 54, this));
    this->calendarArea->addWidget(this->calendar, 0, Qt::AlignBottom);
    this->calendar->showToday();
    this->calendar->setSelectionMode(calendar->NoSelection);
    this->calendar->setFixedSize(300, 290);
    this->calendar->setStyleSheet("font-family: URW Bookman L; font-size:12px; color: black");

/*    this->frmt.setForeground(Qt::red);
    this->calendar->setHeaderTextFormat(frmt);
*/

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

//update tasks
void SetUpCleaningPlan::setTaskCombobox(std::vector<std::string> Tasks, std::vector<std::string> Rooms) {
    QStringList tasks;
    for(unsigned int i = 0; i< Tasks.size(); i++) {
        tasks.push_back(QString::fromStdString(Tasks[i]) + " - " + QString::fromStdString(Rooms[i]));
    }
    selectTaskCombo->clear();
    selectTaskCombo->addItems(tasks);
}

//update residents
void SetUpCleaningPlan::setResidentCombobox(std::vector<std::string> Residents) {
    QStringList res;
    for(unsigned int i = 0; i< Residents.size(); i++) {
        res.push_back(QString::fromStdString(Residents[i]));
    }
    selectResCombo->clear();
    selectResCombo->addItems(res);
}


int SetUpCleaningPlan::getTaskWeekInput(){
    return this->giveCWEdit->text().toInt();
}

std::string SetUpCleaningPlan::getTaskNameInput(){
    std::string task_str;
    std::string task_name = "";
    task_str = this->selectTaskCombo->currentText().toStdString();
    for(unsigned int i = 0; i<task_str.size(); i++){
        if(task_str[i+1] != '-'){
            task_name= task_name + task_str[i];
        }else{
            break;
        }
    }
    return task_name;
}
std::string SetUpCleaningPlan::getTaskRoomInput(){
    std::string task_str;
    task_str = this->selectTaskCombo->currentText().toStdString();
    char task_room [task_str.size()];

    for(unsigned int i = 0; i<task_str.size(); i++){
        if(task_str[i] == '-'){
            std::size_t length = task_str.copy(task_room, task_str.size(), i+2 );
            task_room[length] = '\0';
            break;
        }
    }
    return task_room;
}

std::string SetUpCleaningPlan::getResInput(){
    return this->selectResCombo->currentText().toStdString();
}

void SetUpCleaningPlan::deepDeleteLayout(QLayout *layout){
    QLayoutItem* item;

    while((item = layout->takeAt(0))) {
        if(item->layout()){
            deepDeleteLayout(item->layout());
            delete item->layout();
        }

        if(item->widget()) {
            delete item->widget();
        }

        delete item;
    }
}

void SetUpCleaningPlan::appear(std::vector<int> weekVec,
                               std::vector<std::string> taskVec,
                               std::vector<std::string> resVec,
                               std::vector<std::string> roomVec,
                               int size){
    for(unsigned int i= 0; i<ConcreteTaskListItemList.size(); i++){
        deepDeleteLayout(scrollLayout);
    }
    ConcreteTaskListItemList.clear();

    for(int i=0; i<size; i++){
        newConcreteTask = new ConcreteTaskListItem(QString::number(weekVec[i]),
                                                   QString::fromStdString(taskVec[i]),
                                                   QString::fromStdString(resVec[i]),
                                                   QString::fromStdString(roomVec[i]));
        connect(newConcreteTask,SIGNAL(deleteConcreteTaskSignal(QString, QString, QString, QString)),this,SLOT(deleteTaskCalled(QString,QString,QString,QString)));
        connect(newConcreteTask, SIGNAL(editConcreteTaskSignal(QString,QString,QString,QString)), this, SLOT(editTaskCalled(QString,QString,QString,QString)));

        ConcreteTaskListItemList.push_back(newConcreteTask);
        scrollLayout->addWidget(newConcreteTask);
    }
    giveCWEdit->clear();
    selectTaskCombo->setCurrentIndex(0);
    selectResCombo->setCurrentIndex(0);
}

void SetUpCleaningPlan::setNewTaskCalled(){
    emit NewConcreteTaskSignal();
}

void SetUpCleaningPlan::deleteTaskCalled(QString week, QString task, QString res, QString room){
    emit deleteConcreteTaskSignal(week, task, res, room);
}

void SetUpCleaningPlan::editTaskCalled(QString week, QString task, QString res, QString room){
    emit deleteConcreteTaskSignal(week, task, res, room);


    int index = selectTaskCombo->findText(task+" - "+room);
    selectTaskCombo->setCurrentIndex(index);

    index = selectResCombo->findText(res);
    selectResCombo->setCurrentIndex(index);

    giveCWEdit->setText(week);

}

