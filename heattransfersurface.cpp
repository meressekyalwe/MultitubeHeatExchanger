#include "heattransfersurface.h"
#include "cmath"

HeatTransferSurface::HeatTransferSurface()
{

}

float HeatTransferSurface::heat(float G1, float c1, float t11, float t21)
{
    return (G1 * c1 * (t11 - t21));
}

float HeatTransferSurface::t22(float t21, float heat, float G2, float c2)
{
    return (t21 + (heat / (G2 * c2)));
}

float HeatTransferSurface::tcp1(float t11, float t12)
{
    return ((t11 + t12) / 2);
}

float HeatTransferSurface::tcp2(float t21, float t22)
{
    return ((t21 + t22) / 2);
}

float HeatTransferSurface::deltatB(float t11, float t22)
{
    return (t11 - t22);
}

float HeatTransferSurface::deltatM(float t12, float t21)
{
    return (t12 - t21);
}

float HeatTransferSurface::A(float t11, float t12, float t21, float t22)
{
    return std::sqrt(std::pow((t11 - t12), 2.0) + std::pow((t22 - t21), 2.0));
}

float HeatTransferSurface::x(float deltatB, float deltatM, float A)
{
    return ((deltatB + deltatM + A) / (deltatB + deltatM - A));
}

float HeatTransferSurface::deltatcp(float A, float x)
{
    return (A / x);
}

float HeatTransferSurface::fp(float Q, float K, float deltatcp)
{
    return (Q / (K * deltatcp));
}

float HeatTransferSurface::yy(float f, float fp)
{
    return (f - fp);
}

