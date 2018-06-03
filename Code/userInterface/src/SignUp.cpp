#include "userInterface/lib/SignUp.h"

//calling the constructor, calls the parent constructor too
//in this case QWidget
SignUp::SignUp(QWidget *parent) : QWidget(parent) {
    //declarations of window contents
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Registrieren");

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

    mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
    backButton = new QPushButton (QString::fromUtf8("Zurück"), this);
    saveButton = new QPushButton ("Speichern");

    setMainWindowDesign();
    setMainLayoutDesign();

    QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(startPageCalled()));
    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(saveClicked()));
}

void SignUp::setMainWindowDesign() {
    this->setFixedSize(700, 500);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Registrieren"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(imageRow);
    mainLayout->addLayout(nameRow);
    mainLayout->addLayout(passwordRow);
    mainLayout->addLayout(errorMsgRow);
    mainLayout->addLayout(mainButtonsRow);
    this->setLayout(mainLayout);
}

void SignUp::setMainLayoutDesign() {
    mainLabelRow->addWidget(mainLabel, 0, Qt::AlignCenter);
    mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 30px; color: #aaa;");

    imageRow->addWidget(picLabel, 0, Qt::AlignVCenter);
    scaled = pic->scaled(130, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    picLabel->setPixmap(scaled);
    picLabel->setFixedSize(200, 200);
    picLabel->setAlignment(Qt::AlignCenter);

    nameRow->addWidget(nameLabel, 4, Qt::AlignRight);
    nameRow->addWidget(giveNameEdit, 11, Qt::AlignLeft);
    giveNameEdit->setMaxLength(18);
    giveNameEdit->setFixedWidth(300);
    nameLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    giveNameEdit->setStyleSheet("margin-left: 10px; color: black;");

    passwordRow->addWidget(passwordLabel, 4, Qt::AlignRight);
    passwordRow->addWidget(givePasswordEdit, 11, Qt::AlignLeft);
    givePasswordEdit->setEchoMode(QLineEdit::Password);
    givePasswordEdit->setMaxLength(4);
    givePasswordEdit->setFixedWidth(300);
    givePasswordEdit->setValidator(new QIntValidator(0, 10000, this));
    givePasswordEdit->setStyleSheet("margin-left: 10px; margin-bottom: 0px; color: black;");
    passwordLabel->setStyleSheet("margin-top: 0px; margin-bottom: 10px; color: #aaa; "
                                 "font-weight: bold;");

    errorMsgRow->addWidget(errorMsgLabel, 0, Qt::AlignCenter);
    errorMsgLabel->setStyleSheet("font-weight: bold; color:red");
    errorMsgLabel->hide();

    mainButtonsRow->addWidget(backButton);
    backButton->setFixedSize(200, 50);
    backButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                             "border-radius: 5px; background-color: #3399ff; "
                             "color: white; font-weight: bold;}");

    mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(200, 50);
    saveButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                              "border-radius: 5px; background-color: #00b300; "
                              "color: white; font-weight: bold;}");
}

void SignUp::appear() {
    clearContent();
    this->show();
}

void SignUp::clearContent() {
    giveNameEdit->clear();
    givePasswordEdit->clear();
    errorMsgLabel->hide();
}

void SignUp::usernameExist() {
    errorMsgLabel->setText("Username already exist");
    errorMsgLabel->show();
}

void SignUp::validate() {
    QString name = giveNameEdit->text();
    QString password = givePasswordEdit->text();

    bool passwordError = password.size() < 4 || password[0] == ' ';
    bool userNameError = name.size() == 0 || name[0] == ' ';

    if(passwordError && userNameError){
        throw std::string("Please enter a valid username and password");
    }else if(passwordError) {
        throw std::string("Password does not meet password policy requirements");
    }else if(userNameError){
        throw std::string("This is not a valid username");
    }
}

void SignUp::startPageCalled() {
    emit startPageCallSignal();
    clearContent();
}

void SignUp::saveClicked() {
    try {
        validate();
    }

    catch (std::string error) {
        errorMsgLabel->setText(QString::fromStdString(error));
        errorMsgLabel->show();
        return;
    }

    std::string userName = giveNameEdit->text().toUtf8().constData();
    int password = givePasswordEdit->text().toInt();

    emit newUserSignUpSignal(userName, password);
}
