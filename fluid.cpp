
#include "fluid.h"

Fluid::Fluid()
{
    SelectComponent = new QComboBox;
    NameComponent = new QLabel(tr("Выбрать компонета"));
    HBoxLayoutComponent = new QHBoxLayout;
    HBoxLayoutComponent->addWidget(NameComponent, 60);
    HBoxLayoutComponent->addWidget(SelectComponent, 40);


    SliderFlow = new QSlider(Qt::Horizontal);
    DescriptionFlow = new QLabel(tr("Расход, кг/с "));
    FlowValue = new QDoubleSpinBox;
    HBoxLayoutFlow = new QHBoxLayout;
    HBoxLayoutTemperature = new QHBoxLayout;
    VBoxLayout = new QVBoxLayout;
    FlowValue->setAlignment(Qt::AlignRight);
    SliderFlow->setRange(10, 1000);
    SliderFlow->setSingleStep(1);
    FlowValue->setRange(0.01, 1);
    FlowValue->setSingleStep(0.01);

    HBoxLayoutFlow->addWidget(DescriptionFlow, 30);
    HBoxLayoutFlow->addWidget(SliderFlow, 40);
    HBoxLayoutFlow->addWidget(FlowValue, 30);

    SliderTemperature = new QSlider(Qt::Horizontal);
    DescriptionTemperature = new QLabel(tr("Начальная \nтемп., °С "));
    TemperatureValue = new QSpinBox;
    HBoxLayoutTemperature = new QHBoxLayout;
    TemperatureValue->setAlignment(Qt::AlignRight);
    SliderTemperature->setRange(0, 100);
    SliderTemperature->setSingleStep(1);
    SliderTemperature->setPageStep(1);
    TemperatureValue->setRange(0, 100);
    TemperatureValue->setSingleStep(1);

    // parse density
    Parser->Density(SelectComponent);



    HBoxLayoutTemperature->addWidget(DescriptionTemperature, 30);
    HBoxLayoutTemperature->addWidget(SliderTemperature, 40);
    HBoxLayoutTemperature->addWidget(TemperatureValue, 30);

    VBoxLayout->addLayout(HBoxLayoutComponent, 20);
    VBoxLayout->addLayout(HBoxLayoutFlow, 40);
    VBoxLayout->addLayout(HBoxLayoutTemperature, 40);
    setLayout(VBoxLayout);

    // расход
    QObject::connect(SliderFlow, &QSlider::valueChanged, [=](int value){FlowValue->setValue(static_cast<double>(value) / 1000);});
    QObject::connect(FlowValue, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
    [=](float value){SliderFlow->setValue(static_cast<double>(value * 1000)); setFlow(value);});

    // температура
    QObject::connect(SliderTemperature, &QSlider::valueChanged, TemperatureValue, &QSpinBox::setValue);
    QObject::connect(TemperatureValue, qOverload<int>(&QSpinBox::valueChanged),
    [=](int value){SliderTemperature->setValue(value); setInitialTemperature(value);});

}


void Fluid::setFlow(float value)
{
    Properties->Flow = value;
}

void Fluid::setInitialTemperature(int value)
{
    Properties->InitialTemperature = value;
}

Fluid* Fluid::getFluid()
{
    return this;
}

FluidPhysicalProperties* Fluid::getFluidPhysicalProperties()
{
    return Properties;
}
