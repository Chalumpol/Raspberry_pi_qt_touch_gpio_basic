#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T13:31:02
#
#-------------------------------------------------

QT       += core gui 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Touch
target.path = /home/pi
INSTALLS = target
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

#LIBS += -L/usr/local/lib -lwiringPi -lwiringPiDev

#INCLUDEPATH += /usr/local/include
