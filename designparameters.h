#ifndef DESIGNPARAMETERS_H
#define DESIGNPARAMETERS_H


#include <QObject>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QSlider>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QDoubleSpinBox>

#include "Types.h"
#include "parsertext.h"

class DesignParameters : public QGroupBox
{
    Q_OBJECT

public:

    DesignParameters();

    void setData(float ShellDiameter, float TubeOuterDiameter, float WallThickness, float Time);

    DesignData* getData();

private:

    DesignData* Data;

    // материал аппарата
    QHBoxLayout* HBoxLayoutMaterial;
    QLabel* DescriptionMaterial;
    QComboBox* NameMaterial;

    // длина аппарата
    QHBoxLayout* HBoxLayoutLength;
    QLabel* DescriptionLength;
    QSlider* SliderLength;
    QDoubleSpinBox* LengthValue;

    // число труб
    QHBoxLayout* HBoxLayoutNumberPipe;
    QLabel* DescriptionNumberPipe;
    QSlider* SliderNumberPipe;
    QSpinBox* ValueNumberPipe;

    // число ходов
    QHBoxLayout* HBoxLayoutNumberPasses;
    QLabel* DescriptionNumberPasses;
    QSlider* SliderNumberPasses;
    QSpinBox* ValueNumberPasses;

    // наружный диаметр труб
    QHBoxLayout* HBoxLayoutTubeOuterDiameter;
    QLabel* DescriptionTubeOuterDiameter;
    QLineEdit* TubeOuterDiameterValue;

    // толщина стенки труб
    QHBoxLayout* HBoxLayoutWallThickness;
    QLabel* DescriptionWallThickness;
    QLineEdit* WallThicknessValue;

    // наружный диаметр аппарат
    QHBoxLayout* HBoxLayoutDiameter;
    QLabel* DescriptionDiameter;
    QLineEdit* DiameterValue;

    QVBoxLayout* VBoxLayout;

    // времия
    QHBoxLayout* HBoxLayoutTime;
    QLabel* DescriptionTime;
    QLineEdit* TimeValue;


    QDoubleValidator* Validator = new QDoubleValidator(0.0, 5.0, 6);

    ParserText* Parser;
};

#endif // DESIGNPARAMETERS_H
