#ifndef DBUTITLITY_H
#define DBUTITLITY_H
#include <vector>
#include <QSqlDatabase>
#include <QFile>
#include <QDebug>
#include <QSqlError>


class DBUtility
{
private:
    DBUtility();
    DBUtility(DBUtility &);
    static DBUtility * instance;
    QSqlDatabase myDB;

public:
    static DBUtility* getInstance();
    std::vector<char> getSeats();
    void updateSeats(QString seatno, QString bookOrCheckOut="y");
    void initDB();
    QSqlDatabase getDBInstance();
};

#endif // DBUTITLITY_H
