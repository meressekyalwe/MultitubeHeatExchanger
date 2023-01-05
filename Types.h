#ifndef TYPES_H
#define TYPES_H

#include <QString>

struct Material
{
    QString Name;
    float HeatConductivity;
};

struct FluidPhysicalProperties
{
    float MolarMass; // молярная масса
    float Flow; // расход
    int InitialTemperature; // начальная температура
    int FinalTemperature; // конечная температура
    float Density; // плотность
    float HeatCapacity; // теплоемкость
    float Viscosity; // вязкость
    float HeatConductivity; // коэф. теплопровдности жидкости
};

struct DesignData
{
    float Length; // длина аппарата
    float ShellDiameter; // диаметр корпуса
    float TubeOuterDiameter; // наружны диметр трубы
    float WallThickness; // тольщина стенки
    int NumberOfTube; // число труб
    int NumberOfPasses; // число ходов
    float Time; // время
};


#endif // TYPES_H
