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

class SignUp : public QWidget{
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
   QLabel *label;

   QBoxLayout *addUsersRow;
   QLabel *nameLabel;
   QLabel *passwordLabel;
   QLineEdit *giveNameEdit;
   QLineEdit *givePasswordEdit;

   QBoxLayout *mainButtonsRow;
   QPushButton *backButton;
   QPushButton *saveButton;

   void setMainWindowDesign();
   void setMainLayoutDesign();

private slots:

    //void saveButtonClicked();
    void backButtonClicked();

signals:


public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    //explicit SignUp(QWidget *parent = NULL);
    explicit SignUp(QWidget *parent = NULL);

    //virtual void showWindow();

public slots:

};

#endif // SIGNUP_H
