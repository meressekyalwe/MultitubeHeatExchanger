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
#include "database.h"

class Fluid : public QGroupBox
{
    Q_OBJECT

public:

    Fluid(DataBase& db);

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
};

#endif // FLUID_H
