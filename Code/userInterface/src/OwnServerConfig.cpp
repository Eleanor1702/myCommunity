#include "../lib/OwnServerConfig.h"

OwnServerConfig::OwnServerConfig(QWidget* parent) : QWidget(parent) {
    //declaration of windwos contents
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Bitte geben Sie Ihre Credentials ein:");

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

    warningLabelRow =  new QBoxLayout(QBoxLayout::TopToBottom);
    warnLabel = new QLabel();

    buttonRow = new QBoxLayout(QBoxLayout::RightToLeft);
    confirmButton = new QPushButton("Speichern");
    cancelButton = new QPushButton("Abbrechen");

    QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(callHome()));
    QObject::connect(confirmButton, SIGNAL(clicked()), this, SLOT(confirm()));

    this->setMainWindowDesign();
    this->setMainLayoutDesign();
}

OwnServerConfig::~OwnServerConfig() {
}

void OwnServerConfig::setMainWindowDesign() {
    this->setFixedSize(500, 300);
    this->setStyleSheet("background-color: #FFFAF0");
    this->setWindowTitle(QString::fromStdString("MySQL Server Konfiguration"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(userRow);
    mainLayout->addLayout(hostRow);
    mainLayout->addLayout(passwordRow);
    mainLayout->addLayout(databaseRow);
    mainLayout->addLayout(warningLabelRow);
    mainLayout->addLayout(buttonRow);
    this->setLayout(mainLayout);
}

void OwnServerConfig::setMainLayoutDesign() {
    mainLabelRow->addWidget(mainLabel, 0 , Qt::AlignCenter);
    mainLabel->setStyleSheet("font-size: 15px; font-weight: bold;"
                             "color: #4169E1; font-family: monospace;");
    userRow->addWidget(userLabel, 2, Qt::AlignCenter);
    userLabel->setText("User: ");
    userLabel->setStyleSheet("font-size: 10px; font-weight: bold; "
                             "color: #4169E1; font-family: monospace;");
    userRow->addWidget(userInput, 4, Qt::AlignCenter);
    userInput->setFixedSize(300, 20);
    userInput->setStyleSheet("color: #4169E1;");

    hostRow->addWidget(hostLabel, 2, Qt::AlignCenter);
    hostLabel->setText("Host: ");
    hostLabel->setStyleSheet("font-size: 10px; font-weight: bold; "
                             "color: #4169E1; font-family: monospace;");
    hostRow->addWidget(hostInput, 4, Qt::AlignCenter);
    hostInput->setFixedSize(300, 20);
    hostInput->setStyleSheet("color: #4169E1;");

    passwordRow->addWidget(passwordLabel, 2, Qt::AlignCenter);
    passwordLabel->setText("Passwort: ");
    passwordLabel->setStyleSheet("font-size: 10px; font-weight: bold; "
                             "color: #4169E1; font-family: monospace;");
    passwordRow->addWidget(passwordInput, 4, Qt::AlignCenter);
    passwordInput->setFixedSize(300, 20);
    passwordInput->setStyleSheet("color: #4169E1;");
    passwordInput->setEchoMode(QLineEdit::Password);

    databaseRow->addWidget(databaseLabel, 2, Qt::AlignCenter);
    databaseLabel->setText("Datenbank: ");
    databaseLabel->setStyleSheet("font-size: 10px; font-weight: bold; "
                             "color: #4169E1; font-family: monospace;");
    databaseRow->addWidget(databaseInput, 4, Qt::AlignCenter);
    databaseInput->setFixedSize(300, 20);
    databaseInput->setStyleSheet("color: #4169E1;");

    warningLabelRow->addWidget(warnLabel, 0, Qt::AlignCenter);
    warnLabel->setText("Bitte geben Sie Ihre Credentials ein!");
    warnLabel->setVisible(false);
    warnLabel->setStyleSheet("font-size: 12px; font-weight: bold;"
                             "color: #FF0000; font-family: monospace;");

    buttonRow->addWidget(confirmButton, 0, Qt::AlignCenter);
    confirmButton->setFixedSize(100, 50);
    confirmButton->setStyleSheet("margin-bottom: 15px; font-size: 10px;"
                                 "font-family: monospace; color: #F5FFFA;"
                                 "background: #191970; font-weight: bold;");
    buttonRow->addWidget(cancelButton, 0, Qt::AlignCenter);
    cancelButton->setFixedSize(100, 50);
    cancelButton->setStyleSheet("margin-bottom: 15px; font-size: 10px;"
                                "font-family: monospace; color: #F5FFFA;"
                                "background: #191970; font-weight: bold;");
}

void OwnServerConfig::callHome() {
    emit configHomeCalled();
}

void OwnServerConfig::confirm() {
    std::string user = userInput->text().toStdString();
    std::string host = hostInput->text().toStdString();
    std::string password = passwordInput->text().toStdString();
    std::string database = databaseInput->text().toStdString();

    if(user == "" || host == "" || password == "" || database == "") {
        warnLabel->setVisible(true);
        return;
    }

    emit sendCredentials(user, host, password, database);
}
