#include "bookticket.h"
#include "ui_bookticket.h"

//airoplane * bookticket::ptrToAiro = nullptr;

bookticket::bookticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookticket)
{
    ui->setupUi(this);
    ptrToAiro = nullptr;
}

bookticket::~bookticket()
{
    delete ui;
}

void bookticket::on_btnDone_clicked()
{
    //Update DB
    qDebug() << "in bookticket::on_btnDone_clicked()";
    //read DB & update UI
    QString name = ui->txtName->text();
    QString contactno = ui->txtContactNo->text();
    QString address = ui->txtAddress->text();
    QString passport = ui->txtPassportNo->text();
    QString seatNo = ui->cmbSeats->currentText();

    DBUtility::getInstance()->initDB();
    QSqlDatabase  db =  DBUtility::getInstance()->getDBInstance();
    QSqlQuery query(db);
        query.prepare("update cppbuzz_airo_seats set available='N' where seat_number='" + seatNo + "'");

        if(!query.exec())
               qDebug() << query.lastError().text() << query.lastQuery();
        else
            qDebug() << "update was successful "<< query.lastQuery();


         query.clear();

         query.prepare("insert into cppbuzz_airo_transaction (customername, customer_contact_no, customer_address, customer_passport) values ('" + name + "','" + contactno + "','" + address + "','" + passport + "')");

            if(!query.exec())
                qDebug() << query.lastError().text() << query.lastQuery();
            else
                qDebug() << "update was successful "<< query.lastQuery();


        db.close();

        this->hide();
        checkStatus();
}

bool bookticket::reservationFull()
{
    DBUtility::getInstance()->initDB();
    QSqlDatabase  db =  DBUtility::getInstance()->getDBInstance();
    QSqlQuery query(db);
        query.prepare("select count(*) from cppbuzz_airo_seats where available='Y'");

        if(!query.exec())
            qDebug() << query.lastError().text() << query.lastQuery();
        else
            qDebug() << "read was successful "<< query.lastQuery();
        //db.close();

        int count = -1;
        query.next();
        count = query.value(0).toInt();
        //query.clear();
        qDebug() << "count is : "<<count;
        db.close();

    if(count == 0 )
    {
        return true;

    }
    return false;
}

void bookticket::getTicketsFromDB()
{
    qDebug() << "in bookticket::getTicketsFromDB()";
    //read DB & update UI

    DBUtility::getInstance()->initDB();
    QSqlDatabase  db =  DBUtility::getInstance()->getDBInstance();
    QSqlQuery query(db);
        query.prepare("select seat_number from cppbuzz_airo_seats where available='Y'");

        if(!query.exec())
            qDebug() << query.lastError().text() << query.lastQuery();
        else
            qDebug() << "Read was successful "<< query.lastQuery();

        char tempFlag = 0;
        while(query.next())
        {
            tempFlag = 1;
            QString record = query.value(0).toString();
            //ui->cmb  ush_back(record.toInt());
            //this->ui->comboBox->addItem(record);
            ui->cmbSeats->addItem(record);
            qDebug()<<"Line is : "<<record;
        }

        if(tempFlag == 0)
        {
            ui->txtName->setReadOnly(true);
            ui->btnDone->hide();

        }
        db.close();
}

void bookticket::setAiroplane(airoplane *ptr)
{
    qDebug()<<" bookticket::setAiroplane()";
    this->ptrToAiro = ptr;
}

void bookticket::checkStatus()
{
    qDebug()<<" bookticket::checkStatus()";
    bool isReservatiofull = reservationFull();
    qDebug()<<"isReservationfull: "<<isReservatiofull;

    if(ptrToAiro == nullptr)
        qDebug() << "ptrToAiro is null";

    if(isReservatiofull)
    {
        flag = 1; //setting global flag to show reservation is full
        reset();
    }
}

void bookticket::reset()
{
    DBUtility::getInstance()->initDB();
    QSqlDatabase  db =  DBUtility::getInstance()->getDBInstance();
    QSqlQuery query(db);
        query.prepare("update cppbuzz_airo_seats set available='Y'");

        if(!query.exec())
            qDebug() << query.lastError().text() << query.lastQuery();
        else
            qDebug() << "Read was successful "<< query.lastQuery();

}
