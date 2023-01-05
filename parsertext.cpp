
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QCoreApplication>

#include "parsertext.h"

ParserText::ParserText(QObject *parent)
    : QObject{parent}
{

}

void ParserText::ThermalConductivity(QComboBox* ComboBox)
{
    QFile file(QCoreApplication::applicationDirPath() + "/Ressources/thermal_conductivity.txt");

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);

           while (!stream.atEnd())
            {
                 QString name;
                 float value;

                 stream >> name;
                 stream >> value;

                 ComboBox->addItem(name, value);
            }
            file.close();
    }
}

void ParserText::Density(QComboBox *ComboBox)
{
    QFile file(QCoreApplication::applicationDirPath() + "/Ressources/components.txt");

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);

           while (!stream.atEnd())
            {
                 QString name;

                 stream >> name;

                 ComboBox->addItem(name);
            }

            file.close();
    }
}
