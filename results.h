#ifndef RESULTS_H
#define RESULTS_H

#include <QObject>
#include "Types.h"
#include "database.h"
#include "givenwidget.h"



class Results : public QObject
{
    Q_OBJECT
public:
    explicit Results(QObject *parent = nullptr);

    Results(GivenWidget* gw);

    void setCurrentMaterial(GivenWidget* gw, DataBase& db);

    void setCurrentHotFluid(GivenWidget* gw, DataBase& db);

    void setCurrentColdFluid(GivenWidget* gw, DataBase& db);

    void setFromDb(DataBase& db, int t11, int t21);

    float FK(DataBase& db);

    float yy(DataBase& db, int t12);

    float met_del(DataBase& db);

    float Fi(float value);

    void Calculate(DataBase& db);

public:
    S_Fluid HotFluid;
    S_Fluid ColdFluid;
    S_DesignData DesignData;
    S_Material Material;
private:
    S_Fluid _HotFluid;
    S_Fluid _ColdFluid;
};

#endif // RESULTS_H
