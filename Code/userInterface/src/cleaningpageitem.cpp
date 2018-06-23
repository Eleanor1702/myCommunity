#include "userInterface/lib/cleaningpageitem.h"

CleaningPageItem::CleaningPageItem(QString weekClean, QString taskClean, QString resClean, QWidget *parent) : QFrame(parent)
{
    this->newPlanLayout = new QGridLayout();
    this->taskLabel = new QLabel(resClean + "\n"+ taskClean);

    res = resClean;
    task = taskClean;
    week = weekClean;

    setItemStyle();
}

void CleaningPageItem::setItemStyle(){
    this->setFixedSize(160, 60);
    this->setStyleSheet("border: 0.5px solid #555; border-radius: 1px;");

    this->setLayout(this->newPlanLayout);
    this->newPlanLayout->addWidget(this->taskLabel);
    this->taskLabel->setFixedSize(140, 40);
    this->taskLabel->setStyleSheet("text-align: top; font-size: 12px; border: 0px; color: #555;");

}
