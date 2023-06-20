#include "heattransfercoefficient.h"

HeatTransferCoefficient::HeatTransferCoefficient()
{

}

float HeatTransferCoefficient::getW(float G, float rhoo, float S)
{
    return (G / (rhoo * S));
}

float HeatTransferCoefficient::getRe(float W, float dvn, float rhoo, float miu)
{
    return (W * dvn * rhoo / miu);
}

float HeatTransferCoefficient::getAlpha(float Nu, float lambda, float dvn)
{
    return (Nu * lambda / dvn);
}

float HeatTransferCoefficient::getK(float alpha1, float alpha2, float lambdaSt, float delta)
{
    return (1 / ((1 / alpha1) + (delta / lambdaSt) + (1 / alpha2)));
}




