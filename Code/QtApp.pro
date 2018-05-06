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
    userInterface/src/SignIn.cpp \
    userInterface/src/StartPage.cpp \
    userInterface/src/GuiController.cpp

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
    userInterface/lib/SignIn.h \
    userInterface/lib/StartPage.h \
    userInterface/lib/GuiController.h
