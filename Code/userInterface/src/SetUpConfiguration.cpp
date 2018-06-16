#include "../lib/SetUpConfiguration.h"

SetUpConfiguration::SetUpConfiguration(QWidget *parent) : QWidget(parent) {
    //declaration of windows contents
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Wo ist dein MySQL Server?");

    buttonRow = new QBoxLayout(QBoxLayout::TopToBottom);
    localHost = new QPushButton("Auf meinem Computer");
    ownServer = new QPushButton("Auf einem anderen Computer");

    QObject::connect(localHost, SIGNAL(clicked()), this, SLOT(callLocalHost()));
    QObject::connect(ownServer, SIGNAL(clicked()), this, SLOT(callOwnServer()));

    connect(&local, SIGNAL(configHomeCalled()), this, SLOT(callConfigHome()));
    connect(&local, SIGNAL(sendCredentials(std::string,std::string,std::string,std::string)), this, SLOT(saveCredentials(std::string, std::string, std::string, std::string)));
    connect(&server, SIGNAL(configHomeCalled()), this, SLOT(callConfigHome()));
    connect(&server, SIGNAL(sendCredentials(std::string,std::string,std::string,std::string)), this, SLOT(saveCredentials(std::string, std::string, std::string, std::string)));

    this->setMainWindowDesign();
    this->setMainLayoutDesign();
}

void SetUpConfiguration::setMainWindowDesign() {
    this->setFixedSize(500, 300);
    this->setStyleSheet("background-color: #FFFAF0");
    this->setWindowTitle(QString::fromStdString("MySQL Server Configuration"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(buttonRow);
    this->setLayout(mainLayout);
}

void SetUpConfiguration::setMainLayoutDesign() {
    mainLabelRow->addWidget(mainLabel, 0, Qt::AlignCenter);
    mainLabel->setStyleSheet("margin-top: 0px; font-size: 20px;"
                             "font-weight: bold; color: #4169E1;"
                             "font-family: monospace;");

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
}

void SetUpConfiguration::callConfigHome() {
    this->show();
    local.hide();
    server.close();
}

void SetUpConfiguration::callLocalHost() {
    local.show();
    this->hide();
}

void SetUpConfiguration::callOwnServer() {
    server.show();
    this->hide();
}

void SetUpConfiguration::saveCredentials(std::string user, std::string host, std::string password, std::string database) {
    config.write(user, host, password, database);
    config.read();

    popUp.show();
    this->close();
    local.close();
    server.close();
}
