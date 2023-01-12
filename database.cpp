#include "database.h"
#include <QDebug>
#include <QApplication>
#include <QSqlError>
#include <QSqlDriver>

DataBase::DataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");

    db.open();

    if(!db.isOpen())
    {
        qDebug() << "Cannot open database:" << db.lastError();
    }
    else
    {
        //qDebug() << "Ok";
    }

    //db.close();
}

void DataBase::test()
{

    if (db.isOpen())
    {
        QString query = "select * from вязкость;";
        QSqlQuery sqlQ(db);

        if(!sqlQ.exec(query)) {
            qDebug() << "query failed...";
            return;
        }


        while (sqlQ.next())
        {
            qDebug() << sqlQ.value(0).toString(),sqlQ.value(3).toFloat();
        }
    }
}
