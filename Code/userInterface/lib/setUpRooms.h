#ifndef SETUPROOMS_H
#define SETUPROOMS_H

#include <QApplication>
#include <QLabel>
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
    QLabel *mainLabel = new QLabel(&mainWindow);
    QBoxLayout *mainLayout = new QBoxLayout(QBoxLayout::TopToBottom, &mainWindow);
    QBoxLayout *zeile1 = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout *zeile2 = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout *zeile3 = new QBoxLayout(QBoxLayout::LeftToRight);

    void setMainWindowDesign();
    void setMainLabelDesign();
    void setMainLayoutDesign();

private slots:
    void Button_add_clicked(QComboBox*, QLineEdit*);

public:
    SetUpRooms();
    void run();
};

#endif // SETUPROOMS_H

