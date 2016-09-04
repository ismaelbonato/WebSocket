#-------------------------------------------------
#
# Project created by QtCreator 2016-09-03T19:39:05
#
#-------------------------------------------------

QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebSocket
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    webserver.cpp

HEADERS  += mainwindow.h \
    webserver.h

FORMS    += mainwindow.ui

DISTFILES += \
    index.html \
    socketserver.js
