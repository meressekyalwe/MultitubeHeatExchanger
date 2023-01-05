#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    Given = new GivenWidget;
    Label = new QLabel;
    HBoxLayout = new QHBoxLayout;

    HBoxLayout->addWidget(Given, 20);
    HBoxLayout->addWidget(Label, 80);

    setLayout(HBoxLayout);

    Calcul = new Calculator;
}

void MainWindow::CalculateFluidPhysicalProperties()
{
    // горячий теплоноситель
    Calcul->CalculateDensity(Given->getHotWater());
    Calcul->CalculateHeatCapacity(Given->getHotWater());
    Calcul->CalculateViscosity(Given->getHotWater());
    Calcul->CalculateHeatConductivity(Given->getHotWater());

    // холодний теплоноситель
    Calcul->CalculateDensity(Given->getColdWater());
    Calcul->CalculateHeatCapacity(Given->getColdWater());
    Calcul->CalculateViscosity(Given->getColdWater());
    Calcul->CalculateHeatConductivity(Given->getColdWater());
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

MainWindow::~MainWindow()
{

}

