#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

#include "fluid.h"
#include "designparameters.h"

class Calculator : public QObject
{
    Q_OBJECT

public:

    // физические своиства теплоносители при заданные температуры теплоносители
    explicit Calculator(QObject *parent = nullptr);

    // процедура расчета поверхности теплопередачи
    float FluidSpeed(DesignParameters* DesignData, Fluid* Fluid);

    float ReynoldsNumber(DesignParameters* DesignData, Fluid* Fluid);

    float NusseltNumber(DesignParameters* DesignData, Fluid* Fluid);

    float HeatTransfertCoefficient(DesignParameters* DesignData, Fluid* Fluid);

    float AreaRequired(DesignParameters* DesignData, Fluid* Fluid);

    // процедура расчета коэффициента теплопередачи



};


#endif // CALCULATOR_H
