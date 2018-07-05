CONFIG += qt
TEMPLATE = app
TARGET = myCommunity

QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

unix:!macx {
    LIBS += -lGL
    LIBS += /usr/lib/x86_64-linux-gnu/libmysqlclient.so
    INCLUDEPATH += /usr/include/mysql
}

macx: {
    LIBS += -framework OpenGL -L/usr/local/opt/mysql/lib -lmysqlclient
    INCLUDEPATH += /usr/local/opt/mysql/include/mysql
}

win32: {
    INCLUDEPATH += 'C:\Program Files\MySQL\MySQL Connector C 6.1\include'
    LIBS += -L'C:\Program Files\MySQL\MySQL Connector C 6.1\lib' -llibmysql
}

SOURCES += \
    main.cpp \
    src/controller.cpp \
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
    userInterface/src/RoomListItem.cpp \
    userInterface/src/cleaningpage.cpp \
    userInterface/src/SetUpTasks.cpp \
    userInterface/src/TaskListItem.cpp \
    userInterface/src/eventlistitem.cpp \
    userInterface/src/UserListItem.cpp \
    userInterface/src/SetUpConfiguration.cpp \
    userInterface/src/shoppinglistitem.cpp \
    userInterface/src/changepwpage.cpp \
    userInterface/src/setupshoppinglist.cpp \
    Database/src/DatabaseConfig.cpp \
    Database/src/communitydata.cpp \
    userInterface/src/LocalHostConfig.cpp \
    userInterface/src/OwnServerConfig.cpp \
    userInterface/src/PopUpWindow.cpp \
    userInterface/src/setupcleaningplan.cpp \
    userInterface/src/eventpage.cpp \
    src/Resident.cpp \
    src/Room.cpp \
    userInterface/src/concretetasklistitem.cpp \
    src/Event.cpp \
    src/exporter.cpp \
    userInterface/src/exportpage.cpp \
    userInterface/src/cleaningpageitem.cpp \
    userInterface/src/MainScreen.cpp \

HEADERS += \
    lib/controller.h \
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
    userInterface/lib/RoomListItem.h \
    userInterface/lib/cleaningpage.h \
    userInterface/lib/SetUpTasks.h \
    userInterface/lib/TaskListItem.h \
    userInterface/lib/eventlistitem.h \
    userInterface/lib/UserListItem.h \
    userInterface/lib/SetUpConfiguration.h \
    userInterface/lib/changepwpage.h \
    userInterface/lib/shoppinglistitem.h \
    userInterface/lib/setupshoppinglist.h \
    Database/lib/DatabaseConfig.h \
    Database/lib/communitydata.h \
    userInterface/lib/LocalHostConfig.h \
    userInterface/lib/OwnServerConfig.h \
    userInterface/lib/PopUpWindow.h \
    userInterface/lib/setupcleaningplan.h \
    userInterface/lib/eventpage.h \
    lib/Resident.h \
    lib/Room.h \
    userInterface/lib/concretetasklistitem.h \
    lib/Event.h \
    lib/exporter.h \
    userInterface/lib/exportpage.h \
    userInterface/lib/cleaningpageitem.h \
    userInterface/lib/MainScreen.h \

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
        test/lib/TestTask.h \
        test/lib/TestRoomExpert.h \
        test/lib/TestResidentExpert.h \
        test/lib/TestEvent.h \
        test/lib/TestConcreteTask.h \
        test/lib/TestEventExpert.h \
        test/lib/TestShoppingExpert.h \
        test/lib/TestShoppingItem.h \
        test/lib/TestTaskExpert.h \
        test/lib/TestController.h \

    SOURCES += \
        test/src/TestDatabaseDeleter.cpp \
        test/main.cpp \
        test/src/TestRoom.cpp \
        test/src/TestResident.cpp \
        test/src/TestTask.cpp \
        test/src/TestRoomExpert.cpp \
        test/src/TestResidentExpert.cpp \
        test/src/TestEvent.cpp \
        test/src/TestConcreteTask.cpp \
        test/src/TestEventExpert.cpp \
        test/src/TestShoppingExpert.cpp \
        test/src/TestShoppingItem.cpp \
        test/src/TestTaskExpert.cpp \
        test/src/TestController.cpp \

}

