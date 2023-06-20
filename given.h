#ifndef GIVEN_H
#define GIVEN_H

#include <QObject>
#include <QString>

#include "Types.h"

class Given : public QObject
{
    Q_OBJECT
public:
    explicit Given(QObject *parent = nullptr);

// Теплоносители
    FluidPhysicalProperties hotFluid;

    FluidPhysicalProperties coldFluid;

    Material material;

// Размеры
    DesignData designData;

// методы
    void getFromDatabase();

    void setHotFluid(QString name, float G, float t);

    void setColdFluid(QString name, float G, float t);

    void setDesignData(DesignData& IndesignData);


};

#endif // GIVEN_H
