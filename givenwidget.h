#ifndef GIVENWIDGET_H
#define GIVENWIDGET_H

#include <QObject>
#include <QGroupBox>

#include "fluid.h"
#include "designparameters.h"
#include "database.h"

class GivenWidget : public QGroupBox
{
    Q_OBJECT

public:

    GivenWidget();

    Fluid* getHotWater();

    Fluid* getColdWater();

    void GetFromDatabase();

    DesignParameters* getDesignDataClass();


    Fluid* HotFluid;
    Fluid* ColdFluid;
    DesignParameters* DesignDataClass;
    QVBoxLayout* VBoxLayout;
    DataBase* Db;
};

#endif // GIVENWIDGET_H
