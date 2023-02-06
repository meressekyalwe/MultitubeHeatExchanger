#include "givenwidget.h"

GivenWidget::GivenWidget()
{
    setTitle(tr("Исходные данные "));

    HotFluid = new Fluid;
    ColdFluid = new Fluid;
    DesignDataClass = new DesignParameters;

    HotFluid->setTitle(tr("Горячий теплоноситель "));
    ColdFluid->setTitle(tr("Холодный теплоноситель "));
    DesignDataClass->setTitle(tr("Конструктивные параметры аппарата "));

    VBoxLayout = new QVBoxLayout;
    VBoxLayout->addWidget(HotFluid, 3);
    VBoxLayout->addWidget(ColdFluid, 3);
    VBoxLayout->addWidget(DesignDataClass, 6);

    setLayout(VBoxLayout);

    Db = new DataBase();
    Db->GetListOfAllSubstances(HotFluid->SelectComponent);
    Db->GetListOfAllSubstances(ColdFluid->SelectComponent);
    Db->GetListOfAllMaterials(DesignDataClass->SelectMaterial);
}

Fluid* GivenWidget::getHotWater()
{
    return HotFluid;
}

Fluid* GivenWidget::getColdWater()
{
    return ColdFluid;
}

void GivenWidget::GetFromDatabase()
{
    float Temp1 = HotFluid->Properties.InitialTemperature;
    QString Name1 = HotFluid->Properties.Name;
    HotFluid->Properties.Density = Db->GetDensity(Temp1, Name1);
    HotFluid->Properties.HeatCapacity = Db->GetHeatCapacity(Temp1, Name1);
    HotFluid->Properties.HeatConductivity = Db->GetHeatConductivity(Temp1, Name1);
    HotFluid->Properties.Viscosity = Db->GetViscosity(Temp1, Name1);

    float Temp2 = ColdFluid->Properties.InitialTemperature;
    QString Name2 = ColdFluid->Properties.Name;
    ColdFluid->Properties.Density = Db->GetDensity(Temp2, Name2);
    ColdFluid->Properties.HeatCapacity = Db->GetHeatCapacity(Temp2, Name2);
    ColdFluid->Properties.HeatConductivity = Db->GetHeatConductivity(Temp2, Name2);
    ColdFluid->Properties.Viscosity = Db->GetViscosity(Temp2, Name2);
}

DesignParameters* GivenWidget::getDesignDataClass()
{
    return DesignDataClass;
}

