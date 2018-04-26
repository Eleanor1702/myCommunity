#include "userInterface/lib/setUpRooms.h"

SetUpRooms::SetUpRooms(){}

void SetUpRooms::setMainWindowDesign() {
    this->mainWindow.setFixedSize(700, 500);
    this->mainWindow.setStyleSheet("background-color: white;");
    this->mainWindow.setWindowTitle("Räume verwalten");
    mainLayout->addLayout(row1);
    mainLayout->addLayout(row2);
    mainLayout->addLayout(row3);
    mainLayout->addLayout(row4);
    mainWindow.setLayout(mainLayout);
}

void SetUpRooms::setMainLayoutDesign() {

    this->row1->addWidget(this->mainLabel, 0, Qt::AlignTop);


    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollArea->setWidgetResizable(true);
    this->row2->addWidget(scrollArea);


    QLabel *art = new QLabel();
    art->setText("Art:");
    row3->addWidget(art);

    QComboBox *chooseArt = new QComboBox();
    row3->addWidget(chooseArt);
    QStringList rooms;
    rooms << "Bad" << "Kueche" << "Wohnzimmer" << "Flur";
    chooseArt->addItems(rooms);

    QLabel *name = new QLabel();
    name->setText("Name:");
    row3->addWidget(name);

    QLineEdit *giveName = new QLineEdit();
    row3->addWidget(giveName);
    name->setBuddy(giveName);

    QPushButton *add = new QPushButton ("Raum hinzufügen", &mainWindow);
    this->row4->addWidget(add);
    add->setFixedSize(200, 50);
    add->setStyleSheet("background-color: red");

    QPushButton *save = new QPushButton ("Speichern");
    this->row4->addWidget(save);
    save->setFixedSize(200, 50);
    save->setStyleSheet("background-color: green");

    //Click on "Raum hinzufügen"
    QObject::connect(add,SIGNAL(clicked()),&mainWindow,SLOT(Button_add_clicked(chooseArt, giveName)));

}

void SetUpRooms::setMainLabelDesign() {
    this->mainLabel->setText("Let's add your WG Rooms..");
    this->mainLabel->setAlignment(Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L;"
                                   "font-size: 30px; font-weight: bold;"
                                   "margin-top: 20px;");
}

//scroll area commands under working
/*void SetUpRooms::setRoomsLayoutDesign() {
  this->scrollArea->setAlignment(Qt::AlignCenter);
  this->scrollArea->setFixedHeight(300);
  this->scrollArea->setFixedWidth(600);
  this->scrollWidget->setLayout(this->mainLayout);
  this->scrollArea->setWidget(this->scrollWidget);
  this->scrollArea->setWidgetResizable(true);
}
*/
void SetUpRooms::run() {
    this->setMainWindowDesign();
    this->setMainLayoutDesign();
    this->setMainLabelDesign();
    this->mainWindow.show();
}

void SetUpRooms::Button_add_clicked(QComboBox* artWaehlen, QLineEdit* nameEingeben){
    QString hilf = artWaehlen->currentText();
    string text = hilf.toUtf8().constData();

    hilf = nameEingeben->text();
    string text2 = hilf.toUtf8().constData();
    //WG wg;
    //wg.raumErstellen(text, text2);

}

