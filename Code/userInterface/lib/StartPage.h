#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QApplication>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

class StartPage : public QWidget {
  //enable creation of slots and signals
  Q_OBJECT
private:
   friend class GuiController;

   QBoxLayout *mainLayout;
   QBoxLayout *mainLabelRow;
   QLabel *mainLabel;

   QBoxLayout *ButtonsRow;
   QPushButton *signInButton;
   QPushButton *signUpButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit StartPage(QWidget *parent = NULL);
};

#endif // STARTPAGE_H