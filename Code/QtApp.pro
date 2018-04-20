CONFIG += qt
TEMPLATE = app
TARGET = myCommunity

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    src/mainscreen.cpp \
    src/bewohner.cpp \
    src/raum.cpp \
    src/wg.cpp \
    userInterface/src/SetUpRooms.cpp

HEADERS += \
    lib/mainscreen.h \
    lib/bewohner.h \
    lib/raum.h \
    lib/wg.h \
    userInterface/lib/setUpRooms.h
