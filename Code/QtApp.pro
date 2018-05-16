CONFIG += qt
TEMPLATE = app
TARGET = myCommunity

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    src/controller.cpp \
    src/room.cpp \
    src/roomexpert.cpp \
    src/residentexpert.cpp \
    src/communitydata.cpp \
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

HEADERS += \
    lib/controller.h \
    lib/resident.h \
    lib/room.h \
    lib/roomexpert.h \
    lib/residentexpert.h \
    lib/communitydata.h \
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


RESOURCES = \
    media/application.qrc \
    media/application.qrc \
    media/avatar.qrc

DISTFILES += \
    media/avatar.png \
    media/signUp.png \
    DatenBank/test.txt

SUBDIRS += \
    QtApp.pro
