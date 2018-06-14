#ifndef CHANGEPWPAGE_H
#define CHANGEPWPAGE_H
#include <string>
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

class changePwPage : public QWidget
{
    Q_OBJECT

private:
    friend class GuiController;

    //Design Elemts

    QBoxLayout *mainLayout;

    QBoxLayout *mainLabelRow;
    QLabel *mainLabel;

    QBoxLayout *oldPwRow;
    QBoxLayout *newPwRow;

    QBoxLayout *mainButtonsRow;
    QLabel *oldpwLabel;
    QLineEdit *giveOldpwEdit;
    QLabel *newpwLabel;
    QLineEdit *giveNewpwEdit;

    QBoxLayout* errorMsgRow;
    QLabel* errorMsgLabel;

    QPushButton *saveButton;
    QPushButton *backButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();
    void falseData();
    void validate();

private slots:
    void setupusersCalled();    //go back to SetUpUsers interface
    void changepwCalled();

signals:
    void setupusersSignal();
    void changepwSignal();

public:
    explicit changePwPage(QWidget *parent = NULL);

    std::string getOldPwInput();
    std::string getNewPwInput();

    void appear();
    void clearContent();
};


#endif // CHANGEPWPAGE_H
