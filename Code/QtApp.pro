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
    src/residentexpert.cpp \
    src/communitydata.cpp \
    src/event.cpp \
    src/eventexpert.cpp

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
    lib/residentexpert.h \
    lib/communitydata.h \
    lib/event.h \
    lib/eventexpert.h

RESOURCES = \
    media/application.qrc
