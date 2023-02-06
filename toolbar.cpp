#include "toolbar.h"

ToolBar::ToolBar(QWidget *parent)
    : QWidget{parent}
{
    Run = new QPushButton("Расчитать");
    Clear = new QPushButton("Очистить");

    HBoxLayout = new QHBoxLayout;
    HBoxLayout->addWidget(Run);
    HBoxLayout->addWidget(Clear);

    setLayout(HBoxLayout);
}
