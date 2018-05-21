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
    src/roomexpert.cpp \
    src/event.cpp \
    src/eventexpert.cpp \
    src/resident.cpp \
    src/residentexpert.cpp \
    userInterface/src/GuiController.cpp \
    userInterface/src/HomePage.cpp \
    userInterface/src/SetUpRooms.cpp \
    userInterface/src/SetUpUsers.cpp \
    userInterface/src/SignIn.cpp \
    userInterface/src/SignUp.cpp \
    userInterface/src/StartPage.cpp \
    userInterface/src/UserList.cpp \
    userInterface/src/RoomListItem.cpp \
    Database/src/communitydata.cpp \

HEADERS += \
    lib/controller.h \
    lib/resident.h \
    lib/residentexpert.h \
    lib/room.h \
    lib/roomexpert.h \
    lib/event.h \
    lib/eventexpert.h \
    lib/wg.h \
    userInterface/lib/GuiController.h \
    userInterface/lib/HomePage.h \
    userInterface/lib/SetUpRooms.h \
    userInterface/lib/SetUpUsers.h \
    userInterface/lib/SignIn.h \
    userInterface/lib/SignUp.h \
    userInterface/lib/StartPage.h \
    userInterface/lib/UserList.h \
    userInterface/lib/RoomListItem.h \
    Database/lib/communitydata.h \

RESOURCES = \
    media/application.qrc \
    media/avatar.qrc

DISTFILES += \
    media/signUp.png

test {
    message(Test build)

    QT += testlib
    TARGET = myCommunity-test
    SOURCES -= main.cpp

    HEADERS += \
        test/lib/TestRoom.h \

    SOURCES += \
        test/main.cpp \
        test/src/TestRoom.cpp \
}

