CONFIG += qt
TEMPLATE = app
TARGET = myCommunity

QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lGL
LIBS += -L/usr/lib -L/usr/lib -lmysqlcppconn
INCLUDEPATH += -I/usr/include -I/usr/local/include -I/usr/local/include/cppconn

SOURCES += \
    main.cpp \
    src/controller.cpp \
    src/room.cpp \
    src/resident.cpp \
    userInterface/src/SetUpRooms.cpp \
    userInterface/src/SetUpUsers.cpp \
    userInterface/src/UserList.cpp \
    userInterface/src/SignUp.cpp \
    userInterface/src/SignIn.cpp \
    userInterface/src/StartPage.cpp \
    userInterface/src/HomePage.cpp \
    userInterface/src/RoomListItem.cpp \
    userInterface/src/GuiController.cpp \
    src/roomexpert.cpp \
    src/residentexpert.cpp \
    src/event.cpp \
    src/eventexpert.cpp \
    Database/src/communitydata.cpp

HEADERS += \
    lib/controller.h \
    lib/resident.h \
    lib/room.h \
    lib/roomexpert.h \
    lib/residentexpert.h \
    lib/wg.h \
    userInterface/lib/SetUpUsers.h \
    userInterface/lib/SetUpRooms.h \
    userInterface/lib/UserList.h \
    userInterface/lib/SignUp.h \
    userInterface/lib/SignIn.h \
    userInterface/lib/StartPage.h \
    userInterface/lib/GuiController.h \
    userInterface/lib/HomePage.h \
    userInterface/lib/RoomListItem.h \
    lib/event.h \
    lib/eventexpert.h \
    lib/wg.h \
    Database/lib/communitydata.h

RESOURCES = \
    media/application.qrc \
    media/avatar.qrc

DISTFILES += \
    media/signUp.png
