#include "userInterface/lib/setUpRooms.h"

SetUpRooms::SetUpRooms() {}

void SetUpRooms::setMainWindowDesign() {
    this->mainWindow.setFixedSize(700, 500);
    this->mainWindow.setStyleSheet("background-color: white;");
}

void SetUpRooms::setMainLayoutDesign() {
    this->mainLayout->addWidget(this->mainLabel, 0, Qt::AlignTop);
}

void SetUpRooms::setMainLabelDesign() {
    this->mainLabel->setText("Let's add your WG Rooms..");
    this->mainLabel->setAlignment(Qt::AlignCenter);
    //this->mainLabel->setFixedWidth(10);
}

void SetUpRooms::run() {
    this->setMainWindowDesign();
    this->setMainLayoutDesign();
    this->setMainLabelDesign();
    this->mainWindow.show();
}


