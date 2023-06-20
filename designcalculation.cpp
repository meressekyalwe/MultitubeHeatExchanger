#include "designcalculation.h"
#include "cmath"

DesignCalculation::DesignCalculation()
{

}

float DesignCalculation::getdvn(float dn, float delta)
{
    return (dn - 2 * delta);
}

float DesignCalculation::getS1(float dvn, int n, int z)
{
    return (std::pow(dvn, 2) * 0.785 * n / z);
}

float DesignCalculation::getF(float L1, int n, float dn, float dvn)
{
    return (3.14 * L1 * n * (dn + dvn) / 2);
}

float DesignCalculation::getS2(float D, float n, float dн)
{
    return (0.785 * (std::pow(D, 2) - n * std::pow(dн, 2)));
}

float DesignCalculation::getdeq2(float D, int n, float dn)
{
    return (std::pow(D, 2) - n * std::pow(dn, 2)) / (D + n * dn);
}
