#include "userInterface/lib/SetUpTasks.h"

//calling the constructor, calls the parent constructor too
//in this case QWidget
SetUpTasks::SetUpTasks(QWidget *parent) : QWidget(parent){
  //declarations of window contents
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainLabel = new QLabel("Aufgaben hinzufügen..");

  scrollAreaRow = new QBoxLayout(QBoxLayout::LeftToRight);
  scrollArea = new QScrollArea(this);
  scrollWidget = new QWidget(this);
  scrollLayout = new QBoxLayout(QBoxLayout::TopToBottom, this->scrollWidget);

  addTasksRow = new QBoxLayout(QBoxLayout::LeftToRight);

  mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
  TaskFrequencyLabel = new QLabel("Häufigkeit:");
  chooseTaskFrequencyCombo = new QComboBox();
  TaskRoomLabel = new QLabel ("Raum:");
  chooseTaskRoomCombo = new QComboBox();
  nameLabel = new QLabel("Name:");
  giveNameEdit = new QLineEdit();
  addButton = new QPushButton (QString::fromUtf8("Aufgabe hinzufügen"), this);
  saveButton = new QPushButton ("Speichern");

  this->setMainWindowDesign();
  this->setMainLayoutDesign();

  QObject::connect(addButton, SIGNAL(clicked()), this, SLOT(setNewTaskCalled()));
  QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(homePageCalled()));
}

void SetUpTasks::setMainWindowDesign() {
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Aufgaben Verwalten"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(scrollAreaRow);
    mainLayout->addLayout(addTasksRow);
    mainLayout->addLayout(mainButtonsRow);
    this->setLayout(mainLayout);
}

void SetUpTasks::setMainLayoutDesign() {

    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 5px; color: #aaa;");

    this->scrollAreaRow->addWidget(scrollArea);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollWidget->setLayout(this->scrollLayout);
    this->scrollLayout->setAlignment(Qt::AlignTop);
    this->scrollArea->setWidgetResizable(true);


    this->addTasksRow->addWidget(TaskFrequencyLabel);
    this->addTasksRow->addWidget(chooseTaskFrequencyCombo);
    this->chooseTaskFrequencyCombo->setFixedWidth(120);
    this->TaskFrequencyLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    this->chooseTaskFrequencyCombo->setStyleSheet("selection-color: white; selection-background-color: #1aa3ff;"
                                             " color: black; background-color: White;");

    QStringList frequency;
    frequency << QString::fromUtf8("jede Woche") << QString::fromUtf8("jede 2. Woche") << "jede 3. Woche" << "jeden Monat" << "nach Bedarf";
    chooseTaskFrequencyCombo->addItems(frequency);

    this->addTasksRow->addWidget(TaskRoomLabel);
    this->addTasksRow->addWidget(chooseTaskRoomCombo);
    this->chooseTaskRoomCombo->setFixedWidth(120);
    this->TaskRoomLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    this->chooseTaskRoomCombo->setStyleSheet("selection-color: white; selection-background-color: #1aa3ff;"
                                             "color: black; background-color: white;");

    //Muss Liste der Räume aus Datenbank holen!
    QStringList rooms;
    rooms << "Bad" << "Küche";
    chooseTaskRoomCombo->addItems(rooms);

    this->addTasksRow->addWidget(nameLabel);
    this->addTasksRow->addWidget(giveNameEdit);
    this->giveNameEdit->setMaxLength(18);
    this->nameLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    this->giveNameEdit->setStyleSheet("color: black;");

    this->mainButtonsRow->addWidget(addButton);
    addButton->setFixedSize(200, 50);
    addButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                             "border-radius: 5px; background-color: #3399ff; "
                             "color: white; font-weight: bold;}");


    this->mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(200, 50);
    saveButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                              "border-radius: 5px; background-color: #00b300; "
                              "color: white; font-weight: bold;}");
}

std::string SetUpTasks::getSelectedTaskFrequency() {
  return chooseTaskFrequencyCombo->currentText().toStdString();
}

std::string SetUpTasks::getSelectedRoomTask() {
  return chooseTaskRoomCombo->currentText().toStdString();
}

std::string SetUpTasks::getTaskNameInput() {
    //proceed only with a room name
    if(giveNameEdit->text().size() == 0 || giveNameEdit->text()[0] == ' '){
        return "Error";
    }

    return giveNameEdit->text().toStdString();
}

void SetUpTasks::appear(std::vector<std::string> nameVec, std::vector<std::string> roomVec, std::vector<std::string> frequencyVec, int size) {
    this->show();

    for(int i = 0; i < TaskListItemList.size(); i++) {
        scrollLayout->removeWidget(TaskListItemList[i]);
    }

    TaskListItemList.clear();

    for(int i = 0; i < size; i++) {
        newTask = new TaskListItem(QString::fromStdString(nameVec[i]), QString::fromStdString(roomVec[i]), QString::fromStdString(frequencyVec[i]));

        // so every TaskListItem is connected..
        connect(newTask, SIGNAL(deleteTaskSignal(QString)), this, SLOT(deleteTaskCalled(QString)));

        TaskListItemList.push_back(newTask);
        scrollLayout->addWidget(newTask);
    }

    giveNameEdit->clear();
}


void SetUpTasks::setNewTaskCalled() {
  emit newTaskSignal();
}

void SetUpTasks::homePageCalled() {
  emit homePageCallSignal();
}

void SetUpTasks::deleteTaskCalled(QString name) {
  emit deleteTaskSignal(name);
}