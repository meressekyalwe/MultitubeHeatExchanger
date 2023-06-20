#include "designparameters.h"

DesignParameters::DesignParameters(DataBase& db)
{
    setTitle(tr("Конструктивные параметры аппарата"));

    HBoxLayoutMaterial = new QHBoxLayout;
    DescriptionMaterial = new QLabel(tr("Материал аппарата "));
    SelectMaterial = new QComboBox;
    HBoxLayoutMaterial->addWidget(DescriptionMaterial, 60);
    HBoxLayoutMaterial->addWidget(SelectMaterial, 40);

    HBoxLayoutLength = new QHBoxLayout;
    DescriptionLength = new QLabel(tr("Длина \nаппарата, м "));
    SliderLength = new QSlider(Qt::Horizontal);
    LengthValue = new QDoubleSpinBox;
    HBoxLayoutLength->addWidget(DescriptionLength, 30);
    HBoxLayoutLength->addWidget(SliderLength, 40);
    HBoxLayoutLength->addWidget(LengthValue, 30);
    LengthValue->setAlignment(Qt::AlignRight);
    SliderLength->setRange(20, 120);
    SliderLength->setSingleStep(25);
    LengthValue->setRange(0.5, 3);
    LengthValue->setSingleStep(0.25);
    LengthValue->setValue(0.75);

    // число труб
    HBoxLayoutNumberPipe = new QHBoxLayout;
    DescriptionNumberPipe = new QLabel(tr("Число труб, шт "));
    SliderNumberPipe = new QSlider(Qt::Horizontal);
    ValueNumberPipe = new QSpinBox;
    HBoxLayoutNumberPipe->addWidget(DescriptionNumberPipe, 30);
    HBoxLayoutNumberPipe->addWidget(SliderNumberPipe, 40);
    HBoxLayoutNumberPipe->addWidget(ValueNumberPipe, 30);
    ValueNumberPipe->setAlignment(Qt::AlignRight);
    SliderNumberPipe->setRange(20, 200);
    ValueNumberPipe->setRange(2, 20);

    // число ходов
    HBoxLayoutNumberPasses = new QHBoxLayout;
    DescriptionNumberPasses = new QLabel(tr("Число ходов, n "));
    SliderNumberPasses = new QSlider(Qt::Horizontal);
    ValueNumberPasses = new QSpinBox;
    HBoxLayoutNumberPasses->addWidget(DescriptionNumberPasses, 30);
    HBoxLayoutNumberPasses->addWidget(SliderNumberPasses, 40);
    HBoxLayoutNumberPasses->addWidget(ValueNumberPasses, 30);
    ValueNumberPasses->setAlignment(Qt::AlignRight);
    SliderNumberPasses->setRange(10, 40);
    ValueNumberPasses->setRange(1, 4);
    ValueNumberPasses->setValue(1);

    HBoxLayoutDiameter = new QHBoxLayout;
    DescriptionDiameter = new QLabel(tr("Внутр. диаметр корпуса, м "));
    DiameterValue = new QLineEdit("0.6");
    HBoxLayoutDiameter->addWidget(DescriptionDiameter, 70);
    HBoxLayoutDiameter->addWidget(DiameterValue, 30);
    DiameterValue->setValidator(Validator);
    DiameterValue->setAlignment(Qt::AlignRight);

    HBoxLayoutTubeOuterDiameter = new QHBoxLayout;
    DescriptionTubeOuterDiameter = new QLabel(tr("Наружный диаметр труб, м "));
    TubeOuterDiameterValue = new QLineEdit("0.02");
    HBoxLayoutTubeOuterDiameter->addWidget(DescriptionTubeOuterDiameter, 70);
    HBoxLayoutTubeOuterDiameter->addWidget(TubeOuterDiameterValue, 30);
    TubeOuterDiameterValue->setValidator(Validator);
    TubeOuterDiameterValue->setAlignment(Qt::AlignRight);

    HBoxLayoutWallThickness = new QHBoxLayout;
    DescriptionWallThickness = new QLabel(tr("Толщина стенки труб, м "));
    WallThicknessValue = new QLineEdit("0.002");
    HBoxLayoutWallThickness->addWidget(DescriptionWallThickness, 70);
    HBoxLayoutWallThickness->addWidget(WallThicknessValue, 30);
    WallThicknessValue->setValidator(Validator);
    WallThicknessValue->setAlignment(Qt::AlignRight);

    // время
    HBoxLayoutTime = new QHBoxLayout;
    DescriptionTime = new QLabel(tr("Время, с "));
    TimeValue = new QLineEdit("900");
    TimeValue->setAlignment(Qt::AlignRight);
    TimeValue->setValidator(Validator);
    HBoxLayoutTime->addWidget(DescriptionTime, 70);
    HBoxLayoutTime->addWidget(TimeValue, 30);

    VBoxLayout = new QVBoxLayout;
    VBoxLayout->addLayout(HBoxLayoutMaterial);
    VBoxLayout->addLayout(HBoxLayoutLength);
    VBoxLayout->addLayout(HBoxLayoutNumberPipe);
    VBoxLayout->addLayout(HBoxLayoutNumberPasses);
    VBoxLayout->addLayout(HBoxLayoutDiameter);
    VBoxLayout->addLayout(HBoxLayoutTubeOuterDiameter);
    VBoxLayout->addLayout(HBoxLayoutWallThickness);
    VBoxLayout->addLayout(HBoxLayoutTime);

    // длинна аппарата
    QObject::connect(SliderLength, &QSlider::valueChanged,
    [=](int value){LengthValue->setValue(static_cast<double>(value) / 40);});
    QObject::connect(LengthValue, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
    [=](float value){SliderLength->setValue(value * 40);});

    // число труб
    QObject::connect(SliderNumberPipe, &QSlider::valueChanged,
    [=](int value){ValueNumberPipe->setValue(value / 10);});
    QObject::connect(ValueNumberPipe, qOverload<int>(&QSpinBox::valueChanged),
    [=](int value){SliderNumberPipe->setValue(value * 10);});

    // число ходов
    QObject::connect(SliderNumberPasses, &QSlider::valueChanged,
    [=](int value){ValueNumberPasses->setValue(value / 10);});
    QObject::connect(ValueNumberPasses, qOverload<int>(&QSpinBox::valueChanged),
    [=](int value){SliderNumberPasses->setValue(value * 10);});

    setLayout(VBoxLayout);

    db.GetListOfAllMaterials(SelectMaterial);
}




