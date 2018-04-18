#include "userInterface/lib/startpage.h"

StartPage::StartPage() {}

void StartPage::setInterfaceDesign() {
    this->interface.setFixedSize(700, 500);
    this->interface.setStyleSheet("background-color: black;");
}

void StartPage::run() {
    this->setInterfaceDesign();
    this->interface.show();
}


