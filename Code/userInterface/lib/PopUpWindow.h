#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

class PopUpWindow : public QWidget {
    Q_OBJECT
private:
    QBoxLayout* mainLayout;
    QBoxLayout* labelRow;
    QLabel* mainLabel;
    QBoxLayout* msgRow;
    QLabel* msgLabel;
    QBoxLayout* buttonRow;
    QPushButton* okButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

public:
    explicit PopUpWindow(QWidget* parent = NULL);
    ~PopUpWindow();
};

#endif // POPUPWINDOW_H
