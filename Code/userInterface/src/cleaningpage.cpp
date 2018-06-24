#include "userInterface/lib/cleaningpage.h"

CleaningPage::CleaningPage(QWidget *parent) : QWidget(parent) {

    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Putzplan");

    //Shows next 4 Calendarweeks
    weekRow = new QBoxLayout(QBoxLayout::LeftToRight);
    w1Label = new QLabel("");
    w2Label = new QLabel("");
    w3Label = new QLabel("");
    w4Label = new QLabel("");

    //Shows concrete Tasks sorted by Residents
    planRow = new QBoxLayout(QBoxLayout::LeftToRight);
    ScrollAreaW1 = new QScrollArea;
    scrollWidgetW1 = new QWidget(this);
    ScrollAreaW2 = new QScrollArea;
    scrollWidgetW2 = new QWidget(this);
    ScrollAreaW3 = new QScrollArea;
    scrollWidgetW3 = new QWidget(this);
    ScrollAreaW4 = new QScrollArea;
    scrollWidgetW4 = new QWidget(this);
    scrollLayoutW1 = new QBoxLayout(QBoxLayout::TopToBottom);
    scrollLayoutW2 = new QBoxLayout(QBoxLayout::TopToBottom);
    scrollLayoutW3 = new QBoxLayout(QBoxLayout::TopToBottom);
    scrollLayoutW4 = new QBoxLayout(QBoxLayout::TopToBottom);


    //Buttons added
    buttonRow = new QBoxLayout(QBoxLayout::LeftToRight);
    setuptaskButton = new QPushButton ("Aufgaben \n verwalten");
    createPlanButton = new QPushButton ("Plan erstellen");
    backButton = new QPushButton ("Zurück zum Hauptmenü");

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
    QObject::connect(createPlanButton,SIGNAL(clicked()),this,SLOT(createPlanCalled()));
    QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(homePageCalled()));
}

void CleaningPage::setMainWindowDesign(){
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white");
    this->setWindowTitle(QString::fromUtf8("Putzplan"));

    mainLayout->addLayout(this->mainLabelRow);
    mainLayout->addLayout(this->weekRow);
    mainLayout->addLayout(this->planRow);
    mainLayout->addLayout(this->buttonRow);

    this->setLayout(mainLayout);
}

void CleaningPage::setMainLayoutDesign(){
    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: Arial; font-size: 30px;"
                                   "font-weight: bold; margin-bottom: 20px; color: #555;");

    this->weekRow->addWidget(w1Label, 0, Qt::AlignLeft);
    this->w1Label->setStyleSheet("text-align: center; font-family: Arial;"
                                 "font-size: 12px; border: 0px; color: #555;"
                                 "font-weight: bold; margin-top: 0px;");
    this->weekRow->addWidget(w2Label, 0, Qt::AlignLeft);
    this->w2Label->setStyleSheet("text-align: center; font-family: Arial;"
                                 "font-size: 12px; border: 0px; color: #555;"
                                 "font-weight: bold; margin-top: 0px;");
    this->weekRow->addWidget(w3Label, 0, Qt::AlignLeft);
    this->w3Label->setStyleSheet("text-align: center; font-family: Arial;"
                                 "font-size: 12px; border: 0px; color: #555;"
                                 "font-weight: bold; margin-top: 0px;");
    this->weekRow->addWidget(w4Label, 0, Qt::AlignLeft);
    this->w4Label->setStyleSheet("text-align: center; font-family: Arial;"
                                 "font-size: 12px; border: 0px; color: #555;"
                                 "font-weight: bold; margin-top: 0px;");

    this->planRow->addWidget(ScrollAreaW1, 0, Qt::AlignLeft);
    this->ScrollAreaW1->setWidget(this->scrollWidgetW1);
    this->ScrollAreaW1->setFixedWidth(190);
    this->ScrollAreaW1->setWidgetResizable(true);
    this->scrollWidgetW1->setLayout(this->scrollLayoutW1);

    this->planRow->addWidget(ScrollAreaW2, 1, Qt::AlignLeft);
    this->ScrollAreaW2->setWidget(this->scrollWidgetW2);
    this->ScrollAreaW2->setFixedWidth(190);
    this->ScrollAreaW2->setWidgetResizable(true);
    this->scrollWidgetW2->setLayout(this->scrollLayoutW2);

    this->planRow->addWidget(ScrollAreaW3, 2, Qt::AlignRight);
    this->ScrollAreaW3->setWidget(this->scrollWidgetW3);
    this->ScrollAreaW3->setFixedWidth(190);
    this->ScrollAreaW3->setWidgetResizable(true);
    this->scrollWidgetW3->setLayout(this->scrollLayoutW3);

    this->planRow->addWidget(ScrollAreaW4, 3, Qt::AlignRight);
    this->ScrollAreaW4->setWidget(this->scrollWidgetW4);
    this->ScrollAreaW4->setFixedWidth(190);
    this->ScrollAreaW4->setWidgetResizable(true);
    this->scrollWidgetW4->setLayout(this->scrollLayoutW4);


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

void CleaningPage::createPlanCalled(){
    emit createPlanSignal();
}

void CleaningPage::homePageCalled() {
  emit homePageCallSignal();
}

void CleaningPage::deepDeleteLayout(QLayout *layout) {
    QLayoutItem* item;

    while((item = layout->takeAt(0))) {
        if(item->layout()){
            deepDeleteLayout(item->layout());
            delete item->layout();
        }

        if(item->widget()) {
            delete item->widget();
        }

        delete item;
    }
}
//Shows next 4 calendarweeks, with concrete Tasks, ordered by Resident
//Tasks of current User are highlighted
void CleaningPage::appear(std::vector<int> weekVec, std::vector<std::string>roomVec, std::vector<std::string> taskVec,
                          std::vector<std::string> resVec, int size, int week, std::string user){
    deepDeleteLayout(scrollLayoutW1);
    deepDeleteLayout(scrollLayoutW2);
    deepDeleteLayout(scrollLayoutW3);
    deepDeleteLayout(scrollLayoutW4);

    this->w1Label->setText("Kalenderwoche: " + QString::number(week));
    this->w2Label->setText("Kalenderwoche: " + QString::number(week+1));
    this->w3Label->setText("Kalenderwoche: " + QString::number(week+2));
    this->w4Label->setText("Kalenderwoche: " + QString::number(week+3));

    for(int i = 0; i<size; i++) {
        newCPageItem = new CleaningPageItem(QString::fromStdString(roomVec[i]),
                                            QString::fromStdString(taskVec[i]),
                                            QString::fromStdString(resVec[i]));



        if(resVec[i]==user){
            newCPageItem->setStyleSheet("background-color: #af8;"
                                        "border: 1px solid #555; border-radius: 1px;");
        }

        if(weekVec[i]==week){
            scrollLayoutW1->addWidget(newCPageItem, Qt::AlignTop);
        } else if(weekVec[i]== week+1){
            scrollLayoutW2->addWidget(newCPageItem, Qt::AlignTop);
        }else if(weekVec[i]== week+2){
            scrollLayoutW3->addWidget(newCPageItem, Qt::AlignTop);
        }else if(weekVec[i]== week+3){
            scrollLayoutW4->addWidget(newCPageItem, Qt::AlignTop);
        }

        //CleaningPageItemList.push_back(newCPageItem);
    }

}

