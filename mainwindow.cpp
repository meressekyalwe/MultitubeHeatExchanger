#include "mainwindow.h"
#include <QFontMetrics>
#include <QScrollArea>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    givenWidget = new GivenWidget(db);
    Label = new QLabel;
    pToolBar = new ToolBar;
    VBoxLayout = new QVBoxLayout;
    HBoxLayout = new QHBoxLayout;
    scrollArea = new QScrollArea;

    setLayout(HBoxLayout);

    Label->setStyleSheet("QLabel { background-color : white; color : black; }");
    Label->setAlignment(Qt::AlignAbsolute | Qt::AlignAbsolute);
    Label->setMargin(25);
    Label->setWordWrap(true);

    scrollArea->setWidget(Label);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setWidgetResizable(true);

    QScrollBar* scrollBar = new QScrollBar(Qt::Vertical);
    scrollArea->setVerticalScrollBar(scrollBar);

    // Create a vertical scrollbar
    QScrollBar* verticalScrollBar = new QScrollBar;
    verticalScrollBar->setOrientation(Qt::Vertical);
    verticalScrollBar->setRange(0, scrollArea->widget()->height());

    // Connect the scrollbar valueChanged signal to the scrollArea verticalScrollBar slot
    QObject::connect(verticalScrollBar, &QScrollBar::valueChanged, scrollArea->verticalScrollBar(), &QScrollBar::setValue);

    // Set the vertical scrollbar as the scroll area's verticalScrollBar
    scrollArea->setVerticalScrollBar(verticalScrollBar);

    VBoxLayout->addWidget(pToolBar, 5);
    VBoxLayout->addWidget(scrollArea, 95);

    HBoxLayout->addWidget(givenWidget, 25);
    HBoxLayout->addLayout(VBoxLayout, 75);

    setFont(QFont("arial", 12));
    Label->setFont(QFont("times", 12));
    setMinimumSize(QSize(1600, 900));

    QObject::connect(pToolBar->Run, &QPushButton::clicked,
    [=]()
    {
        rs.setCurrentMaterial(givenWidget);
        rs.setCurrentHotFluid(givenWidget);
        rs.setCurrentColdFluid(givenWidget);
        rs.Calculate(db);
        writeResult();
    });

    QObject::connect(pToolBar->Clear, &QPushButton::clicked,
    [=]()
    {
        Label->clear();
    });
}

void MainWindow::writeResult()
{
    QString text = ("Исследование теплообмена в многотрубчатом кожухотрубном теплообменнике \n\nI. Физические свойства теплоносители при начальной температуре\n\n");

    QString text1 = ("1. Горячий теплоноситель : " + rs.HotFluid.Name);
    text1 += ("\nРасход " + QString::number(rs.HotFluid.Flow) + " кг/с");
    text1 += ("\nНачальная температура " + QString::number(rs.HotFluid.InitialTemperature) + " °С");
    text1 += ("\nПлотность = " + QString::number(rs.HotFluid.Density) + " кг/м³");
    text1 += ("\nВязкость = " + QString::number(rs.HotFluid.Viscosity) + " Па·с");
    text1 += ("\nТеплоемкость = " + QString::number(rs.HotFluid.HeatCapacity) + " Дж/кг·К");
    text1 += ("\nКоэффициент теплопроводность = " + QString::number(rs.HotFluid.HeatConductivity) + " Вт/м·К");

    QString text2 = ("\n\n2. Холодный теплоноситель : " + rs.ColdFluid.Name);
    text2 += ("\nРасход " + QString::number(rs.ColdFluid.Flow) + " кг/с");
    text2 += ("\nНачальная температура " + QString::number(rs.ColdFluid.InitialTemperature) + " °С");
    text2 += ("\nПлотность = " + QString::number(rs.ColdFluid.Density) + " кг/м³");
    text2 += ("\nВязкость = " + QString::number(rs.ColdFluid.Viscosity) + " Па·с");
    text2 += ("\nТеплоемкость = " + QString::number(rs.ColdFluid.HeatCapacity) + " Дж/кг·К");
    text2 += ("\nКоэффициент теплопроводность = " + QString::number(rs.ColdFluid.HeatConductivity) + " Вт/м·К");

    QString text3 = ("\n\nII. Конструктивные параметры аппарата\n");
    text3 += "\nМатериал трубы : " + rs.Material.Name;
    text3 += "\nДлина аппарата : " + QString::number(rs.DesignData.Length) + " м";
    text3 += "\nЧисло труб : " + QString::number(rs.DesignData.NumberOfTube);
    text3 += "\nЧисло ходов : " + QString::number(rs.DesignData.NumberOfPasses);
    text3 += "\nВнутреный диаметр корпуса : " + QString::number(rs.DesignData.ShellDiameter) + " м";
    text3 += "\nНаружный диметр труб : " + QString::number(rs.DesignData.TubeOuterDiameter) + " м";
    text3 += "\nТольшина стенки труб : " + QString::number(rs.DesignData.WallThickness) + " м";
    text3 += "\nВремя : " + QString::number(rs.DesignData.Time) + " с";

    text3 += "\nТеплопроводности материала : " + QString::number(rs.Material.HeatConductivity);
    /*
    text3 += "\nПлошадь поперечного сечения трубного пространства : " + QString::number(rs.S1);
    text3 += "\nВнутреный диаметр труб = " + QString::number(rs.dvn) + " м";
    //text3 += "\nF = " + QString::number(results.F);
    text3 += "\nПлощадь поперечного сечения межтрубного пространства : " + QString::number(rs.S2);
    text3 += "\nЭквивалентный диаметр по межтрубному пространству : " + QString::number(rs.deq2);


    text4 += ("\nКритерия Прандтля:");
    text4 += ("\n Pr1 = " + QString::number(results.Pr1));
    text4 += ("\n Pr2 = " + QString::number(results.Pr2));
    text4 += ("\nСредняя скорость движения теплоносителей:");
    text4 += ("\n W1 = " + QString::number(results.W1));
    text4 += ("\n W2 = " + QString::number(results.W2));
    text4 += ("\nКритерий Рейнольдса:");
    text4 += ("\n Re1 = " + QString::number(results.Re1));
    text4 += ("\n Re2 = " + QString::number(results.Re2));
    text4 += ("\nКритерий Нуссельта:");
    text4 += ("\n Nu1 = " + QString::number(results.Nu1));
    text4 += ("\n Nu2 = " + QString::number(results.Nu2));
    text4 += ("\nКоэффициенты теплоотдачи:");
    text4 += ("\n α1 = " + QString::number(results.alpha1));
    text4 += ("\n α2 = " + QString::number(results.alpha2));
*/
    QString text4 = ("\n\n IV. Резултаты опыта \n");
    text4 += ("\n Температура теплоносители на выходе: = " + QString::number(rs.HotFluid.FinalTemperature) + " °С");
    text4 += ("\n Температура теплоносители на выходе: = " + QString::number(rs.ColdFluid.FinalTemperature) + " °С");

    text += (text1 + text2 + text3 + text4);
    Label->setText(text);
}

MainWindow::~MainWindow()
{

}

