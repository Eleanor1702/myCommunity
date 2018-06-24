#include "userInterface/lib/exportpage.h"

exportPage::exportPage(QWidget *parent) : QWidget(parent){
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Pläne exportiern");

    cleaningButtonRow = new QBoxLayout(QBoxLayout::LeftToRight);
    shoppingButtonRow = new QBoxLayout(QBoxLayout::LeftToRight);
    backButtonRow = new QBoxLayout(QBoxLayout::LeftToRight);

    backButton = new QPushButton(QString::fromUtf8("Zurück zum Hauptmenü"));
    cleaningExportButton = new QPushButton(QString::fromUtf8("Putzplan exportieren"));
    shoppingExportButton = new QPushButton(QString::fromUtf8("Einkaufsliste exportieren"));

    MsgRow = new QBoxLayout(QBoxLayout::LeftToRight);
    MsgLabel = new QLabel("");

    this->setMainWindowDesign();
    this->setMainLayoutDesign();

    QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(homePageCalled()));
    QObject::connect(cleaningExportButton, SIGNAL(clicked()), this, SLOT(cleaningExportCalled()));
    QObject::connect(shoppingExportButton, SIGNAL(clicked()), this, SLOT(shoppingExportCalled()));

    this->setGeometry(          //To Center Window
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

}

void exportPage::setMainWindowDesign(){
    this->setFixedSize(800,600);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Pläne Exportiern"));

    this->mainLayout->addLayout(mainLabelRow);
    this->mainLayout->addLayout(cleaningButtonRow);
    this->mainLayout->addLayout(shoppingButtonRow);
    this->mainLayout->addLayout(backButtonRow);
    this->mainLayout->addLayout(MsgRow);

    this->setLayout(mainLayout);

}

void exportPage::setMainLayoutDesign(){

    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                       "font-weight: bold; margin-top: 5px; color: #aaa;");
    this->cleaningButtonRow->addWidget(cleaningExportButton, 1, Qt::AlignBottom);
    this->cleaningExportButton->setFixedSize(200,50);
        this->cleaningExportButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                            "border-radius: 5px; background-color: #3399ff; "
                                            "color: white; font-weight: bold;}");
    this->shoppingButtonRow->addWidget(shoppingExportButton, 1, Qt::AlignTop);
    this->shoppingExportButton->setFixedSize(200,50);
    this->shoppingExportButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                                            "border-radius: 5px; background-color: #3399ff; "
                                            "color: white; font-weight: bold;}");
    this->backButtonRow->addWidget(backButton, 1, Qt::AlignTop);
    this->backButton->setFixedSize(200,50);
    this->backButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                                            "border-radius: 5px; background-color: #00b300; "
                                            "color: white; font-weight: bold;}");
    this->MsgRow->addWidget(this->MsgLabel, 3, Qt::AlignCenter);
    this->MsgLabel->setStyleSheet("font-weight: bold; color:black");
    this->MsgLabel->hide();

}

void exportPage::homePageCalled(){
    MsgLabel->hide();
    emit homePageCallSignal();
}

void exportPage::shoppingExportCalled(){
    MsgLabel->setText("Einkaufsliste erfolgreich in das Home Verzeichnis exportiert");
    MsgLabel->show();
    emit shoppingExportSignal();
}

void exportPage::cleaningExportCalled(){
    MsgLabel->setText("Putzplan erfolgreich in das Home Verzeichnis exportiert");
    MsgLabel->show();
    emit cleaningExportSignal();
}



