#ifndef FLUID_H
#define FLUID_H

#include <QGroupBox>
#include <QObject>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDoubleSpinBox>
#include <QComboBox>

#include "Types.h"

class Fluid : public QGroupBox
{
    Q_OBJECT

public:

    bool Hot = false;

    Fluid();

    QComboBox* SelectComponent;

    void setFlow();

    void setInitialTemperature();

    void selectComponent();

    float Surface = 0.f;

    Fluid* getFluid();

    FluidPhysicalProperties getFluidPhysicalProperties();


    FluidPhysicalProperties Properties;
    QLabel* NameComponent;
    QHBoxLayout* HBoxLayoutComponent;

    QSlider* SliderFlow;
    QLabel* DescriptionFlow;
    QDoubleSpinBox* FlowValue;
    QHBoxLayout* HBoxLayoutFlow;

    QSlider* SliderTemperature;
    QLabel* DescriptionTemperature;
    QSpinBox* TemperatureValue;
    QHBoxLayout* HBoxLayoutTemperature;

    QVBoxLayout* VBoxLayout;
};

#endif // FLUID_H
