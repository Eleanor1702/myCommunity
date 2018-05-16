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
<<<<<<< HEAD \
    Database/src/communitydata.cpp \
    src/controller.cpp \
    src/event.cpp \
    src/eventexpert.cpp \
    src/resident.cpp \
    src/residentexpert.cpp \
    src/room.cpp \
    src/roomexpert.cpp \
    userInterface/src/GuiController.cpp \
    userInterface/src/HomePage.cpp \
    userInterface/src/RoomListItem.cpp \
    userInterface/src/SetUpRooms.cpp \
    userInterface/src/SetUpUsers.cpp \
    userInterface/src/SignIn.cpp \
    userInterface/src/SignUp.cpp \
    userInterface/src/StartPage.cpp \
    userInterface/src/UserList.cpp \
    main.cpp
    src/roomexpert.cpp \
    src/residentexpert.cpp \
=======
>>>>>>> d09e8dc0fefd21e54d1eaaf140e89abda6a95c81
    src/resident.cpp \
    src/event.cpp \
    src/eventexpert.cpp \
    userInterface/src/SetUpRooms.cpp \
    userInterface/src/SetUpUsers.cpp \
    userInterface/src/UserList.cpp \
    userInterface/src/SignUp.cpp \
    userInterface/src/SignIn.cpp \
    userInterface/src/StartPage.cpp \
    userInterface/src/HomePage.cpp \
    userInterface/src/RoomListItem.cpp \
    userInterface/src/GuiController.cpp \
    Database/src/communitydata.cpp

HEADERS += \
    lib/controller.h \
    lib/resident.h \
    lib/room.h \
    lib/roomexpert.h \
    lib/residentexpert.h \
<<<<<<< HEAD \
    Database/lib/communitydata.h \
    lib/controller.h \
    lib/event.h \
    lib/eventexpert.h \
    lib/resident.h \
    lib/residentexpert.h \
    lib/room.h \
    lib/roomexpert.h \
    lib/wg.h \
    userInterface/lib/GuiController.h \
    userInterface/lib/HomePage.h \
    userInterface/lib/RoomListItem.h \
    userInterface/lib/SetUpRooms.h \
    userInterface/lib/SetUpUsers.h \
    userInterface/lib/SignIn.h \
    userInterface/lib/SignUp.h \
    userInterface/lib/StartPage.h \
    userInterface/lib/UserList.h
    lib/event.h \
    lib/eventexpert.h \
=======
>>>>>>> d09e8dc0fefd21e54d1eaaf140e89abda6a95c81
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
<<<<<<< HEAD
=======
    lib/event.h \
    lib/eventexpert.h \
    lib/wg.h \
>>>>>>> d09e8dc0fefd21e54d1eaaf140e89abda6a95c81
    Database/lib/communitydata.h

RESOURCES = \
    media/application.qrc \
    media/avatar.qrc

DISTFILES += \
    media/signUp.png
