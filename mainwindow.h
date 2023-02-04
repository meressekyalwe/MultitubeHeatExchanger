#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QSlider>
#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

#include "givenwidget.h"
#include "calculator.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    void CalculateFluidPhysicalProperties();

    void  DesignCalculation();

    void CalculateHeatTransferSurface();

    void CalculateHeatTransferCoefficient();

    ~MainWindow();

private:

    GivenWidget* Given;
    QGroupBox* Label;
    QHBoxLayout* HBoxLayout;


    Calculator* Calcul;
};
#endif // MAINWINDOW_H
