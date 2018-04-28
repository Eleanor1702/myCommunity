#include "userInterface/lib/setUpRooms.h"


//calling the constructor, calls the parent constructor too
//in this case QWidget
SetUpRooms::SetUpRooms(QWidget *parent) : QWidget(parent){

  //declarations of window contents
  scrollArea = new QScrollArea(this);
  scrollWidget = new QWidget(this);
  mainLabel = new QLabel("Let's add your WG Rooms..");
  mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
  scrollAreaRow = new QBoxLayout(QBoxLayout::LeftToRight);
  addRoomsRow = new QBoxLayout(QBoxLayout::LeftToRight);
  mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
  addButton = new QPushButton (QString::fromUtf8("Raum hinzufügen"), this);
  roomTypeLabel = new QLabel("Art:");
  chooseRoomTypeCombo = new QComboBox();
  nameLabel = new QLabel("Name:");
  giveNameEdit = new QLineEdit();
  saveButton = new QPushButton ("Speichern");


  this->setMainWindowDesign();
  this->setMainLayoutDesign();

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
    this->scrollArea->setWidgetResizable(true);

    this->addRoomsRow->addWidget(roomTypeLabel);
    this->addRoomsRow->addWidget(chooseRoomTypeCombo);

    QStringList rooms;
    rooms << "Bad" << QString::fromUtf8("Küche") << "Wohnzimmer" << "Flur";
    chooseRoomTypeCombo->addItems(rooms);

    this->addRoomsRow->addWidget(nameLabel);
    this->addRoomsRow->addWidget(giveNameEdit);

    this->mainButtonsRow->addWidget(addButton);
    addButton->setFixedSize(200, 50);
    addButton->setStyleSheet("background-color: red");

    this->mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(200, 50);
    saveButton->setStyleSheet("background-color: green");
}

void SetUpRooms::Button_add_clicked(){
  this->addButton->setText("Clicked");
   /* QString help = artWaehlen->currentText();
    string text = hilf.toUtf8().constData();

    hilf = nameEingeben->text();
    string text2 = hilf.toUtf8().constData();
    //WG wg;
    //wg.raumErstellen(text, text2);
*/
}

