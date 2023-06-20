#ifndef HEATTRANSFERSURFACE_H
#define HEATTRANSFERSURFACE_H


class HeatTransferSurface
{
public:
    HeatTransferSurface();

    static float heat(float G1, float c1, float t11, float t21);

    static float t22(float t21, float heat, float G2, float c2);

    static float tcp1(float t11, float t12);

    static float tcp2(float t21, float t22);

    static float deltatB(float t11, float t22);

    static float deltatM(float t12, float t21);

    static float A(float t11, float t12, float t21, float t22);

    static float x(float deltatB, float deltatM, float A);

    static float deltatcp(float A, float x);

    static float fp(float Q, float K, float deltatcp);

    static float yy(float f, float fp);

};

#endif // HEATTRANSFERSURFACE_H
