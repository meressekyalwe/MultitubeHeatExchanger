QT += core gui
QT += sql
QT += uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    designcalculation.cpp \
    designparameters.cpp \
    fluid.cpp \
    givenwidget.cpp \
    heattransfercoefficient.cpp \
    heattransfersurface.cpp \
    main.cpp \
    mainwindow.cpp \
    nusselt.cpp \
    results.cpp \
    toolbar.cpp \

HEADERS += \
    Types.h \
    database.h \
    designcalculation.h \
    designparameters.h \
    fluid.h \
    givenwidget.h \
    heattransfercoefficient.h \
    heattransfersurface.h \
    mainwindow.h \
    nusselt.h \
    results.h \
    toolbar.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES += Ressources/thermal_conductivity.txt
