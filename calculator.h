#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

#include "fluid.h"

class Calculator : public QObject
{
    Q_OBJECT

public:
    // физические своиства теплоносители при заданные температуры теплоносители
    explicit Calculator(QObject *parent = nullptr);

    void CalculateDensity(Fluid* Fluid); // расчёт плотности

    void CalculateHeatCapacity(Fluid* Fluid); // расчёт теплоемкости

    void CalculateViscosity(Fluid* Fluid); // расчёт вязкости

    void CalculateHeatConductivity(Fluid* Fluid); // расчёт коэф. теплопродности

    // конструктивные расчёты
    void Cross_SectionalAreaOfTubeSpace(DesignData* DesignData); // плошадь поперечного сечения трубного пространства

    void AnnulusCross_SectionalArea(DesignData* DesignData); // площадь поперечного сечения межтрубного пространства

    void EquivalentAnnulusDiameter(DesignData* DesignData); // эквивалентный диаметр по межтрубному пространству

    // процедура расчета поверхности теплопередачи
    void FluidSpeed(DesignData* DesignData, Fluid* Fluid);

    void ReynoldsNumber(DesignData* DesignData, Fluid* Fluid);

    void NusseltNumber(DesignData* DesignData, Fluid* Fluid);

    void HeatTransfertCoefficient(DesignData* DesignData, Fluid* Fluid);

    void AreaRequired(DesignData* DesignData, Fluid* Fluid);

    // процедура расчета коэффициента теплопередачи



};


#endif // CALCULATOR_H
