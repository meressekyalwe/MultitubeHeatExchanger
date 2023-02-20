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
    Label->setAlignment(Qt::AlignAbsolute | Qt::AlignAbsolute);
    Label->setMargin(25);

    Calcul = new Calculator;

    QObject::connect(pToolBar->Run, &QPushButton::clicked,
    [=]()
    {
        Given->getHotWater()->setInitialTemperature(); Given->getHotWater()->setFlow(); Given->getHotWater()->selectComponent();
        Given->getColdWater()->setInitialTemperature(); Given->getColdWater()->setFlow(); Given->getColdWater()->selectComponent();
        Given->DesignDataClass->setData();
        Calculate();
        setTextLabel();
    });

    QObject::connect(pToolBar->Clear, &QPushButton::clicked, [=](){Label->clear();});

    setFont(QFont("times", 10));
    Label->setFont(QFont("arial", 10));
    setMinimumSize(QSize(1600, 900));
}

void MainWindow::CalculateFluidPhysicalProperties()
{
    Given->GetFromDatabase();
}

void MainWindow::DesignCalculation()
{

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
    QString text = ("Исследование теплообмена в многотрубчатом кожухотрубном теплообменнике \n\nI. Физические свойства теплоносители при начальной температуре\n\n");

    QString text1 = ("1. Горячий теплоноситель : " + Given->HotFluid->Properties.Name);
    text1 += ("\nНачальная температура " + QString::number(Given->HotFluid->Properties.InitialTemperature) + " °С");
    text1 += ("\nПлотность = " + QString::number(Given->HotFluid->Properties.Density) + " кг/м³");
    text1 += ("\nВязкость = " + QString::number(Given->HotFluid->Properties.Viscosity) + " мПа·с");
    text1 += ("\nТеплоемкость = " + QString::number(Given->HotFluid->Properties.HeatCapacity) + " кДж/кг·К");
    text1 += ("\nКоэффициент теплопроводность = " + QString::number(Given->HotFluid->Properties.HeatConductivity) + " Вт/м·К");

    QString text2 = ("\n\n2. Холодный теплоноситель : " + Given->ColdFluid->Properties.Name);
    text2 += ("\nНачальная температура " + QString::number(Given->ColdFluid->Properties.InitialTemperature) + " °С");
    text2 += ("\nПлотность = " + QString::number(Given->ColdFluid->Properties.Density) + " кг/м³");
    text2 += ("\nВязкость = " + QString::number(Given->ColdFluid->Properties.Viscosity) + " мПа·с");
    text2 += ("\nТеплоемкость = " + QString::number(Given->ColdFluid->Properties.HeatCapacity) + " кДж/кг·К");
    text2 += ("\nКоэффициент теплопроводность = " + QString::number(Given->ColdFluid->Properties.HeatConductivity) + " Вт/м·К");

    QString text3 = ("\n\nII. Конструктивные параметры аппарата\n");
    text3 += "\nМатериал трубы : " + Given->DesignDataClass->Material.Name;
    text3 += "\nДлина аппарата : " + QString::number(Given->DesignDataClass->Data.Length) + " м";
    text3 += "\nЧисло труб : " + QString::number(Given->DesignDataClass->Data.NumberOfTube);
    text3 += "\nЧисло ходов : " + QString::number(Given->DesignDataClass->Data.NumberOfPasses);
    text3 += "\nВнутреный диаметр корпуса : " + QString::number(Given->DesignDataClass->Data.ShellDiameter) + " м";
    text3 += "\nНаружный диметр труб : " + QString::number(Given->DesignDataClass->Data.TubeOuterDiameter) + " м";
    text3 += "\nТольшина стенки труб : " + QString::number(Given->DesignDataClass->Data.WallThickness) + " м";
    text3 += "\nВремя : " + QString::number(Given->DesignDataClass->Data.Time) + " с";
    text3 += "\nТеплопроводности материала : " + QString::number(Given->DesignDataClass->Material.HeatConductivity);

    text += (text1 + text2 + text3);
    Label->setText(text);
}

MainWindow::~MainWindow()
{

}

