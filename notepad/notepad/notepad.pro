#-------------------------------------------------
#
# Project created by QtCreator 2022-05-10T16:49:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = notepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    subtext.cpp

HEADERS  += mainwindow.h \
    subtext.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
