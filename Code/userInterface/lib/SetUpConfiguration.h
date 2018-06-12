#ifndef SETUPCONFIGURATION_H
#define SETUPCONFIGURATION_H

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class SetUpConfiguration : public QWidget {
    Q_OBJECT

private:
    QBoxLayout* mainLayout;

    QBoxLayout* mainLabelRow;
    QLabel* mainLabel;

    QBoxLayout* buttonRow;
    QPushButton* localHost;
    QPushButton* ownServer;

    //localHost Setup:
    QBoxLayout* userRow;
    QLabel* userLabel;
    QLineEdit* userInput;

    QBoxLayout* hostRow;
    QLabel* hostLabel;
    QLineEdit* hostInput;

    QBoxLayout* passwordRow;
    QLabel* passwordLabel;
    QLineEdit* passwordInput;

    QBoxLayout* databaseRow;
    QLabel* databaseLabel;
    QLineEdit* databaseInput;

    QBoxLayout* localButtonRow;
    QPushButton* confirmButton;
    QPushButton* cancelButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();
    void setOwnServer();

private slots:
    void setLocalHost();
    void callConfigHome();

public:
    explicit SetUpConfiguration(QWidget* parent = NULL);
};
#endif // SETUPCONFIGURATION_H
