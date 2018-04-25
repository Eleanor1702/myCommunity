#include "userInterface/lib/setUpRooms.h"

SetUpRooms::SetUpRooms() {}

void SetUpRooms::setMainWindowDesign() {
    this->mainWindow.setFixedSize(700, 500);
    this->mainWindow.setStyleSheet("background-color: white;");
    this->mainWindow.setWindowTitle("Räume verwalten");
    mainLayout->addLayout(zeile1);
    mainLayout->addLayout(zeile2);
    mainLayout->addLayout(zeile3);
    mainWindow.setLayout(mainLayout);
}

void SetUpRooms::setMainLayoutDesign() {
    this->zeile1->addWidget(this->mainLabel, 0, Qt::AlignTop);

    QLabel *art = new QLabel();
    art->setText("Art:");
    zeile2->addWidget(art);

    QComboBox *artWaehlen = new QComboBox();
    zeile2->addWidget(artWaehlen);
    QStringList raeume;
    raeume << "Bad" << "Küche" << "Wohnzimmer" << "Flur";
    artWaehlen->addItems(raeume);

    QLabel *name = new QLabel();
    name->setText("Name:");
    zeile2->addWidget(name);

    QLineEdit *nameEingeben = new QLineEdit();
    zeile2->addWidget(nameEingeben);
    name->setBuddy(nameEingeben);

    QPushButton *hinzufuegen = new QPushButton ("Raum hinzufügen");
    this->zeile3->addWidget(hinzufuegen);
    hinzufuegen->setFixedSize(200, 50);
    hinzufuegen->setStyleSheet("background-color: red");

    QPushButton *speichern = new QPushButton ("Speichern");
    this->zeile3->addWidget(speichern);
    speichern->setFixedSize(200, 50);
    speichern->setStyleSheet("background-color: green");
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


