#ifndef OWNSERVER_H
#define OWNSERVER_H

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class OwnServerConfig : public QWidget {
    Q_OBJECT
private:
    QBoxLayout* mainLayout;

    QBoxLayout* mainLabelRow;
    QLabel* mainLabel;

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

    QBoxLayout* warningLabelRow;
    QLabel* warnLabel;

    QBoxLayout* buttonRow;
    QPushButton* confirmButton;
    QPushButton* cancelButton;

    void setMainWindowDesign();
    void setMainLayoutDesign();

signals:
    void configHomeCalled();
    void sendCredentials(std::string user, std::string host, std::string password, std::string database);

private slots:
    void callHome();
    void confirm();

public:
    explicit OwnServerConfig(QWidget* parent = NULL);
    ~OwnServerConfig();
};
#endif // OWNSERVER_H
