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

//Inheritance from QWidget allows the class itself to react on events
//example (Button clicks.. etc)
class SetUpRooms : public QWidget{
  //enable creation of slots and signals
  Q_OBJECT
private:
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QLabel *mainLabel;
    QBoxLayout *mainLayout;
    QBoxLayout *mainLabelRow;
    QBoxLayout *scrollAreaRow;
    QBoxLayout *addRoomsRow;
    QBoxLayout *mainButtonsRow;
    QPushButton *addButton;
    QLabel *roomTypeLabel;
    QComboBox *chooseRoomTypeCombo;
    QLabel *nameLabel;
    QLineEdit *giveNameEdit;
    QPushButton *saveButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

private slots:
    void Button_add_clicked();

signals:

public slots:

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SetUpRooms(QWidget *parent = NULL);
};

#endif // SETUPROOMS_H

