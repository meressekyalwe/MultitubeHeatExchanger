#include "givenwidget.h"

GivenWidget::GivenWidget()
{
    setTitle(tr("Исходные данные "));

    HotWater = new Fluid;
    ColdWater = new Fluid;
    DesignDataClass = new DesignParameters;

    HotWater->setTitle(tr("Горячий теплоноситель "));
    ColdWater->setTitle(tr("Холодный теплоноситель "));
    DesignDataClass->setTitle(tr("Конструктивные параметры аппарата "));

    VBoxLayout = new QVBoxLayout;
    VBoxLayout->addWidget(HotWater, 2);
    VBoxLayout->addWidget(ColdWater, 2);
    VBoxLayout->addWidget(DesignDataClass, 6);

    setLayout(VBoxLayout);
}

Fluid* GivenWidget::getHotWater()
{
    return HotWater;
}

Fluid* GivenWidget::getColdWater()
{
    return ColdWater;
}

DesignParameters *GivenWidget::getDesignDataClass()
{
    return DesignDataClass;
}
