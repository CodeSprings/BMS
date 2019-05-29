#-------------------------------------------------
#
# Project created by QtCreator 2017-08-12T11:36:15
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

RC_FILE = icon.rc

TARGET = Battery_Monitoring_System
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        main_interface.cpp \
    inverter_activepower_set.cpp \
    inverter_controlmode.cpp \
    inverter_current_set.cpp \
    inverter_switch.cpp \
    inverter_voltage_set.cpp \
    jqchecksum.cpp \
    xmlwriter.cpp \
    login.cpp \
    stove1_temperature_set.cpp \
    stove2_temperature_set.cpp \
    stove3_temperature_set.cpp \
    stove4_temperature_set.cpp \
    qcustomplot.cpp \
    parameter_range.cpp

HEADERS += \
        main_interface.h \
    inverter_activepower_set.h \
    inverter_controlmode.h \
    inverter_current_set.h \
    inverter_switch.h \
    inverter_voltage_set.h \
    jqchecksum.h \
    xmlwriter.h \
    login.h \
    stove1_temperature_set.h \
    stove2_temperature_set.h \
    stove3_temperature_set.h \
    stove4_temperature_set.h \
    qcustomplot.h \
    parameter_range.h \
    ECanVci.h

FORMS += \
        main_interface.ui \
    inverter_activepower_set.ui \
    inverter_controlmode.ui \
    inverter_current_set.ui \
    inverter_switch.ui \
    inverter_voltage_set.ui \
    login.ui \
    stove1_temperature_set.ui \
    stove2_temperature_set.ui \
    stove3_temperature_set.ui \
    stove4_temperature_set.ui \
    parameter_range.ui

RESOURCES += \
    myimage.qrc

DISTFILES += \
    ParameterRangeForm.ui.qml \
    ParameterRange.qml

LIBS +=-LC:/Users/15257/Desktop/bms426/BMS/BMS -lECanVci

UI_DIR=./UI

