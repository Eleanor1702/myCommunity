#ifndef SIGNUP_H
#define SIGNUP_H

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

class SignUp : public QWidget{
  //enable creation of slots and signals
  Q_OBJECT
private:
   QBoxLayout *mainLayout;
   QBoxLayout *mainLabelRow;
   QLabel *mainLabel;

   QBoxLayout *imageRow;
   QWidget *image;

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
    //void backButtonClicked();

signals:

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SignUp(QWidget *parent = NULL);

public slots:

};


#endif // SIGNUP_H
