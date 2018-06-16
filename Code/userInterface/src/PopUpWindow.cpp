#include "../lib/PopUpWindow.h"

PopUpWindow::PopUpWindow(QWidget* parent) : QWidget(parent) {
    mainLayout =  new QBoxLayout(QBoxLayout::TopToBottom);

    labelRow = new QBoxLayout(QBoxLayout::TopToBottom);
    mainLabel = new QLabel();

    msgRow = new QBoxLayout(QBoxLayout::TopToBottom);
    msgLabel = new QLabel();

    buttonRow = new QBoxLayout(QBoxLayout::TopToBottom);
    okButton = new QPushButton("Confirm");

    QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(close()));

    setMainWindowDesign();
    setMainLayoutDesign();
}

PopUpWindow::~PopUpWindow(){
    this->close();
}

void PopUpWindow::setMainWindowDesign() {
    this->setFixedSize(450, 250);
    this->setStyleSheet("background-color: #FFFAF0");
    this->setWindowTitle(QString::fromStdString("Confirmation"));

    mainLayout->addLayout(labelRow);
    mainLayout->addLayout(msgRow);
    mainLayout->addLayout(buttonRow);
    this->setLayout(mainLayout);
}

void PopUpWindow::setMainLayoutDesign() {
    mainLabel->setText("Danke! Deine Credentials \nsind erfolgreich gespeichert.");
    labelRow->addWidget(mainLabel, 0 , Qt::AlignCenter);
    mainLabel->setAlignment(Qt::AlignCenter);
    mainLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #4169E1;"
                             "font-family: monospace;");

    msgLabel->setText("Bitte starten Sie das Programm neu, \ndamit die"
                      " neue Konfiguration angewendet werden kann.");
    msgLabel->setAlignment(Qt::AlignCenter);
    msgLabel->setStyleSheet("font-size: 12px; color: #FF0000;"
                            "font-family: monospace; margin-bottom: 3px;");
    msgRow->addWidget(msgLabel, 0, Qt::AlignCenter);

    okButton->setText("Confirm");
    buttonRow->addWidget(okButton, 0 ,Qt::AlignCenter);
    okButton->setFixedSize(200, 50);
    okButton->setStyleSheet("margin-bottom: 15px; font-size: 10px;"
                             "font-family: monospace; color: #F5FFFA;"
                             "background: #191970; font-weight: bold;");
}
