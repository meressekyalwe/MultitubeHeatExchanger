#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include <QSqlRecord>
#include <QTime>



class DataBase : public QSqlDatabase
{

public:

    DataBase();

    QSqlQuery* query;
    QString* statement;
    QSqlRecord* rec;
};

#endif // DATABASE_H
