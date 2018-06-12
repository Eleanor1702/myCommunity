#include "../lib/SetUpConfiguration.h"

SetUpConfiguration::SetUpConfiguration(QWidget *parent) : QWidget(parent) {
    //declaration of windows contents
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel();

    buttonRow = new QBoxLayout(QBoxLayout::TopToBottom);
    localHost = new QPushButton("Auf meinem Computer");
    ownServer = new QPushButton("Auf einem anderen Computer");

    //Localhost Setup:
    userRow = new QBoxLayout(QBoxLayout::LeftToRight);
    hostRow = new QBoxLayout(QBoxLayout::LeftToRight);
    passwordRow = new QBoxLayout(QBoxLayout::LeftToRight);
    databaseRow = new QBoxLayout(QBoxLayout::LeftToRight);

    userLabel = new QLabel();
    hostLabel = new QLabel();
    passwordLabel = new QLabel();
    databaseLabel = new QLabel();

    userInput = new QLineEdit();
    hostInput = new QLineEdit();
    passwordInput = new QLineEdit();
    databaseInput = new QLineEdit();

    localButtonRow = new QBoxLayout(QBoxLayout::RightToLeft);
    confirmButton = new QPushButton("Submit");
    cancelButton = new QPushButton("cancel");

    QObject::connect(localHost, SIGNAL(clicked()), this, SLOT(setLocalHost()));
    QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(callConfigHome()));

    this->setMainWindowDesign();
    this->setMainLayoutDesign();
}

void SetUpConfiguration::setMainWindowDesign() {
    this->setFixedSize(500, 300);
    this->setStyleSheet("background-color: #000080");
    this->setWindowTitle(QString::fromStdString("MySQL Server Configuration"));

    this->setLayout(mainLayout);
}

void SetUpConfiguration::setMainLayoutDesign() {
    mainLabelRow->addWidget(mainLabel, 0, Qt::AlignCenter);
    mainLabel->setText("Wo ist dein MySQL Server?");
    mainLabel->setStyleSheet("margin-top: 0px; font-size: 20px;"
                             "font-weight: bold; color: #4169E1;"
                             "font-family: monospace;");

    mainLayout->addLayout(mainLabelRow);

    buttonRow->addWidget(localHost, 0, Qt::AlignCenter);
    localHost->setFixedSize(200, 50);
    localHost->setStyleSheet("margin-bottom: 15px; font-size: 10px;"
                             "font-family: monospace; color: #F5FFFA;"
                             "background: #191970; font-weight: bold;");

    buttonRow->addWidget(ownServer, 0, Qt::AlignCenter);
    ownServer->setFixedSize(200, 50);
    ownServer->setStyleSheet("margin-bottom: 15px; font-size: 10px;"
                             "font-family: monospace; color: #F5FFFA;"
                             "background: #191970; font-weight: bold;");

    mainLayout->addLayout(buttonRow);
}

void SetUpConfiguration::setLocalHost() {
    mainLabel->setText("Please set your credentials:");

    userRow->addWidget(userLabel, 2, Qt::AlignCenter);
    userLabel->setText("User: ");
    userLabel->setStyleSheet("font-size: 10px; font-weight: bold; "
                             "color: #4169E1; font-family: monospace;");
    userRow->addWidget(userInput, 4, Qt::AlignCenter);
    userInput->setFixedSize(300, 20);
    userInput->setStyleSheet("color: white;");
    mainLayout->addLayout(userRow);

    hostRow->addWidget(hostLabel, 2, Qt::AlignCenter);
    hostLabel->setText("Host: ");
    hostLabel->setStyleSheet("font-size: 10px; font-weight: bold; "
                             "color: #4169E1; font-family: monospace;");
    hostRow->addWidget(hostInput, 4, Qt::AlignCenter);
    hostInput->setText("localhost");
    hostInput->setDisabled(true);
    hostInput->setFixedSize(300, 20);
    hostInput->setStyleSheet("color: white;");
    mainLayout->addLayout(hostRow);

    passwordRow->addWidget(passwordLabel, 2, Qt::AlignCenter);
    passwordLabel->setText("Password: ");
    passwordLabel->setStyleSheet("font-size: 10px; font-weight: bold; "
                             "color: #4169E1; font-family: monospace;");
    passwordRow->addWidget(passwordInput, 4, Qt::AlignCenter);
    passwordInput->setFixedSize(300, 20);
    passwordInput->setStyleSheet("color: white;");
    passwordInput->setEchoMode(QLineEdit::Password);
    mainLayout->addLayout(passwordRow);

    databaseRow->addWidget(databaseLabel, 2, Qt::AlignCenter);
    databaseLabel->setText("Database: ");
    databaseLabel->setStyleSheet("font-size: 10px; font-weight: bold; "
                             "color: #4169E1; font-family: monospace;");
    databaseRow->addWidget(databaseInput, 4, Qt::AlignCenter);
    databaseInput->setFixedSize(300, 20);
    databaseInput->setStyleSheet("color: white;");
    mainLayout->addLayout(databaseRow);

    mainLayout->removeItem(buttonRow);

    localButtonRow->addWidget(confirmButton, 0, Qt::AlignCenter);
    confirmButton->setFixedSize(100, 50);
    confirmButton->setStyleSheet("margin-bottom: 15px; font-size: 10px;"
                                 "font-family: monospace; color: #F5FFFA;"
                                 "background: #191970; font-weight: bold;");
    localButtonRow->addWidget(cancelButton, 0, Qt::AlignCenter);
    cancelButton->setFixedSize(100, 50);
    cancelButton->setStyleSheet("margin-bottom: 15px; font-size: 10px;"
                                "font-family: monospace; color: #F5FFFA;"
                                "background: #191970; font-weight: bold;");
    mainLayout->addLayout(localButtonRow);
}

void SetUpConfiguration::callConfigHome() {
    setMainLayoutDesign();
}
