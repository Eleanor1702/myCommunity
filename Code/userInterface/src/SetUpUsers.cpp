#include "userInterface/lib/SetUpUsers.h"

//calling the constructor, calls the parent constructor too
//in this case QWidget
SetUpUsers::SetUpUsers(QWidget *parent) : QWidget(parent){

  //declarations of window contents
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainLabel = new QLabel("Konfiguriere deine Mitbewohner");

  mainRow = new QBoxLayout(QBoxLayout::LeftToRight, this);

  scrollAreaRow = new QBoxLayout(QBoxLayout::TopToBottom);
  scrollArea = new QScrollArea(this);
  scrollWidget = new QWidget(this);
  scrollLayout = new QBoxLayout(QBoxLayout::TopToBottom, this->scrollWidget);

  mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
  saveButton = new QPushButton ("Speichern");

  this->setMainWindowDesign();
  this->setMainLayoutDesign();
}

void SetUpUsers::setMainWindowDesign() {
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Bewohner Verwalten"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(mainRow);
    //mainLayout->addLayout(scrollAreaRow);
    mainLayout->addLayout(mainButtonsRow);
    this->setLayout(mainLayout);
}

void SetUpUsers::setMainLayoutDesign() {

    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 5px; color: #aaa;");

    this->mainRow->addLayout(scrollAreaRow);
    //this->scrollAreaRow->addWidget(scrollArea);

    this->mainRow->addWidget(scrollArea, 0, Qt::AlignRight);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollWidget->setLayout(this->scrollLayout);
    this->scrollLayout->setAlignment(Qt::AlignTop);
    this->scrollArea->setWidgetResizable(true);
    //this->scrollArea->

    this->mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(200, 50);
    saveButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                              "border-radius: 5px; background-color: #00b300; "
                              "color: white; font-weight: bold;}");

}
