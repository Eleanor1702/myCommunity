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
    userInterface/src/SetUpRooms.cpp \
    userInterface/src/SetUpUsers.cpp \
    userInterface/src/Roomlistitem.cpp \
    userInterface/src/UserList.cpp \
    userInterface/src/SignUp.cpp \
    src/controller.cpp

HEADERS += \
    lib/mainscreen.h \
    lib/bewohner.h \
    lib/raum.h \
    lib/wg.h \
    userInterface/lib/SetUpUsers.h \
    userInterface/lib/SetUpRooms.h \
    userInterface/lib/Roomlistitem.h \
    userInterface/lib/UserList.h \
    userInterface/lib/SignUp.h \
    lib/controller.h \
    userInterface/lib/guicontroller.h

RESOURCES = media/SignUp.png

