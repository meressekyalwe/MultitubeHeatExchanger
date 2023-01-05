#include "database.h"
#include <QDebug>
#include <QSqlError>
#include <QString>
#include <QFile>


Database::Database(QObject *parent)
    : QObject{parent}
{
    db = QSqlDatabase::addDatabase("QSQLITE", "SQLITE");
    db.setDatabaseName("database.db");
    db.open();
}

void Database::Test(QString name)
{
    statement = "select * from thermal_conductivity";
    query.prepare(statement);

    if (!query.exec())
    {
        qDebug() << "Query failed!";
        qDebug() << query.lastError();

    }
    else
    {
        qDebug() << "Query succed!";
    }
}
