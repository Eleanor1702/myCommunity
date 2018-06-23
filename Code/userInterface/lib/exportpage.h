#ifndef EXPORTPAGE_H
#define EXPORTPAGE_H
#include <QApplication>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>

#include <QStyle>
#include <QDesktopWidget>

class exportPage : public QWidget{
    Q_OBJECT

private:
    friend class GuiController;

    //Design Elements

    QBoxLayout *mainLayout;

    QBoxLayout *mainLabelRow;
    QLabel *mainLabel;

    QBoxLayout *cleaningButtonRow;
    QBoxLayout *shoppingButtonRow;
    QBoxLayout *backButtonRow;

    QPushButton *backButton;
    QPushButton *cleaningExportButton;
    QPushButton *shoppingExportButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

private slots:
    void cleaningExportCalled();
    void shoppingExportCalled();
    void homePageCalled();

signals:
    void homePageCallSignal();
    void shoppingExportSignal();
    void cleaningExportSignal();

public:
    explicit exportPage(QWidget *parent = NULL);


};



#endif // EXPORTPAGE_H
