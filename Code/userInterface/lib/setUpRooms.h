#ifndef SETUPROOMS_H
#define SETUPROOMS_H

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>

class SetUpRooms{
private:
    QWidget mainWindow;
    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWindow);
    QLabel *mainLabel = new QLabel(&mainWindow);
    QScrollArea *scrollArea = new QScrollArea(&mainWindow);
    QWidget *scrollWidget = new QWidget(&mainWindow);
    QVBoxLayout *roomsLayout = new QVBoxLayout (&mainWindow);
    QLabel *message = new QLabel(&mainWindow);
    QHBoxLayout *buttonLayout = new QHBoxLayout(&mainWindow);
    QPushButton *addButton = new QPushButton(&mainWindow);


    void setMainWindowDesign();
    void setMainLayoutDesign();
    void setMainLabelDesign();
    void setRoomsLayoutDesign();
    void setMessageDesign();
    void setButtonLayoutDesign();
    void setAddButtonDesign();

public:
    SetUpRooms();
    void run();
    void addButtonClicked();
};

#endif // SETUPROOMS_H

