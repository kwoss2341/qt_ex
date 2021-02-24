QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppWithLibrary
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

LIBS += -L$$PWD/../build-MyUtil-Desktop_Qt_5_12_2_MinGW_32_bit-Debug/debug/ -lMyUtil

INCLUDEPATH += $$PWD/../MyUtil
DEPENDPATH += $$PWD/../MyUtil
