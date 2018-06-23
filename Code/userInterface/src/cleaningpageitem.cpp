#include "userInterface/lib/cleaningpageitem.h"

CleaningPageItem::CleaningPageItem(QString roomClean, QString taskClean, QString resClean, QWidget *parent) : QFrame(parent)
{
    this->newPlanLayout = new QGridLayout();
    this->taskLabel = new QLabel(resClean + "\n" + roomClean + "\n" + taskClean);

    res = resClean;
    task = taskClean;
    room = roomClean;

    setItemStyle();
}

void CleaningPageItem::setItemStyle(){
    this->setFixedSize(160, 85);
    this->setStyleSheet("border: 0.5px solid #555; border-radius: 1px;");

    //Layout for concrete Tasks in Cleaning Plan
    this->setLayout(this->newPlanLayout);
    this->newPlanLayout->addWidget(this->taskLabel);
    this->taskLabel->setFixedSize(140, 40);
    this->taskLabel->setStyleSheet("text-align: center; font-family: URW Bookman L;"
                                   "font-size: 12px; border: 0px; color: #555;"
                                   "font-weight: bold; margin-top: 0px; ");

}
