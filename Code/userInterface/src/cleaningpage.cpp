#include "userInterface/lib/cleaningpage.h"

CleaningPage::CleaningPage(QWidget *parent) : QWidget(parent) {

    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Putzplan");

    planRow = new QBoxLayout(QBoxLayout::TopToBottom);
    plan = new QLabel ("hier Plan einfügen");

    buttonRow = new QBoxLayout(QBoxLayout::LeftToRight);
    setuptaskButton = new QPushButton ("Aufgaben \n verwalten");
    createPlanButton = new QPushButton ("Plan erstellen");
    backButton = new QPushButton ("Zurück");

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

    QObject::connect(setuptaskButton, SIGNAL(clicked()), this, SLOT(taskCalled()));
    QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(homePageCalled()));
}

void CleaningPage::setMainWindowDesign(){
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white");
    this->setWindowTitle(QString::fromUtf8("Putzplan"));

    mainLayout->addLayout(this->mainLabelRow);
    mainLayout->addLayout(this->planRow);
    mainLayout->addLayout(this->buttonRow);

    this->setLayout(mainLayout);
}

void CleaningPage::setMainLayoutDesign(){
    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 30px; color: #aaa;");

    this->planRow->addWidget(this->plan, 1, Qt::AlignLeft);
    this->plan->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                              "font-weight: bold; margin-top: 30px; color: #aaa;");

    this->buttonRow->addWidget(setuptaskButton, 2, Qt::AlignLeft);
    this->buttonRow->addWidget(createPlanButton, 2, Qt::AlignCenter);
    this->buttonRow->addWidget(backButton, 2, Qt::AlignRight);

    this->setuptaskButton->setFixedSize(200, 50);
    this->setuptaskButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                    "border-radius: 5px; background-color: #3399ff; "
                                    "color: white; font-weight: bold;}");

    this->createPlanButton->setFixedSize(200, 50);
    this->createPlanButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                    "border-radius: 5px; background-color: #3399ff; "
                                    "color: white; font-weight: bold;}");



    this->backButton->setFixedSize(200, 50);
    this->backButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                                    "border-radius: 5px; background-color: #00b300; "
                                    "color: white; font-weight: bold;}");
}

void CleaningPage::taskCalled() {
  emit taskCallSignal();
}

void CleaningPage::homePageCalled() {
  emit homePageCallSignal();
}
