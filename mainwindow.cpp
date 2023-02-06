#include "mainwindow.h"
#include <QFontMetrics>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    Given = new GivenWidget;
    Label = new QLabel;
    pToolBar = new ToolBar;
    VBoxLayout = new QVBoxLayout;
    HBoxLayout = new QHBoxLayout;

    VBoxLayout->addWidget(pToolBar, 5);
    VBoxLayout->addWidget(Label, 95);

    HBoxLayout->addWidget(Given, 25);
    HBoxLayout->addLayout(VBoxLayout, 75);

    setLayout(HBoxLayout);

    Label->setStyleSheet("QLabel { background-color : white; color : black; }");
    Label->setAlignment(Qt::AlignHCenter | Qt::AlignAbsolute);

    Calcul = new Calculator;

    QObject::connect(pToolBar->Run, &QPushButton::clicked,
    [=]()
    {
        Given->getHotWater()->setInitialTemperature(); Given->getHotWater()->setFlow(); Given->getHotWater()->selectComponent();
        Given->getColdWater()->setInitialTemperature(); Given->getColdWater()->setFlow(); Given->getColdWater()->selectComponent();
        Calculate();
        setTextLabel();
    });

    QObject::connect(pToolBar->Clear, &QPushButton::clicked, [=](){Label->clear();});

    setFont(QFont("arial", 10));
    Label->setFont(QFont("arial", 10));
    setMinimumSize(QSize(1600, 1000));
}

void MainWindow::CalculateFluidPhysicalProperties()
{
    Given->GetFromDatabase();
}

void MainWindow::DesignCalculation()
{
    Calcul->Cross_SectionalAreaOfTubeSpace(Given->getDesignDataClass()->getData());
    Calcul->AnnulusCross_SectionalArea(Given->getDesignDataClass()->getData());
    Calcul->EquivalentAnnulusDiameter(Given->getDesignDataClass()->getData());
}

void MainWindow::CalculateHeatTransferSurface()
{

}

void MainWindow::CalculateHeatTransferCoefficient()
{

}

void MainWindow::Calculate()
{
    CalculateFluidPhysicalProperties();
}

void MainWindow::setTextLabel()
{
    QString text = ("\n\n I. Физические свойства теплоносители при начальной температуре\n\n");
    QString text1 = ("1. Горячий теплоноситель : " + Given->HotFluid->Properties.Name);
    text1 += ("\nНачальная температура " + QString::number(Given->HotFluid->Properties.InitialTemperature) + " °С");
    text1 += ("\nПлотность = " + QString::number(Given->HotFluid->Properties.Density) + " кг/м³");
    text1 += ("\nВязкость = " + QString::number(Given->HotFluid->Properties.Viscosity) + " мПа·с");
    text1 += ("\nТеплоемкость = " + QString::number(Given->HotFluid->Properties.HeatCapacity) + " ккал/кг·°С");
    text1 += ("\nКоэффициент теплопроводность = " + QString::number(Given->HotFluid->Properties.HeatConductivity) + " Вт/м·К");

    QString text2 = ("\n\n2. Холодный теплоноситель : " + Given->ColdFluid->Properties.Name);
    text2 += ("\nНачальная температура " + QString::number(Given->ColdFluid->Properties.InitialTemperature) + " °С");
    text2 += ("\nПлотность = " + QString::number(Given->ColdFluid->Properties.Density) + " кг/м³");
    text2 += ("\nВязкость = " + QString::number(Given->ColdFluid->Properties.Viscosity) + " мПа·с");
    text2 += ("\nТеплоемкость = " + QString::number(Given->ColdFluid->Properties.HeatCapacity) + " ккал/кг·°С");
    text2 += ("\nКоэффициент теплопроводность = " + QString::number(Given->ColdFluid->Properties.HeatConductivity) + " Вт/м·К");

    text += (text1 + text2);
    Label->setText(text);
}

MainWindow::~MainWindow()
{

}

