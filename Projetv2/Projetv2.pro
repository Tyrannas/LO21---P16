#-------------------------------------------------
#
# Project created by QtCreator 2016-06-07T14:34:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projetv2
TEMPLATE = app


SOURCES += main.cpp\
    ComputerException.cpp \
    Controleur.cpp \
    Litterale.cpp \
    LitteraleManager.cpp \
    Pile.cpp \
    Service.cpp \
    Calculatrice.cpp

HEADERS  += \
    ComputerException.h \
    Controleur.h \
    HashMap.h \
    Litterale.h \
    LitteraleManager.h \
    Pile.h \
    Service.h \
    Calculatrice.h

FORMS    += mainwindow.ui \
    calculatrice.ui
