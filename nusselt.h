#ifndef NUSSELT_H
#define NUSSELT_H


class Nusselt
{
public:
    Nusselt();

    static float getNusselt(float Re, float Pr, float d, float L);

};

#endif // NUSSELT_H
