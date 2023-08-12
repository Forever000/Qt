#-------------------------------------------------
#
# Project created by QtCreator 2022-05-05T18:47:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chessgame
TEMPLATE = app


SOURCES += main.cpp\
        chess.cpp \
    chessform.cpp

HEADERS  += chess.h \
    chessform.h

FORMS    += chess.ui \
    chessform.ui
