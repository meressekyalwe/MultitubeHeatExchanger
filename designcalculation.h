#ifndef DESIGNCALCULATION_H
#define DESIGNCALCULATION_H


class DesignCalculation
{
public:
    DesignCalculation();

    static float getdvn(float dn, float delta);

    static float getS1(float dvn, int n, int z);

    static float getF(float L1, int n, float dn, float dvn);

    static float getS2(float D, float n, float dn);

    static float getdeq2(float D, int n, float dn);

};

#endif // DESIGNCALCULATION_H
