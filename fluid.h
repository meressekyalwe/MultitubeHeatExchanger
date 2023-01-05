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
#include "parsertext.h"

class Fluid : public QGroupBox
{
    Q_OBJECT

public:

    Fluid();

private slots:

    void setFlow(float value);

    void setInitialTemperature(int value);

    //void set

    Fluid* getFluid();

    FluidPhysicalProperties* getFluidPhysicalProperties();

private:

    FluidPhysicalProperties* Properties;
    QComboBox* SelectComponent;
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

    ParserText* Parser;
};

#endif // FLUID_H
