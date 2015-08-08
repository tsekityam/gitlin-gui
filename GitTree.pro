#-------------------------------------------------
#
# Project created by QtCreator 2015-08-08T04:11:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GitTree
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES +=

unix: CONFIG += link_pkgconfig
unix: CONFIG += appmenu-qt5
