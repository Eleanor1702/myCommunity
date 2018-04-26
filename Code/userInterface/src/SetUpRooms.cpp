#include "userInterface/lib/setUpRooms.h"

SetUpRooms::SetUpRooms(){}

void SetUpRooms::setMainWindowDesign() {
    this->mainWindow.setFixedSize(700, 500);
    this->mainWindow.setStyleSheet("background-color: white;");
}

void SetUpRooms::setMainLayoutDesign() {
    this->mainLayout->addWidget(this->mainLabel, 0, Qt::AlignTop);
    //this->mainLayout->addWidget(this->addButton, 0, Qt::AlignBottom);
    //test if message can in mainlayout included
    this->mainLayout->addWidget(this->scrollArea, 0, Qt::AlignCenter);
    this->mainLayout->addLayout(this->buttonLayout, 0);
}

void SetUpRooms::setMainLabelDesign() {
    this->mainLabel->setText("Let's add your WG Rooms..");
    this->mainLabel->setAlignment(Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L;"
                                   "font-size: 30px; font-weight: bold;"
                                   "margin-top: 20px;");
}

void SetUpRooms::setRoomsLayoutDesign() {
  this->scrollArea->setAlignment(Qt::AlignCenter);
  this->scrollArea->setFixedHeight(300);
  this->scrollArea->setFixedWidth(600);
  this->scrollWidget->setLayout(this->roomsLayout);
  this->scrollArea->setWidget(this->scrollWidget);
  this->scrollArea->setWidgetResizable(true);
}

void SetUpRooms::setMessageDesign() {
  this->message->setAlignment(Qt::AlignRight);
  this->message->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  this->message->setText("No Rooms added yet");
  this->roomsLayout->addWidget(this->message, 0, Qt::AlignCenter);
}

void SetUpRooms::setButtonLayoutDesign() {
  this->buttonLayout->addWidget(this->addButton,0 , Qt::AlignBottom);
}

void SetUpRooms::setAddButtonDesign() {
    this->addButton->setText("Add");
    this->addButton->setStyleSheet("max-width: 200px; margin-bottom: 20px;"
                                   "font-family: URW Bookman L; font-size: 20px;"
                                   "font-weight: bold;");

    QObject::connect(this->addButton, SIGNAL(clicked()), QApplication::instance(), SLOT(addButtonClicked()));
}

void SetUpRooms::run() {
    this->setMainWindowDesign();
    this->setMainLayoutDesign();
    this->setMainLabelDesign();
    this->setRoomsLayoutDesign();
    this->setMessageDesign();
    this->setButtonLayoutDesign();
    this->setAddButtonDesign();
    this->mainWindow.show();
}

void SetUpRooms::addButtonClicked() {
    this->addButton->setText("Clicked!");
}


