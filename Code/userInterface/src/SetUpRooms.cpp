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
  QObject::connect(addButton,SIGNAL(clicked()),this,SLOT(Button_add_clicked()));

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

    QStringList rooms;
    rooms << "Bad" << QString::fromUtf8("Küche") << "Wohnzimmer" << "Flur";
    chooseRoomTypeCombo->addItems(rooms);

    this->addRoomsRow->addWidget(nameLabel);
    this->addRoomsRow->addWidget(giveNameEdit);
    giveNameEdit->setMaxLength(30);

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

void SetUpRooms::Button_add_clicked(){
  QString roomType = chooseRoomTypeCombo->currentText();
  QString roomName = giveNameEdit->text();

  QLabel *room = new QLabel(roomType + " - " + roomName);
  room->setFixedSize(450, 30);
  room->setStyleSheet("text-align: center; font-size: 20px;");

  QPushButton *editButton = new QPushButton("Bearbeiten");
  editButton->setFixedHeight(30);
  editButton->setStyleSheet(".QPushButton{border: 1px solid #00b8e6;"
                            "border-radius: 5px; background-color: #00b8e6;"
                            "color: white;}");

  QPushButton *deleteButton = new QPushButton(QString::fromUtf8("Löschen"));
  deleteButton->setFixedHeight(30);
  deleteButton->setStyleSheet(".QPushButton{border: 1px solid red;"
                              "border-radius: 5px; background-color: red;"
                              " color: white;}");

  QFrame *newRoom = new QFrame();
  newRoom->setFixedHeight(50);
  newRoom->setStyleSheet(".QFrame{border: 1px solid #aaa; border-radius: 5px;}");

  QHBoxLayout *newRoomLayout = new QHBoxLayout();
  newRoom->setLayout(newRoomLayout);
  newRoomLayout->addWidget(room);
  newRoomLayout->addWidget(editButton);
  newRoomLayout->addWidget(deleteButton);

  this->scrollLayout->addWidget(newRoom);

   /* QString help = artWaehlen->currentText();
    string text = hilf.toUtf8().constData();

    hilf = nameEingeben->text();
    string text2 = hilf.toUtf8().constData();
    //WG wg;
    //wg.raumErstellen(text, text2);
*/
}

