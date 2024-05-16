#ifndef AVAILABLETICKETS_H
#define AVAILABLETICKETS_H
#include <QDebug>

#include <QDialog>
#include "dbutility.h"
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class availabletickets;
}

class availabletickets : public QDialog
{
    Q_OBJECT

public:
    explicit availabletickets(QWidget *parent = nullptr);
    ~availabletickets();
    void getTicketsFromDB();

private:
    Ui::availabletickets *ui;
};

#endif // AVAILABLETICKETS_H
