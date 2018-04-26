#ifndef SETUPROOMS_H
#define SETUPROOMS_H

#include <QApplication>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QStringList>
#include <QList>
#include <lib/wg.h>

class SetUpRooms{
private:
    QWidget mainWindow;
    QScrollArea *scrollArea = new QScrollArea(&mainWindow);
    QWidget *scrollWidget = new QWidget(&mainWindow);
    QLabel *mainLabel = new QLabel(&mainWindow);
    QBoxLayout *mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, &mainWindow);
    QBoxLayout *row1 = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout *row2 = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout *row3 = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout *row4 = new QBoxLayout(QBoxLayout::LeftToRight);

    void setMainWindowDesign();
    void setMainLayoutDesign();
    void setMainLabelDesign();


private slots:
    void Button_add_clicked(QComboBox*, QLineEdit*);

public:
    SetUpRooms();
    void run();
};

#endif // SETUPROOMS_H

