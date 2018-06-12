#include "userInterface/lib/changepwpage.h"


changePwPage::changePwPage(QWidget *parent) : QWidget(parent){
    //declerations of window contents
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Passwort ändern");

    changePwRow = new QBoxLayout(QBoxLayout::LeftToRight);

    mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
    oldpwLabel = new QLabel("Altes Passwort:");
    giveOldpwEdit = new QLineEdit();
    newpwLabel = new QLabel("Neues Passwort");
    giveNewpwEdit = new QLineEdit();
    saveButton = new QPushButton(QString::fromUtf8("Neues Passwort speichern"), this);
    backButton = new QPushButton("Zurück ohne Passwortänderung");

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



}

void changePwPage::setMainWindowDesign(){
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Passwort ändern"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(changePwRow);
    mainLayout->addLayout(mainButtonsRow);


    this->setLayout(mainLayout);
}

void changePwPage::setMainLayoutDesign(){
    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 5px; color: #aaa;");

    this->changePwRow->addWidget(oldpwLabel);
    this->changePwRow->addWidget(giveOldpwEdit);
    this->giveOldpwEdit->setMaxLength(4);
    this->giveOldpwEdit->setEchoMode(QLineEdit::Password);
    this->changePwRow->addWidget(newpwLabel);
    this->changePwRow->addWidget(giveNewpwEdit);
    this->giveNewpwEdit->setMaxLength(4);
    this->giveNewpwEdit->setEchoMode(QLineEdit::Password);

    this->mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(230, 50);
    saveButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                             "border-radius: 5px; background-color: #3399ff; "
                             "color: white; font-weight: bold;}");


    this->mainButtonsRow->addWidget(backButton);
    backButton->setFixedSize(230, 50);
    backButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                              "border-radius: 5px; background-color: #00b300; "
                              "color: white; font-weight: bold;}");


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

void changePwPage::setupusersCalled(){
    emit setupusersSignal();
}

void changePwPage::changepwCalled(){
    emit changepwSignal();
}
