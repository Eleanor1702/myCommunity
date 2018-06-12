#ifndef SETUPUSERS_H
#define SETUPUSERS_H

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

#include <userInterface/lib/UserListItem.h>

//Inheritance from QWidget allows the class itself to react on events
//example (Button clicks.. etc)
class SetUpUsers : public QWidget{
  //enable creation of slots and signals
  Q_OBJECT
private:
   friend class GuiController;

   UserListItem *newUser;

   QBoxLayout *mainLayout;
   QBoxLayout *mainLabelRow;
   QLabel *mainLabel;

   QBoxLayout *scrollAreaRow;
   QScrollArea *scrollArea;
   QWidget *scrollWidget;
   QBoxLayout *scrollLayout;

   QBoxLayout *addUserRow;

   QBoxLayout *mainButtonsRow;
   QPushButton *backButton;
   QPushButton *changepwButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();
    void deepDeleteLayout(QLayout* layout);

private slots:
    void homePageCalled();
    void deleteUserCalled(QString name);
    void pwpageCalled();

signals:
    void newUserSig4nUpSignal(std::string name, int password);
    void homePageCallSignal();
    void deleteUserSignal(QString);
    void pwpageSignal();

public:
    //the constructor build the window
    //the parameter *parent is here to nest widgets in widgets
    explicit SetUpUsers(QWidget *parent = NULL);

    void appear(std::vector<std::string> nameVec, int size, std::string username);
};


#endif // SETUPUSERS_H
