#ifndef SETUPCONFIGURATION_H
#define SETUPCONFIGURATION_H

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "LocalHostConfig.h"
#include "OwnServerConfig.h"
#include "../../Database/lib/DatabaseConfig.h"
#include "PopUpWindow.h"

class SetUpConfiguration : public QWidget {
    Q_OBJECT
private:
    LocalHostConfig local;
    OwnServerConfig server;
    DatabaseConfig config;
    PopUpWindow popUp;

    QBoxLayout* mainLayout;

    QBoxLayout* mainLabelRow;
    QLabel* mainLabel;

    QBoxLayout* buttonRow;
    QPushButton* localHost;
    QPushButton* ownServer;

    void setMainWindowDesign();
    void setMainLayoutDesign();

private slots:
    void callOwnServer();
    void callLocalHost();
    void callConfigHome();
    void saveCredentials(std::string user, std::string host, std::string password, std::string database);

public:
    explicit SetUpConfiguration(QWidget* parent = NULL);
};
#endif // SETUPCONFIGURATION_H
