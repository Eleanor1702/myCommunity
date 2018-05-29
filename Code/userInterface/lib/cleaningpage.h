#ifndef CLEANINGPAGE_H
#define CLEANINGPAGE_H

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

class CleaningPage : public QWidget
{
    Q_OBJECT
public:
    CleaningPage(QWidget *parent=NULL);
private:
    friend class GuiController;
    QBoxLayout *mainLayout;

    QBoxLayout *mainLabelRow;
    QLabel *mainLabel;

    //Hier muss der Plan eingefügt werden
    QBoxLayout *planRow;
    QLabel *plan;

    QBoxLayout *buttonRow;
    QPushButton *setuptaskButton;
    QPushButton *createPlanButton;
    QPushButton *backButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

private slots:
    void taskCalled();
    void homePageCalled();

signals:
    void taskCallSignal();
    void homePageCallSignal();
};

#endif // CLEANINGPAGE_H
