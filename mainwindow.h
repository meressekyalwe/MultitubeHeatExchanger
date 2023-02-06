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
#include "toolbar.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    void CalculateFluidPhysicalProperties();

    void  DesignCalculation();

    void CalculateHeatTransferSurface();

    void CalculateHeatTransferCoefficient();

    void Calculate();

    void setTextLabel();

    ~MainWindow();

private:

    GivenWidget* Given;
    QLabel* Label;
    ToolBar* pToolBar;
    QVBoxLayout* VBoxLayout;
    QHBoxLayout* HBoxLayout;

    Calculator* Calcul;
};
#endif // MAINWINDOW_H
