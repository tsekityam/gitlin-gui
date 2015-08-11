#-------------------------------------------------
#
# Project created by QtCreator 2015-08-08T04:11:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GitLin
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    repocontrolwidget.cpp

HEADERS  += mainwindow.h \
    repocontrolwidget.h

FORMS    += mainwindow.ui \
    repocontrolwidget.ui

RESOURCES += \
    res/res.qrc

unix: CONFIG += link_pkgconfig
unix: CONFIG += appmenu-qt5

DISTFILES +=
