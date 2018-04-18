#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QApplication>
#include <QPushButton>

class StartPage{
private:
    QWidget interface;

    void setInterfaceDesign();

public:
    StartPage();
    void run();
};

#endif // STARTPAGE_H

