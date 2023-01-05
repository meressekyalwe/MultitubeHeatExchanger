#ifndef GIVENWIDGET_H
#define GIVENWIDGET_H

#include <QObject>
#include <QGroupBox>

#include "fluid.h"
#include "designparameters.h"

class GivenWidget : public QGroupBox
{
    Q_OBJECT

public:

    GivenWidget();

    Fluid* getHotWater();

    Fluid* getColdWater();

    DesignParameters* getDesignDataClass();

private:

    Fluid* HotWater;
    Fluid* ColdWater;
    DesignParameters* DesignDataClass;
    QVBoxLayout* VBoxLayout;
};

#endif // GIVENWIDGET_H
