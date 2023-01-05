#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTSql>

struct Data
{
    QString name;
    int value;
};

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);

signals:

public:

    void Test(QString name);

private:
    QSqlDatabase db;
    QSqlQuery query;
    QString statement;
    bool ok = false;
    QSqlRecord rec;
};

#endif // DATABASE_H
