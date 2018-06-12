#include "userInterface/lib/shoppinglistitem.h"

ShoppinglistItem::ShoppinglistItem(QString itemName, int number, QWidget *parent) : QFrame(parent){
    this->newItemLayout = new QHBoxLayout();
    this->item = new QLabel(itemName); // + number
    this->deleteButton = new QPushButton(QString::fromStdString("Löschen"));
    name = itemName;

    setItemStyle();

    //events
    QObject::connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteShopItem()));
}

void ShoppinglistItem::setItemStyle() {
    //Frame Design
    this->setFixedHeight(50);
    this->setStyleSheet("border: 1px solid #aaa; border-radius: 5px;");

    //Layout Design
    this->setLayout(this->newItemLayout);
    this->newItemLayout->addWidget(this->item);
    this->newItemLayout->addWidget(this->deleteButton);

    //Shopping Item Design
    this->item->setFixedSize(550, 30);
    this->item->setStyleSheet("text-align: center; font-size: 20px; border: 0px; color: #aaa;");

    //Button Design
    this->deleteButton->setFixedHeight(30);
    this->deleteButton->setStyleSheet(".QPushButton{border: 1px solid red;"
                                      "border-radius: 5px; background-color: red;"
                                      " color: white; font-weight: bold;}");
}

void ShoppinglistItem::deleteShopItem() {
    emit deleteShopItemSignal(name);
}
