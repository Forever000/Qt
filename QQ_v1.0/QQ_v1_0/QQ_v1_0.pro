#-------------------------------------------------
#
# Project created by QtCreator 2023-03-17T21:48:39
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQ_v1_0
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    userregister.cpp

HEADERS  += widget.h \
    userregister.h

FORMS    += widget.ui

RESOURCES += \
    img/res.qrc
