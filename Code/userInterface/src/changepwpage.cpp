#include "userInterface/lib/changepwpage.h"

changePwPage::changePwPage(QWidget *parent) : QWidget(parent){
    //declerations of window contents
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Passwort ändern");

    oldPwRow = new QBoxLayout(QBoxLayout::LeftToRight);
    newPwRow = new QBoxLayout(QBoxLayout::LeftToRight);

    mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
    oldpwLabel = new QLabel("Altes Passwort:");
    giveOldpwEdit = new QLineEdit();
    newpwLabel = new QLabel("Neues Passwort");
    giveNewpwEdit = new QLineEdit();
    saveButton = new QPushButton(QString::fromUtf8("Neues Passwort \n speichern"), this);
    backButton = new QPushButton("Zurück ohne \n Passwortänderung");

    errorMsgRow = new QBoxLayout(QBoxLayout::LeftToRight);
    errorMsgLabel = new QLabel();

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

    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(changepwCalled()));
    QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(setupusersCalled()));
    QObject::connect(giveOldpwEdit, SIGNAL(returnPressed()), this, SLOT(changepwCalled()));         //Enter as conformation
    QObject::connect(giveNewpwEdit, SIGNAL(returnPressed()), this, SLOT(changepwCalled()));         //Enter as conformation



}

void changePwPage::setMainWindowDesign(){
    this->setFixedSize(400, 300);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Passwort ändern"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(oldPwRow);
    mainLayout->addLayout(newPwRow);
    mainLayout->addLayout(mainButtonsRow);
    mainLayout->addLayout(errorMsgRow);


    this->setLayout(mainLayout);
}

void changePwPage::setMainLayoutDesign(){
    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 5px; color: #aaa;");

    this->oldPwRow->addWidget(oldpwLabel);
    this->oldPwRow->addWidget(giveOldpwEdit);
    this->giveOldpwEdit->setMaxLength(4);
    this->giveOldpwEdit->setEchoMode(QLineEdit::Password);
    this->giveOldpwEdit->setValidator(new QIntValidator(0, 10000, this));

    this->newPwRow->addWidget(newpwLabel);
    this->newPwRow->addWidget(giveNewpwEdit);
    this->giveNewpwEdit->setMaxLength(4);
    this->giveNewpwEdit->setEchoMode(QLineEdit::Password);
    this->giveNewpwEdit->setValidator(new QIntValidator(0, 10000, this));


    this->mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(180, 50);
    saveButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                             "border-radius: 5px; background-color: #3399ff; "
                             "color: white; font-weight: bold;}");


    this->mainButtonsRow->addWidget(backButton);
    backButton->setFixedSize(180, 50);
    backButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                              "border-radius: 5px; background-color: #00b300; "
                              "color: white; font-weight: bold;}");

    errorMsgRow->addWidget(errorMsgLabel, 0, Qt::AlignCenter);
    errorMsgLabel->setStyleSheet("font-weight: bold; color:red");
    errorMsgLabel->hide();


}

std::string changePwPage::getOldPwInput(){
    if(this->giveOldpwEdit->text().size() == 0 || this->giveOldpwEdit->text()[0] == ' '){
        return "Error";
    }
    //giveOldpwEdit->clear();
    return this->giveOldpwEdit->text().toStdString();

}

std::string changePwPage::getNewPwInput(){
    if(this->giveNewpwEdit->text().size() == 0 || this->giveNewpwEdit->text()[0] == ' '){
        return "Error";
    }
    //giveNewpwEdit->clear();
    return this->giveNewpwEdit->text().toStdString();

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
        //else if()
          //  {throw std::string("Falsches Passwot!");


    //}
}


void changePwPage::clearContent() {
    giveNewpwEdit->clear();
    giveOldpwEdit->clear();
    errorMsgLabel->hide();
}

void changePwPage::appear() {
    this->clearContent();
    this->show();
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

