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
    GivenWidget(DataBase& db);
    Fluid* HotFluid;
    Fluid* ColdFluid;
    DesignParameters* DesignDataClass;
    QVBoxLayout* VBoxLayout;
};

#endif // GIVENWIDGET_H
