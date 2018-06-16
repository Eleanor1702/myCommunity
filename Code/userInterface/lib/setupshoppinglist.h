#ifndef SETUPSHOPPINGLIST_H
#define SETUPSHOPPINGLIST_H

#include <vector>
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

#include <QStyle>
#include <QDesktopWidget>

#include <userInterface/lib/shoppinglistitem.h>

//Inheritance from QWidget allows the class itself to react on events
 class SetUpShoppinglist : public QWidget {
     //enable creation of slots and signals
     Q_OBJECT
 private:
     friend class GuiController;

     ShoppinglistItem* newItem;

     QBoxLayout *mainLayout;
     QBoxLayout *mainLabelRow;
     QLabel *mainLabel;

     QBoxLayout *scrollAreaRow;
     QScrollArea *scrollArea;
     QWidget *scrollWidget;
     QBoxLayout *scrollLayout;

     QBoxLayout* addItemsRow;

     QBoxLayout* mainButtonsRow;
     QLabel* ItemNameLabel;
     QLineEdit* giveNameEdit;
     QLabel* ItemNumberLabel;
     QLineEdit* giveNumberEdit;
     QPushButton* addButton;
     QPushButton* saveButton;

     void setMainWindowDesign();
     void setMainLayoutDesign();
     void deepDeleteLayout(QLayout* layout);

 private slots:
     void setNewItemCalled();
     void homepageCalled();
     void deleteItemCalled(QString name);

 signals:
     void setNewItemSignal();
     void homePageCallSignal();
     void deleteItemSignal(QString);

 public:
     //the constructor build the window
     //the parameter *parent is here to nest widgets in widgets
     explicit SetUpShoppinglist(QWidget* parent = NULL);

     std::string getItemNameInput();
     std::string getItemNumberInput();
     void appear(std::vector<std::string> nameVec, std::vector<std::string> numberVec, int size);

 };

#endif // SETUPSHOPPINGLIST_H

