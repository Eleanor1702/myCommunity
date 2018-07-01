#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QApplication>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

#include <QStyle>
#include <QDesktopWidget>

class MainScreen : public QWidget {
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
    explicit MainScreen(QWidget *parent = NULL);

private slots:
   void signUpCalled();
   void signInCalled();

signals:
   void signUpCallSignal();
   void signInCallSignal();
};

#endif // MAINSCREEN_H
