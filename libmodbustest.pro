#-------------------------------------------------
#
# Project created by QtCreator 2018-03-20T13:21:35
#
#-------------------------------------------------

QT       += core gui

TARGET = libmodbustest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    modbus/modbus-version.h \
    modbus/modbus-tcp.h \
    modbus/modbus-rtu.h \
    modbus/modbus.h

FORMS    += mainwindow.ui
LIBS += -L/opt/libmodbus/instal/lib -lmodbus
