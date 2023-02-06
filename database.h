#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include <QVector>



class DataBase : public QObject
{

public:

    DataBase();

    void LinearInterpolation(float& Temp0, float& Temp1, float& Temp, float& Value0, float& Value1, float& InterpValue);

    float GetDensity(float Temperature, QString Substance = QString(tr("Вода")));

    float GetViscosity(float Temperature, QString Substance = QString(tr("Вода")));

    float GetHeatCapacity(float Temperature, QString Substance = QString(tr("Вода")));

    float GetHeatConductivity(float Temperature, QString Substance = QString(tr("Вода")));

    //
    void GetListOfAllSubstances(QComboBox* ComboBox);

    void GetListOfAllMaterials(QComboBox* ComboBox);

private:
    //
    QSqlDatabase db;
};

#endif // DATABASE_H
