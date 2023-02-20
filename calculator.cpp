#include "calculator.h"

Calculator::Calculator(QObject *parent)
    : QObject{parent}
{

}

float Calculator::FluidSpeed(DesignParameters* DesignData, Fluid* Fluid)
{
    float Speed = 0.f;

    if (Fluid->Hot)
    {
        Speed = Fluid->Properties.Flow / (Fluid->Properties.Density * DesignData->Cross_SectionalAreaOfTubeSpace());
    }
    else
    {
        Speed = Fluid->Properties.Flow / (Fluid->Properties.Density * DesignData->AnnulusCross_SectionalArea());
    }

    return Speed;
}

float Calculator::ReynoldsNumber(DesignParameters* DesignData, Fluid* Fluid)
{
    float Reynolds = 0.f;

    if (Fluid->Hot)
    {

    }
    else
    {

    }

    return Reynolds;
}

float Calculator::NusseltNumber(DesignParameters* DesignData, Fluid* Fluid)
{
    float Nusselt = 0.f;


    return Nusselt;
}

float Calculator::HeatTransfertCoefficient(DesignParameters* DesignData, Fluid* Fluid)
{

}

float Calculator::AreaRequired(DesignParameters* DesignData, Fluid* Fluid)
{

}

