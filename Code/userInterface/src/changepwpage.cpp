#include "userInterface/lib/changepwpage.h"

changePwPage::changePwPage(QWidget *parent) : QWidget(parent){
    //declerations of window contents
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLabelRow = new QBoxLayout(QBoxLayout::TopToBottom);
    mainLabel = new QLabel("Passwort ändern");

    oldPwRow = new QBoxLayout(QBoxLayout::LeftToRight);
    oldpwLabel = new QLabel("Altes Passwort:");
    giveOldpwEdit = new QLineEdit();

    newPwRow = new QBoxLayout(QBoxLayout::LeftToRight);
    newpwLabel = new QLabel("Neues Passwort:");
    giveNewpwEdit = new QLineEdit();

    mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
    saveButton = new QPushButton(QString::fromUtf8("Änderungen Speichern"), this);
    backButton = new QPushButton("Abbrechen");

    errorMsgRow = new QBoxLayout(QBoxLayout::LeftToRight);
    errorMsgLabel = new QLabel();

    setMainWindowDesign();
    setMainLayoutDesign();

    //to center window
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter,
                      this->size(), qApp->desktop()->availableGeometry()));

    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(changepwCalled()));
    QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(setupusersCalled()));

    //Enter as conformation
    QObject::connect(giveOldpwEdit, SIGNAL(returnPressed()), this, SLOT(changepwCalled()));
    QObject::connect(giveNewpwEdit, SIGNAL(returnPressed()), this, SLOT(changepwCalled()));
}

void changePwPage::setMainWindowDesign(){
    setFixedSize(400, 300);
    setStyleSheet("background-color: white;");
    setWindowTitle(QString::fromUtf8("Passwort Ändern"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(oldPwRow);
    mainLayout->addLayout(newPwRow);
    mainLayout->addLayout(mainButtonsRow);
    mainLayout->addLayout(errorMsgRow);

    this->setLayout(mainLayout);
}

void changePwPage::setMainLayoutDesign(){
    mainLabelRow->addWidget(mainLabel, 0, Qt::AlignCenter);
    mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 20px;"
                             "font-weight: bold; margin-top: 5px; color: #aaa;");

    oldPwRow->addWidget(oldpwLabel, 0, Qt::AlignCenter);
    oldpwLabel->setStyleSheet("margin-bottom: 20px; margin-right: 9px;");
    oldPwRow->addWidget(giveOldpwEdit);
    giveOldpwEdit->setMaxLength(4);
    giveOldpwEdit->setEchoMode(QLineEdit::Password);
    giveOldpwEdit->setValidator(new QIntValidator(0, 10000, this));
    giveOldpwEdit->setStyleSheet("margin-bottom: 20px;");


    newPwRow->addWidget(newpwLabel, 0, Qt::AlignCenter);
    newpwLabel->setStyleSheet("margin-bottom: 30px; margin-right: 2px;");
    newPwRow->addWidget(giveNewpwEdit);
    giveNewpwEdit->setMaxLength(4);
    giveNewpwEdit->setEchoMode(QLineEdit::Password);
    giveNewpwEdit->setValidator(new QIntValidator(0, 10000, this));
    giveNewpwEdit->setStyleSheet("margin-bottom: 30px; margin-left: 0px;");


    mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(180, 50);
    saveButton->setStyleSheet("border: 1px solid #3399ff; border-radius: 5px; "
                              "background-color: #3399ff; color: white; font-weight: bold; "
                              "margin-bottom: 5px;");

    mainButtonsRow->addWidget(backButton);
    backButton->setFixedSize(180, 50);
    backButton->setStyleSheet("border: 1px solid #00b300; border-radius: 5px; "
                              "background-color: #00b300; color: white; font-weight: bold;");

    errorMsgRow->addWidget(errorMsgLabel, 0, Qt::AlignCenter);
    errorMsgLabel->setStyleSheet("font-weight: bold; color: red");
    errorMsgLabel->hide();
}

std::string changePwPage::getOldPwInput(){
    if(giveOldpwEdit->text().size() == 0 || giveOldpwEdit->text()[0] == ' '){
        return "Error";
    }
    return giveOldpwEdit->text().toStdString();
}

std::string changePwPage::getNewPwInput(){
    if(giveNewpwEdit->text().size() == 0 || giveNewpwEdit->text()[0] == ' '){
        return "Error";
    }
    return giveNewpwEdit->text().toStdString();
}

void changePwPage::falseData() {
    giveOldpwEdit->clear();
    giveNewpwEdit->clear();
    errorMsgLabel->setText("invalid password");
    errorMsgLabel->show();
}

void changePwPage::validate() {
    QString password = giveNewpwEdit->text();

    bool shortpasswordError = password.size() < 4 || password[0] == ' ';

    if(shortpasswordError) {
        throw std::string("Password does not meet password policy requirements");
    }
}

void changePwPage::clearContent() {
    giveNewpwEdit->clear();
    giveOldpwEdit->clear();
    errorMsgLabel->hide();
}

void changePwPage::appear() {
    clearContent();
    show();
}

void changePwPage::setupusersCalled(){
    emit setupusersSignal();
}

void changePwPage::changepwCalled(){
    try{
        validate();
    }
    catch (std::string error) {
        errorMsgLabel->setText(QString::fromStdString(error));
        errorMsgLabel->show();
        return;
    }
    emit changepwSignal();
}

