#-------------------------------------------------
#
# Project created by QtCreator 2017-03-22T20:07:40
#
#-------------------------------------------------

QT       += core gui printsupport opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FreeVibrationSDOF
TEMPLATE = app

LIBS += -lm

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui
