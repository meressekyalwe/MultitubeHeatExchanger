#ifndef TYPES_H
#define TYPES_H

#include <QString>

struct S_Material
{
    QString Name = QString("none");
    float Density = 0.f;
    float HeatConductivity = 0.f;

    S_Material& operator = (const S_Material& other)
    {
        Name = other.Name;
        Density = other.Density;
        HeatConductivity = other.HeatConductivity;
        return *this;
    }
};

struct S_Fluid
{
    QString Name; // Имя вещества
    float MolarMass = 0.f; // молярная масса
    float Flow = 0.f; // расход
    int InitialTemperature = 0; // начальная температура
    int FinalTemperature = 0; // конечная температура
    float Density = 0.f; // плотность
    float HeatCapacity = 0.f; // теплоемкость
    float Viscosity = 0.f; // вязкость
    float HeatConductivity = 0.f; // коэф. теплопровдности жидкости
};

struct S_DesignData
{
    float Length = 0.f; // длина аппарата
    float ShellDiameter = 0.f; // диаметр корпуса
    float TubeOuterDiameter = 0.f; // наружны диметр трубы
    float WallThickness = 0.f; // тольщина стенки
    int NumberOfTube = 0; // число труб
    int NumberOfPasses = 0; // число ходов
    float Time = 0.f; // время

    S_DesignData& operator = (const S_DesignData& other)
    {
        Length = other.Length;
        ShellDiameter = other.ShellDiameter;
        TubeOuterDiameter = other.TubeOuterDiameter;
        WallThickness = other.WallThickness;
        NumberOfTube = other.NumberOfTube;
        NumberOfPasses = other.NumberOfPasses;
        Time = other.Time;
        return *this;
    }
};


#endif // TYPES_H
