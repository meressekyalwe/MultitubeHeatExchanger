#ifndef HEATTRANSFERCOEFFICIENT_H
#define HEATTRANSFERCOEFFICIENT_H

#include "nusselt.h"


class HeatTransferCoefficient
{
public:
    HeatTransferCoefficient();

    static float getW(float G, float rhoo, float S);

    static float getRe(float W, float dvn, float rhoo, float miu);

    static float getAlpha(float Nu, float lambda, float dvn);

    static float getK(float alpha1, float alpha2, float lambdaSt, float delta);

private:

    Nusselt nusselt;
};

#endif // HEATTRANSFERCOEFFICIENT_H
