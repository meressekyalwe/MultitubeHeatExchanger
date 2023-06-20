#include "results.h"
#include "heattransfersurface.h"
#include "designcalculation.h"
#include "nusselt.h"
#include <QString>


Results::Results(QObject *parent)
    : QObject{parent}
{

}

void Results::setCurrentMaterial(GivenWidget* gw, DataBase& db)
{
    Material.Name = gw->DesignDataClass->SelectMaterial->currentText();
    Material.HeatConductivity = db.GetHeatConductivityMaterial(Material.Name);

    DesignData.Length = gw->DesignDataClass->LengthValue->value();
    DesignData.ShellDiameter = (gw->DesignDataClass->DiameterValue->text()).toFloat();
    DesignData.TubeOuterDiameter = (gw->DesignDataClass->TubeOuterDiameterValue->text()).toFloat();
    DesignData.NumberOfTube = gw->DesignDataClass->ValueNumberPipe->value();
    DesignData.NumberOfPasses = gw->DesignDataClass->ValueNumberPasses->value();
    DesignData.WallThickness = (gw->DesignDataClass->WallThicknessValue->text()).toFloat();
    DesignData.Time = (gw->DesignDataClass->TimeValue->text()).toFloat();
}

void Results::setCurrentHotFluid(GivenWidget* gw, DataBase& db)
{
    HotFluid.Name = gw->HotFluid->SelectComponent->currentText();
    HotFluid.InitialTemperature = gw->HotFluid->TemperatureValue->value();
    HotFluid.Flow = gw->HotFluid->FlowValue->value();

    HotFluid.Density = db.GetDensity(HotFluid.InitialTemperature, HotFluid.Name);
    HotFluid.HeatCapacity = db.GetHeatCapacity(HotFluid.InitialTemperature, HotFluid.Name);
    HotFluid.Viscosity = db.GetViscosity(HotFluid.InitialTemperature, HotFluid.Name);
    HotFluid.HeatConductivity = db.GetHeatConductivity(HotFluid.InitialTemperature, HotFluid.Name);
}

void Results::setCurrentColdFluid(GivenWidget* gw, DataBase& db)
{
    ColdFluid.Name = gw->ColdFluid->SelectComponent->currentText();
    ColdFluid.InitialTemperature = gw->ColdFluid->TemperatureValue->value();
    ColdFluid.Flow = gw->ColdFluid->FlowValue->value();

    ColdFluid.Density = db.GetDensity(ColdFluid.InitialTemperature, ColdFluid.Name);
    ColdFluid.HeatCapacity = db.GetHeatCapacity(ColdFluid.InitialTemperature, ColdFluid.Name);
    ColdFluid.Viscosity = db.GetViscosity(ColdFluid.InitialTemperature, ColdFluid.Name);
    ColdFluid.HeatConductivity = db.GetHeatConductivity(ColdFluid.InitialTemperature, ColdFluid.Name);
}

void Results::setFromDb(DataBase& db, int t11, int t21)
{
    // HotFluid
    _HotFluid.Density = db.GetDensity(t11, HotFluid.Name);
    _HotFluid.HeatCapacity = db.GetHeatCapacity(t11, HotFluid.Name);
    _HotFluid.Viscosity = db.GetViscosity(t11, HotFluid.Name);
    _HotFluid.HeatConductivity = db.GetHeatConductivity(t11, HotFluid.Name);

    // ColdFluid
    _ColdFluid.Density = db.GetDensity(t21, ColdFluid.Name);
    _ColdFluid.HeatCapacity = db.GetHeatCapacity(t21, ColdFluid.Name);
    _ColdFluid.Viscosity = db.GetViscosity(t21, ColdFluid.Name);
    _ColdFluid.HeatConductivity = db.GetHeatConductivity(t21, ColdFluid.Name);
}

float Results::FK(DataBase& db)
{
    //setFromDb(db, HotFluid.InitialTemperature, ColdFluid.InitialTemperature);
    float Pr1 = _HotFluid.Viscosity * _HotFluid.HeatCapacity / _HotFluid.HeatConductivity;
    float dvn = DesignCalculation::getdvn(DesignData.TubeOuterDiameter, DesignData.WallThickness);
    float W1 = _HotFluid.Flow / (_HotFluid.Density * DesignCalculation::getS1(dvn, DesignData.NumberOfTube, DesignData.NumberOfPasses));
    float Re1 = W1 * dvn * _HotFluid.Density / _HotFluid.Viscosity;
    float Nu1 = Nusselt::getNusselt(Re1, Pr1, dvn, DesignData.Length);
    float alpha1 = Nu1 * _HotFluid.HeatConductivity / dvn;

    float Pr2 = _ColdFluid.Viscosity * _ColdFluid.HeatCapacity / _ColdFluid.HeatConductivity;
    float deq2 = DesignCalculation::getdeq2(DesignData.ShellDiameter, DesignData.NumberOfTube, DesignData.TubeOuterDiameter);
    float W2 = _ColdFluid.Flow / (_ColdFluid.Density * DesignCalculation::getS2(DesignData.ShellDiameter, DesignData.NumberOfTube, DesignData.TubeOuterDiameter));
    float Re2 = W2 * deq2 * _ColdFluid.Density / _ColdFluid.Viscosity;
    float Nu2 = Nusselt::getNusselt(Re2, Pr2, deq2, DesignData.Length);
    float alpha2 = Nu2 * _ColdFluid.HeatConductivity / deq2;

    return (1 / (1 / alpha1 + DesignData.WallThickness / Material.HeatConductivity + 1 / alpha2));
}

float Results::yy(DataBase& db,int t12)
{
    float Q = HotFluid.Flow * HotFluid.HeatCapacity * (HotFluid.InitialTemperature - t12);
    int t22 = static_cast<int>(ColdFluid.InitialTemperature + (Q / (ColdFluid.Flow * ColdFluid.HeatCapacity)));
    int tcp1 = (HotFluid.InitialTemperature + t12) / 2;
    int tcp2 = (ColdFluid.InitialTemperature + t22) / 2;
    setFromDb(db, tcp1, tcp2);
    float K = FK(db);
    int deltaTb = HeatTransferSurface::deltatB(HotFluid.InitialTemperature, t22);
    int deltaTm = HeatTransferSurface::deltatM(t12, ColdFluid.InitialTemperature);
    float A = HeatTransferSurface::A(HotFluid.InitialTemperature, t12, ColdFluid.InitialTemperature, t22);
    float x = HeatTransferSurface::x(deltaTb, deltaTm, A);
    float deltaTcp = A / std::log(x);
    float F = DesignCalculation::getF(DesignData.Length, DesignData.NumberOfTube, DesignData.TubeOuterDiameter, DesignCalculation::getdvn(DesignData.TubeOuterDiameter, DesignData.WallThickness));
    float Fp = Q / (K * deltaTcp);

    return F - Fp;
}

float Results::met_del(DataBase& db)
{
    int x1 = (HotFluid.InitialTemperature + ColdFluid.InitialTemperature) / 2;
    int x2 = (HotFluid.InitialTemperature - 1);

    int x = (x1 + x2) / 2;

    if (Fi(yy(db, x1)) == Fi(yy(db, x)))
    {
        x1 = x;
        return x1;
    }
    else
    {
        x2 = x;
        return x2;
    }

    return {};
}

float Results::Fi(float value)
{
    float f;

    if (value < 0.f)
    {
        f = 0.f;
    }
    else if (value == 0.f)
    {
        f = 0.5f;
    }
    else
    {
        f = 1.0f;
    }

    return f;
}

void Results::Calculate(DataBase &db)
{
    HotFluid.FinalTemperature = static_cast<int>(met_del(db));
    float Q = HotFluid.Flow * HotFluid.HeatCapacity * (HotFluid.InitialTemperature - HotFluid.FinalTemperature);
    ColdFluid.FinalTemperature = static_cast<int>(ColdFluid.InitialTemperature + Q / (ColdFluid.Flow * ColdFluid.HeatCapacity));
}





















