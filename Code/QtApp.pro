CONFIG += qt
TEMPLATE = app
TARGET = myCommunity

QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

unix:!macx {
    LIBS += -lGL
    LIBS += -L/usr/lib -L/usr/lib -lmysqlcppconn
    INCLUDEPATH += -I/usr/include -I/usr/local/include -I/usr/local/include/cppconn
}

macx: {
    LIBS += -framework OpenGL -L/usr/local/opt/mysql-connector-c++/lib -lmysqlcppconn
    INCLUDEPATH += /usr/local/opt/mysql-connector-c++/lib
    INCLUDEPATH += /usr/local/opt/mysql-connector-c++/include/cppconn /usr/local/opt/boost/include /usr/local/opt/mysql-connector-c++/include
}

#windows: {
    #LIBS += C:\Program Files\MySQL\Connector C++ 1.1\lib\opt -lmysqlcppconn.lib
    #INCLUDEPATH += C:\Program Files\MySQL\Connector C++ 1.1\include
#}

SOURCES += \
    main.cpp \
    src/controller.cpp \
    src/room.cpp \
    src/event.cpp \
    src/resident.cpp \
    src/taskexpert.cpp \
    src/ResidentExpert.cpp \
    src/RoomExpert.cpp \
    src/EventExpert.cpp \
    src/Task.cpp \
    src/concretetask.cpp \
    src/shoppingitem.cpp \
    src/shoppingexpert.cpp \
    userInterface/src/GuiController.cpp \
    userInterface/src/HomePage.cpp \
    userInterface/src/SetUpRooms.cpp \
    userInterface/src/SetUpUsers.cpp \
    userInterface/src/SignIn.cpp \
    userInterface/src/SignUp.cpp \
    userInterface/src/StartPage.cpp \
    userInterface/src/RoomListItem.cpp \
    userInterface/src/cleaningpage.cpp \
    userInterface/src/SetUpTasks.cpp \
    userInterface/src/TaskListItem.cpp \
    userInterface/src/eventlistitem.cpp \
    userInterface/src/UserListItem.cpp \
    userInterface/src/SetUpEvents.cpp \
    userInterface/src/SetUpConfiguration.cpp \
    userInterface/src/shoppinglistitem.cpp \
    userInterface/src/changepwpage.cpp \
    userInterface/src/setupshoppinglist.cpp \
    Database/src/DatabaseConfig.cpp \
    Database/src/communitydata.cpp \

HEADERS += \
    lib/controller.h \
    lib/resident.h \
    lib/room.h \
    lib/event.h \
    lib/taskexpert.h \
    lib/ResidentExpert.h \
    lib/RoomExpert.h \
    lib/EventExpert.h \
    lib/Task.h \
    lib/concretetask.h \
    lib/shoppingitem.h \
    lib/shoppingexpert.h \
    userInterface/lib/GuiController.h \
    userInterface/lib/HomePage.h \
    userInterface/lib/SetUpRooms.h \
    userInterface/lib/SetUpUsers.h \
    userInterface/lib/SignIn.h \
    userInterface/lib/SignUp.h \
    userInterface/lib/StartPage.h \
    userInterface/lib/RoomListItem.h \
    userInterface/lib/cleaningpage.h \
    userInterface/lib/SetUpTasks.h \
    userInterface/lib/TaskListItem.h \
    userInterface/lib/eventlistitem.h \
    userInterface/lib/UserListItem.h \
    userInterface/lib/SetUpEvents.h \
    userInterface/lib/SetUpConfiguration.h \
    userInterface/lib/changepwpage.h \
    userInterface/lib/shoppinglistitem.h \
    userInterface/lib/setupshoppinglist.h \
    Database/lib/DatabaseConfig.h \
    Database/lib/communitydata.h \

RESOURCES = \
    media/application.qrc \
    media/avatar.qrc \

DISTFILES += \
    media/signUp.png \

test {
    message(Test bulid)

    QT += testlib
    TARGET = myCommunity-test
    SOURCES -= main.cpp

    HEADERS += \
        test/lib/TestDatabaseDeleter.h \
        test/lib/TestRoom.h \
        test/lib/TestResident.h \
        test/lib/TestRoomExpert.h \
        test/lib/TestResidentExpert.h \
        test/lib/TestTask.h \

    SOURCES += \
        test/src/TestDatabaseDeleter.cpp \
        test/main.cpp \
        test/src/TestRoom.cpp \
        test/src/TestResident.cpp \
        test/src/TestRoomExpert.cpp \
        test/src/TestResidentExpert.cpp \
        test/src/TestTask.cpp \
}

