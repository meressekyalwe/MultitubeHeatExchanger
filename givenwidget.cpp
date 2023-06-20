#include "givenwidget.h"

GivenWidget::GivenWidget(DataBase& db)
{
    setTitle(tr("Исходные данные "));

    HotFluid = new Fluid(db);
    ColdFluid = new Fluid(db);
    DesignDataClass = new DesignParameters(db);

    HotFluid->setTitle(tr("Горячий теплоноситель "));
    ColdFluid->setTitle(tr("Холодный теплоноситель "));
    DesignDataClass->setTitle(tr("Конструктивные параметры аппарата "));

    VBoxLayout = new QVBoxLayout;
    VBoxLayout->addWidget(HotFluid, 3);
    VBoxLayout->addWidget(ColdFluid, 3);
    VBoxLayout->addWidget(DesignDataClass, 6);

    setLayout(VBoxLayout);

    setAlignment(Qt::AnchorVerticalCenter | Qt::AnchorHorizontalCenter);

    HotFluid->TemperatureValue->setValue(70);
    HotFluid->FlowValue->setValue(0.07);

    ColdFluid->TemperatureValue->setValue(20);
    ColdFluid->FlowValue->setValue(0.07);
}




