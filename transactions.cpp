#include "transactions.h"
#include "ui_transactions.h"

transactions::transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transactions)
{
    ui->setupUi(this);
}

transactions::~transactions()
{
    delete ui;
}

void transactions::getTransDataFromDB()
{

    DBUtility::getInstance()->initDB();
    QSqlDatabase  db =  DBUtility::getInstance()->getDBInstance();
    QSqlQuery query(db);
    query.prepare("select * from cppbuzz_airo_transaction order by id desc");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "update was successful "<< query.lastQuery();


     while(query.next())
     {

         this->ui->lstWidget->addItem(query.value(1).toString() +"************"+ query.value(2).toString() +"************"+ query.value(3).toString() );
         qDebug() << query.value(0).toString() << " " << query.value(1).toString() << query.value(2).toString() << query.value(3).toString();
     }
     db.close();
}
