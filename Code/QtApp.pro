CONFIG += qt
TEMPLATE = app
TARGET = myCommunity

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    src/controller.cpp \
    src/resident.cpp \
    src/room.cpp \
    userInterface/src/SetUpRooms.cpp \
    userInterface/src/SetUpUsers.cpp \
    userInterface/src/UserList.cpp \
    userInterface/src/SignUp.cpp \
    userInterface/src/SignIn.cpp \
    userInterface/src/StartPage.cpp \
    userInterface/src/GuiController.cpp \
    userInterface/src/HomePage.cpp \
    userInterface/src/RoomListItem.cpp \
    src/roomexpert.cpp \
    src/residentexpert.cpp

HEADERS += \
    lib/controller.h \
    lib/resident.h \
    lib/room.h \
    userInterface/lib/SetUpUsers.h \
    userInterface/lib/SetUpRooms.h \
    userInterface/lib/UserList.h \
    userInterface/lib/SignUp.h \
    userInterface/lib/SignIn.h \
    userInterface/lib/StartPage.h \
    userInterface/lib/GuiController.h \
    userInterface/lib/HomePage.h \
    userInterface/lib/RoomListItem.h \
    lib/roomexpert.h \
    lib/residentexpert.h

RESOURCES =
