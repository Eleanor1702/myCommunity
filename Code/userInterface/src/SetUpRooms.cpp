#include "userInterface/lib/SetUpRooms.h"

//calling the constructor, calls the parent constructor too
//in this case QWidget

SetUpRooms::SetUpRooms(QWidget *parent) : QWidget(parent) {
  //declarations of window contents
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainLabel = new QLabel("WG-Räume");

  scrollAreaRow = new QBoxLayout(QBoxLayout::LeftToRight);
  scrollArea = new QScrollArea(this);
  scrollWidget = new QWidget(this);
  scrollLayout = new QBoxLayout(QBoxLayout::TopToBottom, this->scrollWidget);

  addRoomsRow = new QBoxLayout(QBoxLayout::LeftToRight);

  mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
  roomTypeLabel = new QLabel("Art:");
  chooseRoomTypeCombo = new QComboBox();
  nameLabel = new QLabel("Name:");
  giveNameEdit = new QLineEdit();
  addButton = new QPushButton (QString::fromUtf8("Raum hinzufügen"), this);
  saveButton = new QPushButton ("Zurück zum Hauptmenü");

  this->setMainWindowDesign();
  this->setMainLayoutDesign();

  QObject::connect(addButton, SIGNAL(clicked()), this, SLOT(setNewRoomCalled()));
  QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(homePageCalled()));
  QObject::connect(giveNameEdit, SIGNAL(returnPressed()), this, SLOT(setNewRoomCalled()));         //Enter as conformation

  this->setGeometry(
      QStyle::alignedRect(
          Qt::LeftToRight,
          Qt::AlignCenter,
          this->size(),
          qApp->desktop()->availableGeometry()
      )
  );
}

void SetUpRooms::setMainWindowDesign() {
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Räume Verwalten"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(scrollAreaRow);
    mainLayout->addLayout(addRoomsRow);
    mainLayout->addLayout(mainButtonsRow);
    this->setLayout(mainLayout);
}

void SetUpRooms::setMainLayoutDesign() {

    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: Arial; font-size: 30px;"
                                   "font-weight: bold; margin-top: 5px; color: #555;");

    this->scrollAreaRow->addWidget(scrollArea);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollWidget->setLayout(this->scrollLayout);
    this->scrollLayout->setAlignment(Qt::AlignTop);
    this->scrollArea->setWidgetResizable(true);


    this->addRoomsRow->addWidget(roomTypeLabel);
    this->addRoomsRow->addWidget(chooseRoomTypeCombo);
    this->chooseRoomTypeCombo->setFixedWidth(120);
    this->roomTypeLabel->setStyleSheet("color: #555; font-weight: bold;");
    this->chooseRoomTypeCombo->setStyleSheet("selection-color: white; selection-background-color: #1aa3ff;"
                                             " color: black; background-color: White;");

    QStringList rooms;
    rooms << "Bad" << QString::fromUtf8("Küche") << "Wohnzimmer" << "Flur";
    chooseRoomTypeCombo->addItems(rooms);

    this->addRoomsRow->addWidget(nameLabel);
    this->addRoomsRow->addWidget(giveNameEdit);
    this->giveNameEdit->setMaxLength(18);
    this->nameLabel->setStyleSheet("color: #555; font-weight: bold;");
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

std::string SetUpRooms::getRoomTypeInput() {
    return this->chooseRoomTypeCombo->currentText().toStdString();
}

std::string SetUpRooms::getRoomNameInput() {
    //proceed only with a room name
    if(this->giveNameEdit->text().size() == 0 || this->giveNameEdit->text()[0] == ' '){
        return "Error";
    }

    return this->giveNameEdit->text().toStdString();
}

void SetUpRooms::deepDeleteLayout(QLayout *layout) {
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

void SetUpRooms::appear(std::vector<std::string> nameVec, std::vector<std::string> typeVec, int size) {
    deepDeleteLayout(scrollLayout);

    for(int i = 0; i < size; i++) {
        newRoom = new RoomListItem(QString::fromStdString(nameVec[i]), QString::fromStdString(typeVec[i]));

        // so every RoomListItem is connected..
        connect(newRoom, SIGNAL(deleteRoomSignal(QString)), this, SLOT(deleteRoomCalled(QString)));

        scrollLayout->addWidget(newRoom);
    }

     giveNameEdit->clear();
     this->show();
}

void SetUpRooms::setNewRoomCalled() {
    emit setNewRoomSignal();
}

void SetUpRooms::homePageCalled() {
    emit homePageCallSignal();
}

void SetUpRooms::deleteRoomCalled(QString name) {
    emit deleteRoomSignal(name);
}
