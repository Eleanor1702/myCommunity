CONFIG += qt
TEMPLATE = app
TARGET = myCommunity

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    src/wg.cpp \
    src/controller.cpp \
    userInterface/src/SetUpRooms.cpp \
    userInterface/src/SetUpUsers.cpp \
    userInterface/src/Roomlistitem.cpp \
    userInterface/src/UserList.cpp \
    userInterface/src/SignUp.cpp \
    userInterface/src/SignIn.cpp \
    userInterface/src/StartPage.cpp \
    userInterface/src/GuiController.cpp \
    src/room.cpp \
    src/resident.cpp

HEADERS += \
    lib/wg.h \
    lib/controller.h \
    userInterface/lib/SetUpUsers.h \
    userInterface/lib/SetUpRooms.h \
    userInterface/lib/Roomlistitem.h \
    userInterface/lib/UserList.h \
    userInterface/lib/SignUp.h \
    userInterface/lib/SignIn.h \
    userInterface/lib/StartPage.h \
    userInterface/lib/GuiController.h \
    lib/room.h \
    lib/resident.h

RESOURCES = media/SignUp.png
