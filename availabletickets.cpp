#include "availabletickets.h"
#include "ui_availabletickets.h"

availabletickets::availabletickets(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::availabletickets)
{
    ui->setupUi(this); 
}

availabletickets::~availabletickets()
{
    delete ui;
}

void availabletickets::getTicketsFromDB()
{
   qDebug()<<" in availabletikets:: getTicketsFromDB()";
   //read DB & Upate UI

   //read DB
   qDebug() << "in bookticket::on_btnDone_clicked()";
   //read DB & update UI

   DBUtility::getInstance()->initDB();
   QSqlDatabase  db =  DBUtility::getInstance()->getDBInstance();
   QSqlQuery query(db);
       query.prepare("select seat_number from cppbuzz_airo_seats where available='Y'");

       if(!query.exec())
           qDebug() << query.lastError().text() << query.lastQuery();
       else
           qDebug() << "read was successful "<< query.lastQuery();
       //db.close();

       //set default style
       ui->lblinfo->setStyleSheet("QLabel { background-color : grey; color : aqua; }");

       for(char i = 'A'; i<='O'; i++ )
       {
           QString lblname = "lbl" + QString(i);
           QLabel * ptr = this->findChild<QLabel*>(lblname);
           ptr->setStyleSheet("QLabel { background-color : lightgrey; color : aqua; }");
       }

       //changin default style of seats those are available
       while(query.next())
       {
           QString seat = query.value(0).toString();
           QString lblname = "lbl" + seat;
           //qDebug()<<"finding :"<< lblname;

           QLabel * ptr = this->findChild<QLabel*>(lblname);

           if(ptr)
           {
               ptr->setStyleSheet("QLabel { background-color : grey; color : aqua; }");
           }
       }

   //this->hide();
}
