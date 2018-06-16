#ifndef SHOPPINGLISTITEM_H
#define SHOPPINGLISTITEM_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class ShoppinglistItem : public QFrame {
    Q_OBJECT
private:
    friend class GuiController;

    QLabel* item;
    QPushButton* deleteButton;
    QHBoxLayout* newItemLayout;

    QString name;

    void setItemStyle();

private slots:
    void deleteShopItem();

signals:
    void deleteShopItemSignal(QString name);

public:
    //QFrame ist ein QWidget
    explicit ShoppinglistItem(QString itemName, std::string number, QWidget* parent = NULL);

};
#endif // SHOPPINGLISTITEM_H

