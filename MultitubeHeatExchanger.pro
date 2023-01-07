QT  += core gui
QT +=  core

greaterThan(QT_MAJOR_VERSION, 4):

QT += widgets
QT += uitools
QT += sql


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculator.cpp \
    database.cpp \
    designparameters.cpp \
    fluid.cpp \
    givenwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    parsertext.cpp \

HEADERS += \
    Types.h \
    calculator.h \
    database.h \
    designparameters.h \
    fluid.h \
    givenwidget.h \
    mainwindow.h \
    parsertext.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += Ressources/thermal_conductivity.txt
