#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

#include "database.h"


int main(int argc, char *argv[])
{
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);

    DataBase db;
    db.GetHeatCapacity(50.f, QString("Этанол"));

    //MainWindow W;
    //W.show();

    return a.exec();
}
