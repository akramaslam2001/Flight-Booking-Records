#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QGraphicsItem>

namespace Ui {
class menu;
}

class menu : public QDialog, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private:
    Ui::menu *ui;
};

#endif // MENU_H
