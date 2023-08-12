#-------------------------------------------------
#
# Project created by QtCreator 2023-03-26T11:03:59
#
#-------------------------------------------------

QT       += core gui sql multimedia concurrent multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CloudMusicPlayer
TEMPLATE = app


SOURCES += main.cpp\
        cloudmusicplayer.cpp \
    loginwidget.cpp \
    userregister.cpp \
    dialogsetting1.cpp \
    cloudjson.cpp \
    kugoujson.cpp

HEADERS  += cloudmusicplayer.h \
    loginwidget.h \
    userregister.h \
    dialogsetting1.h \
    cloudjson.h \
    kugoujson.h

FORMS    += cloudmusicplayer.ui \
    loginwidget.ui \
    dialogsetting1.ui

RESOURCES += \
    img.qrc
