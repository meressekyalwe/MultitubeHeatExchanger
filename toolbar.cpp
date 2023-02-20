#include "toolbar.h"

ToolBar::ToolBar(QWidget *parent)
    : QWidget{parent}
{
    Run = new QPushButton("Расчитать");
    Clear = new QPushButton("Очистить");
    Print = new QPushButton("Печатать");
    Help = new QPushButton("Помочь");

    HBoxLayout = new QHBoxLayout;
    HBoxLayout->addWidget(Run);
    HBoxLayout->addWidget(Clear);
    HBoxLayout->addWidget(Print);
    HBoxLayout->addWidget(Help);

    setLayout(HBoxLayout);
}
