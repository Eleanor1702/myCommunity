#ifndef SIGNIN_H
#define SIGNIN_H

#include <QApplication>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>

class SignIn : public QWidget {
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

   QBoxLayout *wrongPassRow;
   QLabel *wrongPassLabel;

   QBoxLayout *buttonsRow;
   QPushButton *backButton;
   QPushButton *logInButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SignIn(QWidget *parent = NULL);

    void clearContent();
    std::string getUserName();
    int getUserPassword();
};
#endif // SIGNIN_H
