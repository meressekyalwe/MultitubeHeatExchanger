#include "database.h"
#include <QDebug>
#include <QApplication>
#include <QSqlError>

DataBase::DataBase()
{
    QSqlDatabase::addDatabase("QSQLITE");
    setHostName("bigblue");
    setDatabaseName("database.db");
    setUserName("acarlson");
    setPassword("1uTbSbAs");
    bool ok = open();

    if (ok)
    {
     qDebug() << "DB opened !";
    }
    else
    {
        qDebug() << QSqlDatabase::lastError();
        qDebug() << isDriverAvailable("QSQLITE");
        qDebug() << QSqlDatabase::drivers();
    }

    close();
}
