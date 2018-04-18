CONFIG += qt
TEMPLATE = app
TARGET = myCommunity

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    src/mainscreen.cpp \
    userInterface/src/startpage.cpp \
    src/bewohner.cpp \
    src/raum.cpp \
    src/wg.cpp

HEADERS += \
    lib/mainscreen.h \
    userInterface/lib/startpage.h \
    lib/bewohner.h \
    lib/raum.h \
    lib/wg.h
