#ifndef CLEANINGPAGE_H
#define CLEANINGPAGE_H

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QLayout>

#include <QStyle>
#include <QDesktopWidget>
#include "userInterface/lib/cleaningpageitem.h"

class CleaningPage : public QWidget
{
    Q_OBJECT
public:
    CleaningPage(QWidget *parent=NULL);
    std::vector<CleaningPageItem*> CleaningPageItemList;
    void deepDeleteLayout(QLayout *layout);
    void appear(std::vector<int> weekVec,
                std::vector<std::string> roomVec,
                std::vector<std::string> taskVec,
                std::vector<std::string> resVec, int size, int week);
private:
    friend class GuiController;

    CleaningPageItem *newCPageItem;

    QBoxLayout *mainLayout;

    QBoxLayout *mainLabelRow;
    QLabel *mainLabel;

    //Hier muss der Plan eingefügt werden
/*    QBoxLayout *planRow;
    QVBoxLayout *weekRow;
    QLabel *weekLabel;
    QVBoxLayout *ScrollAreaRow;
    QScrollArea *ScrollAreaW1;
    QScrollArea *ScrollAreaW2;
    QScrollArea *ScrollAreaW3;
    QScrollArea *ScrollAreaW4;
    QVBoxLayout *scrollLayout;
*/
    QBoxLayout *planRow;
    QScrollArea *ScrollAreaW1;
    QBoxLayout *scrollLayoutW1;
    QWidget *scrollWidgetW1;
    QWidget *scrollWidgetW2;
    QWidget *scrollWidgetW3;
    QWidget *scrollWidgetW4;
    QScrollArea *ScrollAreaW2;
    QBoxLayout *scrollLayoutW2;
    QScrollArea *ScrollAreaW3;
    QBoxLayout *scrollLayoutW3;
    QScrollArea *ScrollAreaW4;
    QBoxLayout *scrollLayoutW4;



    QBoxLayout *buttonRow;
    QPushButton *setuptaskButton;
    QPushButton *createPlanButton;
    QPushButton *backButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

private slots:
    void taskCalled();
    void createPlanCalled();
    void homePageCalled();

signals:
    void taskCallSignal();
    void createPlanSignal();
    void homePageCallSignal();
};

#endif // CLEANINGPAGE_H
