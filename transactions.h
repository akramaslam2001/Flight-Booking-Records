#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <QDialog>
#include "dbutility.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class transactions;
}

class transactions : public QDialog
{
    Q_OBJECT

public:
    explicit transactions(QWidget *parent = nullptr);
    ~transactions();
    void getTransDataFromDB();
private:
    Ui::transactions *ui;
};

#endif // TRANSACTIONS_H
