#include "userInterface/lib/SetUpUsers.h"

//calling the constructor, calls the parent constructor too
//in this case QWidget
SetUpUsers::SetUpUsers(QWidget *parent) : QWidget(parent){
  //declarations of window contents
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainLabel = new QLabel("WG Bewohner");

  scrollAreaRow = new QBoxLayout(QBoxLayout::LeftToRight);
  scrollArea = new QScrollArea(this);
  scrollWidget = new QWidget(this);
  scrollLayout = new QBoxLayout(QBoxLayout::TopToBottom, this->scrollWidget);

  addUserRow = new QBoxLayout(QBoxLayout::LeftToRight);

  mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
  backButton = new QPushButton ("Zurück zum Hauptmenü");
  changepwButton = new QPushButton ("Accountpasswort ändern");

  this->setMainWindowDesign();
  this->setMainLayoutDesign();

  QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(homePageCalled()));
  QObject::connect(changepwButton, SIGNAL(clicked()), this, SLOT(pwpageCalled()));
}

void SetUpUsers::setMainWindowDesign() {
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Bewohner Verwalten"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(scrollAreaRow);
    mainLayout->addLayout(addUserRow);
    mainLayout->addLayout(mainButtonsRow);
    this->setLayout(mainLayout);
}

void SetUpUsers::setMainLayoutDesign() {

    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 5px; color: #aaa;");

    this->scrollAreaRow->addWidget(scrollArea);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollWidget->setLayout(this->scrollLayout);
    this->scrollLayout->setAlignment(Qt::AlignTop);
    this->scrollArea->setWidgetResizable(true);


    this->mainButtonsRow->addWidget(backButton);
    backButton->setFixedSize(200, 50);
    backButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                              "border-radius: 5px; background-color: #00b300; "
                              "color: white; font-weight: bold;}");
    this->mainButtonsRow->addWidget(changepwButton);
    changepwButton->setFixedSize(200, 50);
    changepwButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                              "border-radius: 5px; background-color: #00b300; "
                              "color: white; font-weight: bold;}");
}

void SetUpUsers::homePageCalled() {
  emit homePageCallSignal();
}

void SetUpUsers::deleteUserCalled(QString name){
    emit deleteUserSignal(name);
}

void SetUpUsers::pwpageCalled(){
    emit pwpageSignal();
}

void SetUpUsers::deepDeleteLayout(QLayout *layout) {
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

void SetUpUsers::appear(std::vector<std::string> nameVec, int size, std::string username){
    deepDeleteLayout(scrollLayout);

    for(int i = 0; i < size; i++) {
        newUser = new UserListItem(username, QString::fromStdString(nameVec[i]));

        // so every UserListItem is connected..
        connect(newUser, SIGNAL(deleteUserSignal(QString)), this, SLOT(deleteUserCalled(QString)));

        scrollLayout->addWidget(newUser);
    }

    this->show();
}
