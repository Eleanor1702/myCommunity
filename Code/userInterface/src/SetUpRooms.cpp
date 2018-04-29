#include "userInterface/lib/setUpRooms.h"


//calling the constructor, calls the parent constructor too
//in this case QWidget
SetUpRooms::SetUpRooms(QWidget *parent) : QWidget(parent){

  //declarations of window contents
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainLabel = new QLabel("Let's add your WG Rooms..");

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
  saveButton = new QPushButton ("Speichern");

  this->setMainWindowDesign();
  this->setMainLayoutDesign();

  //Events
  QObject::connect(addButton,SIGNAL(clicked()),this,SLOT(addButtonClicked()));

}

void SetUpRooms::setMainWindowDesign() {
    this->setFixedSize(700, 500);
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
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 5px;");

    this->scrollAreaRow->addWidget(scrollArea);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollWidget->setLayout(this->scrollLayout);
    this->scrollLayout->setAlignment(Qt::AlignTop);
    this->scrollArea->setWidgetResizable(true);


    this->addRoomsRow->addWidget(roomTypeLabel);
    this->addRoomsRow->addWidget(chooseRoomTypeCombo);
    this->chooseRoomTypeCombo->setFixedWidth(120);
    this->chooseRoomTypeCombo->setStyleSheet("selection-color: white; "
                                             "selection-background-color: #1aa3ff");

    QStringList rooms;
    rooms << "Bad" << QString::fromUtf8("Küche") << "Wohnzimmer" << "Flur";
    chooseRoomTypeCombo->addItems(rooms);

    this->addRoomsRow->addWidget(nameLabel);
    this->addRoomsRow->addWidget(giveNameEdit);
    this->giveNameEdit->setMaxLength(18);

    this->mainButtonsRow->addWidget(addButton);
    addButton->setFixedSize(200, 50);
    addButton->setStyleSheet(".QPushButton{border: 1px solid red; "
                             "border-radius: 5px; background-color: red; "
                             "color: white;}");


    this->mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(200, 50);
    saveButton->setStyleSheet(".QPushButton{border: 1px solid green; "
                              "border-radius: 5px; background-color: green; "
                              "color: white;}");

}

void SetUpRooms::addButtonClicked(){
  QString roomType = chooseRoomTypeCombo->currentText();

  //proceed only with a room name

  QString roomName = giveNameEdit->text();
  if(roomName.size() == 0){
      return;
  }

  RoomListItem *newRoom = new RoomListItem(roomType + " - " + roomName);

  this->scrollLayout->addWidget(newRoom);

  this->giveNameEdit->clear();

   /* QString help = artWaehlen->currentText();
    string text = hilf.toUtf8().constData();

    hilf = nameEingeben->text();
    string text2 = hilf.toUtf8().constData();
    //WG wg;
    //wg.raumErstellen(text, text2);
*/
}
