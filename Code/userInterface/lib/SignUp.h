#ifndef SIGNUP_H
#define SIGNUP_H

#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QStringList>
#include <QList>
#include <QPixmap>

#include <QStyle>
#include <QDesktopWidget>

class SignUp : public QWidget {
  //enable creation of slots and signals
  Q_OBJECT

private:
   friend class GuiController;
   QBoxLayout *mainLayout;

   QBoxLayout *mainLabelRow;
   QLabel *mainLabel;

   QBoxLayout *imageRow;
   QPixmap *pic;
   QPixmap scaled;
   QLabel *picLabel;

   QBoxLayout *nameRow;
   QLabel *nameLabel;
   QLineEdit *giveNameEdit;

   QBoxLayout *passwordRow;
   QLabel *passwordLabel;
   QLineEdit *givePasswordEdit;

   QBoxLayout* errorMsgRow;
   QLabel* errorMsgLabel;

   QBoxLayout *mainButtonsRow;
   QPushButton *backButton;
   QPushButton *saveButton;

   void setMainWindowDesign();
   void setMainLayoutDesign();

   void validate();

private slots:
   void mainScreenCalled();
   void saveClicked();

signals:
   void mainScreenCallSignal();
   void newUserSignUpSignal(std::string name, int password);

public:
   //the constructor build the window
   //the parameter *parent is here to nest widgets in widgets
   //explicit SignUp(QWidget *parent = NULL);
   explicit SignUp(QWidget *parent = NULL);

   void appear();
   void clearContent();
   void usernameExist();

};

#endif // SIGNUP_H
