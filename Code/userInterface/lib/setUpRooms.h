#ifndef SETUPROOMS_H
#define SETUPROOMS_H

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>

class SetUpRooms{
private:
    QWidget mainWindow;
    QLabel *mainLabel = new QLabel(&mainWindow);
    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWindow);
    void setMainWindowDesign();
    void setMainLabelDesign();
    void setMainLayoutDesign();

public:
    SetUpRooms();
    void run();
};

#endif // SETUPROOMS_H

