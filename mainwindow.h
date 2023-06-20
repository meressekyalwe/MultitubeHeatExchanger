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
#include <QScrollArea>

#include "givenwidget.h"
#include "toolbar.h"
#include "designcalculation.h"
#include "results.h"
#include "database.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    void writeResult();

    ~MainWindow();

private:

    GivenWidget* givenWidget;
    QLabel* Label;
    QScrollArea* scrollArea;
    ToolBar* pToolBar;
    QVBoxLayout* VBoxLayout;
    QHBoxLayout* HBoxLayout;
    DesignCalculation desingCalculator;

    DataBase db;
    Results rs;
};
#endif // MAINWINDOW_H
