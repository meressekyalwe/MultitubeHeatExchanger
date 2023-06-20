#include "nusselt.h"
#include "cmath"

Nusselt::Nusselt()
{

}

float Nusselt::getNusselt(float Re, float Pr, float d, float L)
{
    if (Re <= 2320)
    {
        return 1.61 * std::pow((Re * Pr * d / L), 0.333);
    }
    else if (Re > 2320 && Re < 10000)
    {
        return 0.008 * std::pow(Re, 0.9) * std::pow(Pr, 0.432);
    }
    else if (Re >= 10000)
    {
        return 0.021 * std::pow(Re, 0.8) * std::pow(Pr, 0.43);
    }

    return -1.f;
}







