#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

class MainScreen{
private:
    QWidget mainWindow;
    QPushButton userProfileButton;

    void setMainScreenDesign();
    void addTaskbar();
    void setTaskbarButtonDesign(QPushButton *button);

public:
    MainScreen();
    void run();
};
#endif // MAINSCREEN_H
