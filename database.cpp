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
        // qDebug() << "Cannot open database:" << db.lastError();
    }
    else
    {
        // qDebug() << "database opened";
    }

    //db.close();
}

void DataBase::LinearInterpolation(float& Temp0, float& Temp1, float& Temp, float& Value0, float& Value1, float& InterpValue)
{
    InterpValue = Value0 + (Temp - Temp0) * ((Value1 - Value0) / (Temp1 - Temp0));
}

float DataBase::GetDensity(float Temperature, QString Substance)
{
    // плотность при Temperature
    float Density = 0;

    if (Temperature <= 0 || Temperature <= 100)
    {
        int Step = 20;
        // найти интервал
        float Temp0 = ((int)Temperature / Step) * Step;
        float Temp1 = Temp0 + Step;
        if (Temp1 >= 100)
        {
            Temp1 = 100;
            Temp0 = 100 - Step;
        }

        // SQL ЗАПРОС
        QSqlQuery query(db);
        // QSqlRecord rec = query.record();

        if(!query.exec("SELECT * FROM плотность WHERE наименование = '" + Substance +"';"))
        {
            qDebug() << "query failed...";
            return -1.f;
        }

        float Value0 = 0.f;
        float Value1 = 0.f;

        if (query.next())
        {
            Value0 = query.value(QString::number(Temp0)).toFloat();

            Value1 = query.value(QString::number(Temp1)).toFloat();
        }

      LinearInterpolation(Temp0, Temp1, Temperature, Value0, Value1, Density);

        // qDebug() << Density;
    }

    return Density;
}

float DataBase::GetViscosity(float Temperature, QString Substance)
{
    // плотность при Temperature
    float Viscosity = 0;

    if (Temperature <= 0 || Temperature <= 100)
    {

        int Step = 10;
        if (Temperature >= 60) Step = 20;
        // найти интервал
        float Temp0 = ((int)Temperature / Step) * Step;
        float Temp1 = Temp0 + Step;
        if (Temp1 >= 100)
        {
            Temp1 = 100;
            Temp0 = 100 - Step;
        }

        // SQL ЗАПРОС
        QSqlQuery query(db);
        // QSqlRecord rec = query.record();

        if(!query.exec("SELECT * FROM вязкость WHERE наименование = '" + Substance +"';"))
        {
            qDebug() << "query failed...";
            return -1.f;
        }

        float Value0 = 0.f;
        float Value1 = 0.f;

        if (query.next())
        {
            Value0 = query.value(QString::number(Temp0)).toFloat();

            Value1 = query.value(QString::number(Temp1)).toFloat();
        }

      LinearInterpolation(Temp0, Temp1, Temperature, Value0, Value1, Viscosity);

        // qDebug() << Viscosity;
    }

    return Viscosity;
}

float DataBase::GetHeatCapacity(float Temperature, QString Substance)
{
    // плотность при Temperature
        float HeatCapacity = 0;

        if (Temperature <= 0 || Temperature <= 100)
        {
            int Step = 20;
            // найти интервал
            float Temp0 = ((int)Temperature / Step) * Step;
            float Temp1 = Temp0 + Step;
            if (Temp1 >= 100)
            {
                Temp1 = 100;
                Temp0 = 100 - Step;
            }

            // SQL ЗАПРОС
            QSqlQuery query(db);
            // QSqlRecord rec = query.record();

            if(!query.exec("SELECT * FROM теплоемкость WHERE наименование = '" + Substance +"';"))
            {
                qDebug() << "query failed...";
                return -1.f;
            }

            float Value0 = 0.f;
            float Value1 = 0.f;

            if (query.next())
            {
                Value0 = query.value(QString::number(Temp0)).toFloat();

                Value1 = query.value(QString::number(Temp1)).toFloat();
            }

          LinearInterpolation(Temp0, Temp1, Temperature, Value0, Value1, HeatCapacity);

          //  qDebug() << HeatCapacity;
        }

        return 4.190f *HeatCapacity;
}

float DataBase::GetHeatConductivity(float Temperature, QString Substance)
{
    // плотность при Temperature
    float HeatConductivity = 0;

    if (Temperature <= 0 || Temperature <= 100)
        {
            int Step = 25;
            // найти интервал
            float Temp0 = ((int)Temperature / Step) * Step;
            float Temp1 = Temp0 + Step;
            if (Temp1 >= 100)
            {
                Temp1 = 100;
                Temp0 = 100 - Step;
            }

        // SQL ЗАПРОС
        QSqlQuery query(db);
        // QSqlRecord rec = query.record();

        if(!query.exec("SELECT * FROM теплопроводность WHERE наименование = '" + Substance +"';"))
        {
            qDebug() << "query failed...";
            return -1.f;
        }

        float Value0 = 0.f;
        float Value1 = 0.f;

        if (query.next())
        {
            Value0 = query.value(QString::number(Temp0)).toFloat();

            Value1 = query.value(QString::number(Temp1)).toFloat();
        }

      LinearInterpolation(Temp0, Temp1, Temperature, Value0, Value1, HeatConductivity);

       // qDebug() << HeatConductivity;
    }

    return HeatConductivity;
}

void DataBase::GetListOfAllSubstances(QComboBox *ComboBox)
{
    QSqlQuery query(db);

    if(!query.exec("SELECT * FROM температура_кипения;"))
    {
        qDebug() << "query failed...";
        return;
    }

    while (query.next())
    {
        ComboBox->addItem(query.value(0).toString());
        // qDebug() << query.value(0).toString();
    }
}

void DataBase::GetListOfAllMaterials(QComboBox *ComboBox)
{
    QSqlQuery query(db);

    if(!query.exec("SELECT * FROM физ_свойства_материала;"))
    {
        qDebug() << "query failed...";
        return;
    }

    while (query.next())
    {
        ComboBox->addItem(query.value(0).toString());
        // qDebug() << query.value(0).toString();
    }
}

float DataBase::GetHeatConductivityMaterial(QString Material)
{
    QSqlQuery query(db);
    float Value = 0.0f;

    if(!query.exec("SELECT * FROM физ_свойства_материала;"))
    {
        qDebug() << "query failed...";
        return -1;
    }

    while (query.next())
    {
        if (query.value(0).toString() == Material)
        {
            Value = query.value(1).toFloat();
        }
    }

    return Value;
}
