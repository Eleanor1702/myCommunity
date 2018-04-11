#include "lib/mainscreen.h"

MainScreen::MainScreen() {}

void MainScreen::setMainScreenDesign(){
    this->mainWindow.setFixedSize(800, 600);
    this->mainWindow.setStyleSheet("background-color: black;");
}

void MainScreen::setTaskbarButtonDesign(QPushButton *button){
    button->setFixedSize(100, 100);
    button->setStyleSheet("background-color: white");
}

void MainScreen::addTaskbar() {
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->setContentsMargins(3, 3, 3, 3);

    QPushButton *profile = new QPushButton ("Profile");
    layout->addWidget(profile);
    this->setTaskbarButtonDesign(profile);

    QPushButton *shoppingList = new QPushButton ("Shopping List");
    layout->addWidget(shoppingList);
    this->setTaskbarButtonDesign(shoppingList);

    QPushButton *cleaningList = new QPushButton ("Cleaning List");
    layout->addWidget(cleaningList);
    this->setTaskbarButtonDesign(cleaningList);

    QPushButton *saveFile = new QPushButton ("Save File");
    layout->addWidget(saveFile);
    this->setTaskbarButtonDesign(saveFile);

    QPushButton *noDisturb = new QPushButton ("Don't Disturb");
    layout->addWidget(noDisturb);
    this->setTaskbarButtonDesign(noDisturb);

    QPushButton *logOut = new QPushButton ("Log Out");
    layout->addWidget(logOut);
    this->setTaskbarButtonDesign(logOut);

    this->mainWindow.setLayout(layout);

}

void MainScreen::run() {
    this->setMainScreenDesign();
    this->addTaskbar();
    this->mainWindow.show();
}


