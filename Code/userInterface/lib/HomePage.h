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
  friend class GuiController;
  QBoxLayout *mainLayout;

  //contains mainlabel and content of buttons
  //when clicked
  QBoxLayout *contentColumn;

  QBoxLayout *mainLabelRow;
  QLabel *mainLabel;

  //SettingButton
  QBoxLayout *settingsButtonLayout;
  QPushButton *userSettingButton;
  QPushButton *roomSettingButton;

  QBoxLayout *buttonColumn;
  QPushButton *settings;
  QPushButton *shoppingList;
  QPushButton *cleanPlan;
  QPushButton *saveFormat;
  QPushButton *logOut;

  QBoxLayout *calendarButtonLayout;
  QPushButton *calendarButton;

  void setMainScreenDesign();
  void setMainLayoutDesign();

public:
  HomePage(QWidget *parent = NULL);

private slots:
  void settingsCalled();
  void roomSettingCalled();
  void userSettingCalled();

signals:
  void roomSettingsCallSignal();
  void userSettingsCallSignal();
};
#endif // HOMEPAGE_H
