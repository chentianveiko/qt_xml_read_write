#-------------------------------------------------
#
# Project created by QtCreator 2017-05-14T22:20:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QXmlStreamReader_demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configXmlReadWrite/configxmlreadwrite.cpp

HEADERS  += mainwindow.h \
    configXmlReadWrite/configxmlreadwrite.h

FORMS    += mainwindow.ui
