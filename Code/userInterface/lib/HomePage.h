#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QApplication>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>

//Inheritance from QWidget allows the class itself to react on events
//example (Button clicks.. etc)
class HomePage : public QWidget {
  //enable creation of slots and signals
  Q_OBJECT
private:
  QBoxLayout *mainLayout;

  QBoxLayout *mainLabelRow;
  QLabel *mainLabel;

  QBoxLayout *buttonColumn;
  QPushButton *settings;
  QPushButton *shoppingList;
  QPushButton *cleanPlan;
  QPushButton *saveFormat;
  QPushButton *logOut;

  void setMainScreenDesign();
  void setMainLayoutDesign();

public:
  HomePage(QWidget *parent = NULL);
};
#endif // HOMEPAGE_H