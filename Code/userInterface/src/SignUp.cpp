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

  mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
  backButton = new QPushButton (QString::fromUtf8("Zurück"), this);
  saveButton = new QPushButton ("Speichern");

  this->setMainWindowDesign();
  this->setMainLayoutDesign();

  QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(startPageCalled()));
  QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(saveClicked()));
}

void SignUp::setMainWindowDesign() {
    this->setFixedSize(700, 500);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Registrieren"));

    this->mainLayout->addLayout(mainLabelRow);
    this->mainLayout->addLayout(imageRow);
    this->mainLayout->addLayout(nameRow);
    this->mainLayout->addLayout(passwordRow);
    this->mainLayout->addLayout(mainButtonsRow);
    this->setLayout(mainLayout);
}

void SignUp::setMainLayoutDesign() {
    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 30px; color: #aaa;");

    this->imageRow->addWidget(this->picLabel, 0, Qt::AlignVCenter);
    scaled = this->pic->scaled(130, 130, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    this->picLabel->setPixmap(scaled);
    this->picLabel->setFixedSize(200, 200);
    this->picLabel->setAlignment(Qt::AlignCenter);

    this->nameRow->addWidget(nameLabel, 4, Qt::AlignRight);
    this->nameRow->addWidget(giveNameEdit, 11, Qt::AlignLeft);
    this->giveNameEdit->setMaxLength(18);
    this->giveNameEdit->setFixedWidth(300);
    this->nameLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    this->giveNameEdit->setStyleSheet("margin-left: 10px; color: black;");

    this->passwordRow->addWidget(passwordLabel, 4, Qt::AlignRight);
    this->passwordRow->addWidget(givePasswordEdit, 11, Qt::AlignLeft);
    this->givePasswordEdit->setEchoMode(QLineEdit::Password);
    this->givePasswordEdit->setMaxLength(4);
    this->givePasswordEdit->setFixedWidth(300);
    this->givePasswordEdit->setValidator( new QIntValidator(0, 10000, this));
    this->givePasswordEdit->setStyleSheet("margin-left: 10px; margin-bottom: 0px; color: black;");
    this->passwordLabel->setStyleSheet("margin-top: 0px; margin-bottom: 10px; color: #aaa; font-weight: bold;");

    this->mainButtonsRow->addWidget(backButton);
    backButton->setFixedSize(200, 50);
    backButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                             "border-radius: 5px; background-color: #3399ff; "
                             "color: white; font-weight: bold;}");

    this->mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(200, 50);
    saveButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                              "border-radius: 5px; background-color: #00b300; "
                              "color: white; font-weight: bold;}");
}

void SignUp::clearContent() {
    this->giveNameEdit->clear();
    this->givePasswordEdit->clear();
}

std::string SignUp::getUserName() {
    QString name = this->giveNameEdit->text();

    if(name.size() == 0 || name[0] == ' ') {
        return "Error";
    }

    std::string strName = name.toUtf8().constData();

    return strName;
}

int SignUp::getUserPassword() {
    QString password = this->givePasswordEdit->text();

    if(password.size() < 4 || password[0] == ' ') {
        return 1;
    }

    int intPassword = password.toInt();

    return intPassword;
}

void SignUp::startPageCalled() {
    emit startPageCallSignal();
    clearContent();
}

void SignUp::saveClicked() {
    //whether Input of name or password is acceptable
    if(getUserName() == "Error" || getUserPassword() == 1) {
        //Error message, maybe?
    }else{
        emit newUserSignUpSignal(getUserName(), getUserPassword());
        clearContent();
    }
}
