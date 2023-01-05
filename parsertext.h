#ifndef PARSERTEXT_H
#define PARSERTEXT_H

#include <QObject>
#include <QVector>
#include <QComboBox>


class ParserText : public QObject
{
    Q_OBJECT

public:

    explicit ParserText(QObject *parent = nullptr);

    void ThermalConductivity(QComboBox* ComboBox);

    void Density(QComboBox* ComboBox);

signals:


private:

};

#endif // PARSERTEXT_H
