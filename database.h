#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include <QVector>



class DataBase : public QObject
{

public:

    DataBase();

    void test();



private:
    //
    QSqlDatabase db;
};

#endif // DATABASE_H
