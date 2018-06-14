#include "userInterface/lib/setupshoppinglist.h"

//calling the constructor, calls the parent constructor too
//in this case QWidget

SetUpShoppinglist::SetUpShoppinglist(QWidget *parent) : QWidget(parent) {
    //declaration of window contents
    mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    mainLabelRow = new QBoxLayout(QBoxLayout::LeftToRight);
    mainLabel = new QLabel("Let's create a shoppinglist..");

    scrollAreaRow = new QBoxLayout(QBoxLayout::LeftToRight);
    scrollArea = new QScrollArea(this);
    scrollWidget = new QWidget(this);
    scrollLayout = new QBoxLayout(QBoxLayout::TopToBottom, this->scrollWidget);

    addItemsRow = new QBoxLayout(QBoxLayout::LeftToRight);

    mainButtonsRow = new QBoxLayout(QBoxLayout::LeftToRight);
    ItemNameLabel = new QLabel("Produkt:");
    giveNameEdit = new QLineEdit();
    ItemNumberLabel = new QLabel("Anzahl");
    giveNumberEdit = new QLineEdit();
    addButton = new QPushButton ("Produkt hinzufügen");
    saveButton = new QPushButton("Zurück zum Hauptmenü");

    this->setMainWindowDesign();
    this->setMainLayoutDesign();

    QObject::connect(addButton, SIGNAL(clicked()), this, SLOT(setNewItemCalled()));
    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(homepageCalled()));

    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
         )
    );
}

void SetUpShoppinglist::setMainWindowDesign() {
    this->setFixedSize(800, 600);
    this->setStyleSheet("background-color: white;");
    this->setWindowTitle(QString::fromUtf8("Einkaufsliste verwalten"));

    mainLayout->addLayout(mainLabelRow);
    mainLayout->addLayout(scrollAreaRow);
    mainLayout->addLayout(addItemsRow);
    mainLayout->addLayout(mainButtonsRow);
    this->setLayout(mainLayout);
}

void SetUpShoppinglist::setMainLayoutDesign() {

    this->mainLabelRow->addWidget(this->mainLabel, 0, Qt::AlignCenter);
    this->mainLabel->setStyleSheet("font-family: URW Bookman L; font-size: 30px;"
                                   "font-weight: bold; margin-top: 5px; color: #aaa;");

    this->scrollAreaRow->addWidget(scrollArea);
    this->scrollArea->setWidget(this->scrollWidget);
    this->scrollWidget->setLayout(this->scrollLayout);
    this->scrollLayout->setAlignment(Qt::AlignTop);
    this->scrollArea->setWidgetResizable(true);

    this->addItemsRow->addWidget(ItemNameLabel);
    this->addItemsRow->addWidget(giveNameEdit);
    this->ItemNameLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    this->giveNameEdit->setStyleSheet("color: black;");
    this->addItemsRow->addWidget(ItemNumberLabel);
    this->addItemsRow->addWidget(giveNumberEdit);
    this->ItemNumberLabel->setStyleSheet("color: #aaa; font-weight: bold;");
    this->giveNumberEdit->setStyleSheet("color: black;");

    this->mainButtonsRow->addWidget(addButton);
    addButton->setFixedSize(200, 50);
    addButton->setStyleSheet(".QPushButton{border: 1px solid #3399ff; "
                             "border-radius: 5px; background-color: #3399ff; "
                             "color: white; font-weight: bold;}");


    this->mainButtonsRow->addWidget(saveButton);
    saveButton->setFixedSize(200, 50);
    saveButton->setStyleSheet(".QPushButton{border: 1px solid #00b300; "
                              "border-radius: 5px; background-color: #00b300; "
                              "color: white; font-weight: bold;}");

}

std::string SetUpShoppinglist::getItemNameInput() {
    //proceed only with a room name
    if(this->giveNameEdit->text().size() == 0 || this->giveNameEdit->text()[0] == ' '){
        return "Error";
    }

    return this->giveNameEdit->text().toStdString();
}

int SetUpShoppinglist::getItemNumberInput() {
    //proceed only with a room name
    if(this->giveNumberEdit->text().size() == 0 || this->giveNumberEdit->text()[0] == ' '){
        return 1;
    }

    return this->giveNumberEdit->text().toInt();
}

void SetUpShoppinglist::deepDeleteLayout(QLayout *layout) {
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

void SetUpShoppinglist::appear(std::vector<std::string>nameVec, std::vector<int> numberVec, int size) {
    deepDeleteLayout(scrollLayout);

    for(int i = 0; i < size; i++) {
        newItem = new ShoppinglistItem(QString::fromStdString(nameVec[i]), numberVec[i]);

        //connect every shopping list item
        connect(newItem, SIGNAL(deleteShopItemSignal(QString)), this, SLOT(deleteItemCalled(QString)));
        scrollLayout->addWidget(newItem);
    }
    giveNameEdit->clear();
    giveNumberEdit->clear();
    this->show();
}

void SetUpShoppinglist::setNewItemCalled() {
    emit setNewItemSignal();
}

void SetUpShoppinglist::homepageCalled() {
    emit homePageCallSignal();
}

void SetUpShoppinglist::deleteItemCalled(QString name) {
    emit deleteItemSignal(name);
}

