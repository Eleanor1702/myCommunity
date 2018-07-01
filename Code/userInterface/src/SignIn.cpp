#include "userInterface/lib/SignIn.h"

SignIn::SignIn(QWidget *parent) : QWidget (parent){
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Anmelden");

    imageRow = new QBoxLayout(QBoxLayout::RightToLeft);
    pic = new QPixmap(":/avatar.png");
    picLabel = new QLabel(this);

    nameRow = new QBoxLayout(QBoxLayout::LeftToRight);
    nameLabel = new QLabel("Name:");
    giveNameEdit = new QLineEdit();

    passwordRow = new QBoxLayout(QBoxLayout::LeftToRight);
    passwordLabel = new QLabel("Passwort:");
    givePasswordEdit = new QLineEdit();

    errorMsgRow = new QBoxLayout(QBoxLayout::LeftToRight);
    errorMsgLabel = new QLabel();

    buttonsRow = new QBoxLayout(QBoxLayout::RightToLeft);
    backButton = new QPushButton(QString::fromUtf8("Zurück"));
    logInButton = new QPushButton("Anmelden");

    this->setMainWindowDesign();
    this->setMainLayoutDesign();
    this->setGeometry(        // To center window
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(mainScreenCalled()));
    QObject::connect(logInButton, SIGNAL(clicked()), this, SLOT(userLogedIn()));
    QObject::connect(givePasswordEdit, SIGNAL(returnPressed()), this, SLOT(userLogedIn()));     //Enter as confirmation
    QObject::connect(giveNameEdit, SIGNAL(returnPressed()), this, SLOT(userLogedIn()));         //Enter as conformation

}

void SignIn::setMainWindowDesign() {
    this->setFixedSize(700, 500);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Anmelden"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(imageRow);
    mainLayout->addLayout(nameRow);
    mainLayout->addLayout(passwordRow, Qt::AlignCenter);
    mainLayout->addLayout(errorMsgRow);
    mainLayout->addLayout(buttonsRow);
    this->setLayout(mainLayout);
}

void SignIn::setMainLayoutDesign() {
    mainLabelRow->addWidget(mainLabel, 0, Qt::AlignCenter);
    mainLabel->setStyleSheet("font-family: Arial; font-size: 30px;"
                                   "font-weight: bold; margin-top: 30px; color: #555;");

    imageRow->addWidget(picLabel, 0, Qt::AlignVCenter);
    scaled = pic->scaled(130, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    picLabel->setPixmap(scaled);
    picLabel->setFixedSize(200, 200);
    picLabel->setAlignment(Qt::AlignCenter);

    nameRow->addWidget(nameLabel, 4 , Qt::AlignRight);
    nameLabel->setStyleSheet("font-weight: bold; color: #555;");
    nameRow->addWidget(giveNameEdit, 11, Qt::AlignLeft);
    giveNameEdit->setMaxLength(18);
    giveNameEdit->setFixedWidth(300);
    //left margin keep space between label and LineEdit
    giveNameEdit->setStyleSheet("margin-left: 10px; color: black;");


    passwordRow->addWidget(passwordLabel, 4, Qt::AlignRight);
    passwordLabel->setStyleSheet("margin-top: 0px; margin-bottom: 10px; color: #555; "
                                 "font-weight: bold;");
    passwordRow->addWidget(givePasswordEdit, 11 , Qt::AlignLeft);
    givePasswordEdit->setEchoMode(QLineEdit::Password);
    givePasswordEdit->setMaxLength(4);
    givePasswordEdit->setFixedWidth(300);
    givePasswordEdit->setValidator( new QIntValidator(0, 10000, this));
    //these Margins are for the design of both label and lineEdit
    //the bottom margin keep space between passwordRow and buttons
    //left margin keep space between label and lineEdit
    givePasswordEdit->setStyleSheet("margin-left: 10px; margin-bottom: 0px; color: black;");


    errorMsgRow->addWidget(errorMsgLabel, 0, Qt::AlignCenter);
    errorMsgLabel->setStyleSheet("font-weight: bold; color:red");
    errorMsgLabel->hide();

    buttonsRow->addWidget(logInButton);
    logInButton->setFixedSize(200, 50);
    logInButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                               "border-radius: 5px; background-color: #00b300; "
                               "color: white; font-weight: bold;}");

    buttonsRow->addWidget(backButton);
    backButton->setFixedSize(200, 50);
    backButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                              "border-radius: 5px; background-color: #3399ff; "
                              "color: white; font-weight: bold;}");
}

void SignIn::appear() {
    clearContent();
    this->show();
}

void SignIn::clearContent() {
    giveNameEdit->clear();
    givePasswordEdit->clear();
    errorMsgLabel->hide();
}

void SignIn::falseData() {
    givePasswordEdit->clear();
    errorMsgLabel->setText("invalid username or password");
    errorMsgLabel->show();
}

void SignIn::validate() {
    QString name = giveNameEdit->text();
    QString password = givePasswordEdit->text();

    bool passwordError = password.size() == 0;
    bool userNameError = name.size() == 0;

    if(passwordError && userNameError){
        throw std::string("Login Invalid");
    }else if(passwordError) {
        throw std::string("Please enter a valid password");
    }else if(userNameError){
        throw std::string("Please enter a valid username");
    }
}

std::string SignIn::getUserName() {
    QString name = this->giveNameEdit->text();

    std::string strName = name.toUtf8().constData();

    return strName;
}

int SignIn::getUserPassword() {
    QString password = this->givePasswordEdit->text();

    int intPassword = password.toInt();

    return intPassword;
}

void SignIn::mainScreenCalled() {
    emit mainScreenCallSignal();
    clearContent();
}

void SignIn::userLogedIn() {
    try{
        validate();
    }

    catch (std::string error) {
        errorMsgLabel->setText(QString::fromStdString(error));
        errorMsgLabel->show();
        return;
    }

    std::string userName = giveNameEdit->text().toUtf8().constData();
    int password = givePasswordEdit->text().toInt();

    emit userLogInSignal(userName, password);
}
