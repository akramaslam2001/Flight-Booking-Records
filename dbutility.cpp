#include "dbutility.h"

DBUtility * DBUtility::instance = nullptr;

DBUtility::DBUtility()
{

}

DBUtility *DBUtility::getInstance()
{
    if(instance == nullptr)
    {
        instance = new DBUtility();


    }
    return instance;
}

void DBUtility:: initDB()
{
    myDB = QSqlDatabase::addDatabase("QSQLITE", "Data");
    myDB.setDatabaseName("c:/cppbuzz_airo_managment.sqlite");

    if(QFile::exists("c:/cppbuzz_airo_managment.sqlite"))
            qDebug() << "DB file exist";
        else
           qDebug() << "DB file doesn't exists";

        if (!myDB.open())
            qDebug() << myDB.lastError().text();
        else
            qDebug() << "Database loaded successfull!";
}

QSqlDatabase DBUtility::getDBInstance()
{
    return myDB;
}
std::vector<char> DBUtility::getSeats()
{
    std::vector<char> seats;

    return seats;


}

void DBUtility::updateSeats(QString seatno, QString bookOrCheckOut)
{
    //
}
