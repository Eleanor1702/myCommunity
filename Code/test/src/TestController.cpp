#include "../lib/TestController.h"

TestController::TestController(CommunityData *testData, TestDatabaseDeleter *destroyer) {
    this->testData = testData;
    this->destroyer = destroyer;
}

void TestController::testAddRoom() {
    destroyer->cleanRooms();

    Controller* con = Controller::getInstance(testData);
    con->addRoom("Bath", "Bathroom");
    con->addRoom("Living Room", "Garden Living Room");

    std::vector<Room> rooms = testData->getAllRooms();

    QVERIFY(rooms.size() == 2);
    QVERIFY(rooms.at(0).getName() == "Bathroom");
    QVERIFY(rooms.at(0).getArt() == "Bath");
    QVERIFY(rooms.at(1).getName() == "Garden Living Room");
    QVERIFY(rooms.at(1).getArt() == "Living Room");
}

void TestController::testDeleteRoom() {
    destroyer->cleanRooms();

    Controller* con = Controller::getInstance(testData);
    RoomExpert* roomExpert = RoomExpert::getInstance(testData);

    roomExpert->createRoom("Bathroom", "Bath");
    roomExpert->createRoom("Garden Living Room", "Living Room");

    con->deleteRoom("Garden Living Room");
    std::vector<Room> rooms = testData->getAllRooms();

    QVERIFY(rooms.size() == 1);
    QVERIFY(rooms.at(0).getName() == "Bathroom");
    QVERIFY(rooms.at(0).getArt() == "Bath");
}

void TestController::testGetRoomNames() {
    destroyer->cleanRooms();

    Controller* con = Controller::getInstance(testData);
    RoomExpert* roomExpert = RoomExpert::getInstance(testData);

    roomExpert->createRoom("Bathroom", "Bath");
    roomExpert->createRoom("Garden Living Room", "Living Room");

    std::vector<std::string> names = con->getRoomNames();

    QVERIFY(names.size() == 2);
    QVERIFY(names.at(0) == "Bathroom");
    QVERIFY(names.at(1) == "Garden Living Room");
}

void TestController::testGetRoomArts() {
    destroyer->cleanRooms();

    Controller* con = Controller::getInstance(testData);
    RoomExpert* roomExpert = RoomExpert::getInstance(testData);

    roomExpert->createRoom("Bathroom", "Bath");
    roomExpert->createRoom("Garden Living Room", "Living Room");

    std::vector<std::string> arts = con->getRoomArts();

    QVERIFY(arts.size() == 2);
    QVERIFY(arts.at(0) == "Bath");
    QVERIFY(arts.at(1) == "Living Room");
}

void TestController::testGetRoomlistSize() {
    destroyer->cleanRooms();

    Controller* con = Controller::getInstance(testData);
    RoomExpert* roomExpert = RoomExpert::getInstance(testData);

    roomExpert->createRoom("Bathroom", "Bath");
    roomExpert->createRoom("Garden Living Room", "Living Room");

    QVERIFY(con->getRoomlistSize() == 2);
}

void TestController::testAddResident() {
    destroyer->cleanResidents();

    Controller* con = Controller::getInstance(testData);

    con->addResident("Test", 1234);
    con->addResident("Test2", 9876);

    std::vector<std::string> residents = testData->getAllResidents();

    QVERIFY(residents.size() == 2);
    QVERIFY(residents.at(0) == "Test");
    QVERIFY(residents.at(1) == "Test2");
}

void TestController::testDeleteResident() {
    destroyer->cleanResidents();

    ResidentExpert* residentExpert = ResidentExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    residentExpert->createResident("Test", 1234);
    residentExpert->createResident("Test2", 9876);

    con->deleteResident("Test");

    std::vector<std::string> residents = testData->getAllResidents();

    QVERIFY(residents.size() == 1);
    QVERIFY(residents.at(0) == "Test2");
}

void TestController::testEditResident() {
    destroyer->cleanResidents();

    ResidentExpert* residentExpert = ResidentExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    residentExpert->createResident("Test", 1234);
    residentExpert->createResident("Test2", 9876);

    con->editResident("Test", 5678);

    QVERIFY(testData->verifyLogInData("Test", 5678));
}

void TestController::testSearchResident() {
    destroyer->cleanResidents();

    ResidentExpert* residentExpert = ResidentExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    residentExpert->createResident("Test", 1234);
    residentExpert->createResident("Test2", 9876);

    QVERIFY(con->searchResident("Test", 1234));
}

void TestController::testSearchNameResident() {
    destroyer->cleanResidents();

    ResidentExpert* residentExpert = ResidentExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    residentExpert->createResident("Test", 1234);
    residentExpert->createResident("Test2", 9876);

    QVERIFY(con->searchNameResident("Test"));
}

void TestController::testGetUserNames() {
    destroyer->cleanResidents();

    ResidentExpert* residentExpert = ResidentExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    residentExpert->createResident("Test", 1234);
    residentExpert->createResident("Test2", 9876);

    std::vector<std::string> residents = con->getUserNames();

    QVERIFY(residents.size() == 2);
    QVERIFY(residents.at(0) == "Test");
    QVERIFY(residents.at(1) == "Test2");
}

void TestController::testGetUserlistSize() {
    destroyer->cleanResidents();

    ResidentExpert* residentExpert = ResidentExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    residentExpert->createResident("Test", 1234);
    residentExpert->createResident("Test2", 9876);

    QVERIFY(con->getUserlistSize() == 2);
}

void TestController::testAddEvent() {
    destroyer->cleanEvents();

    Controller* con = Controller::getInstance(testData);

    con->addEvent(" 10:00", "2018-01-01", "Test", "Test-User");
    con->addEvent(" 10:00", "2018-01-02", "Test", "Test-User");

    std::vector<Event> events = testData->getAllEvents("Test-User", "2018-01-01");

    QVERIFY(events.size() == 1);
    QVERIFY(events.at(0).getDate() == "2018-01-01");
    QVERIFY(events.at(0).getDescription() == "Test");
    QVERIFY(events.at(0).getUser() == "Test-User");
    QVERIFY(events.at(0).getTime() == " 10:00");
}

void TestController::testDeleteEvent() {
    destroyer->cleanEvents();

    EventExpert* eventExpert = EventExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    eventExpert->createEvent(" 10:00", "2018-01-01", "Test", "Test-User");
    eventExpert->createEvent(" 11:00", "2018-01-01", "Test", "Test-User");

    con->deleteEvent(" 10:00", "2018-01-01", "Test", "Test-User");

    std::vector<Event> events = testData->getAllEvents("Test-User", "2018-01-01");

    QVERIFY(events.size() == 1);
    QVERIFY(events.at(0).getDate() == "2018-01-01");
    QVERIFY(events.at(0).getDescription() == "Test");
    QVERIFY(events.at(0).getUser() == "Test-User");
    QVERIFY(events.at(0).getTime() == " 11:00");
}

void TestController::testGetEventTime() {
    destroyer->cleanEvents();

    EventExpert* eventExpert = EventExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    eventExpert->createEvent(" 10:00", "2018-01-01", "Test", "Test-User");
    eventExpert->createEvent(" 11:00", "2018-01-01", "Test", "Test-User");

    std::vector<std::string> eventTimes = con->getEventTime("Test-User", "2018-01-01");

    QVERIFY(eventTimes.size() == 2);
    QVERIFY(eventTimes.at(0) == " 10:00");
    QVERIFY(eventTimes.at(1) == " 11:00");
}

void TestController::testGetEventDate() {
    destroyer->cleanEvents();

    EventExpert* eventExpert = EventExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    eventExpert->createEvent(" 10:00", "2018-01-01", "Test", "Test-User");
    eventExpert->createEvent(" 11:00", "2018-01-01", "Test", "Test-User");

    std::vector<std::string> eventDates = con->getEventDate("Test-User", "2018-01-01");

    QVERIFY(eventDates.size() == 2);
    QVERIFY(eventDates.at(0) == "2018-01-01");
    QVERIFY(eventDates.at(1) == "2018-01-01");
}

void TestController::testGetEventDescription() {
    destroyer->cleanEvents();

    EventExpert* eventExpert = EventExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    eventExpert->createEvent(" 10:00", "2018-01-01", "Test", "Test-User");
    eventExpert->createEvent(" 11:00", "2018-01-01", "Test", "Test-User");

    std::vector<std::string> eventDescriptions = con->getEventDescription("Test-User", "2018-01-01");

    QVERIFY(eventDescriptions.size() == 2);
    QVERIFY(eventDescriptions.at(0) == "Test");
    QVERIFY(eventDescriptions.at(1) == "Test");
}

void TestController::testGetEventUser() {
    destroyer->cleanEvents();

    EventExpert* eventExpert = EventExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    eventExpert->createEvent(" 10:00", "2018-01-01", "Test", "Test-User");
    eventExpert->createEvent(" 11:00", "2018-01-01", "Test", "Test-User");

    std::vector<std::string> eventUsers = con->getEventUser("Test-User", "2018-01-01");

    QVERIFY(eventUsers.size() == 2);
    QVERIFY(eventUsers.at(0) == "Test-User");
    QVERIFY(eventUsers.at(1) == "Test-User");
}

void TestController::testGetSizeEvent() {
    destroyer->cleanEvents();

    EventExpert* eventExpert = EventExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    eventExpert->createEvent(" 10:00", "2018-01-01", "Test", "Test-User");
    eventExpert->createEvent(" 11:00", "2018-01-01", "Test", "Test-User");

    QVERIFY(con->getSizeEvent("Test-User", "2018-01-01") == 2);
}

void TestController::testGetAllDates() {
    destroyer->cleanEvents();

    EventExpert* eventExpert = EventExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    eventExpert->createEvent(" 10:00", "2018-01-01", "Test", "Test-User");
    eventExpert->createEvent(" 11:00", "2018-01-02", "Test", "Test-User");

    std::vector<std::string> dates = con->getAllDates("Test-User");

    QVERIFY(dates.size() == 2);
    QVERIFY(dates.at(0) == "2018-01-01");
    QVERIFY(dates.at(1) == "2018-01-02");
}

void TestController::testAddTask() {
    destroyer->cleanTasks();

    Controller* con = Controller::getInstance(testData);

    con->addTask("Clean", "Bath", "Daily");
    con->addTask("Wash", "Kitchen", "Monthly");

    std::vector<Task> tasks = testData->getAllTasks();

    QVERIFY(tasks.size() == 2);
    QVERIFY(tasks.at(0).getName() == "Clean");
    QVERIFY(tasks.at(0).getRoom() == "Bath");
    QVERIFY(tasks.at(0).getFrequency() == "Daily");
    QVERIFY(tasks.at(1).getName() == "Wash");
    QVERIFY(tasks.at(1).getRoom() == "Kitchen");
    QVERIFY(tasks.at(1).getFrequency() == "Monthly");
}

void TestController::testDeleteTask() {
    destroyer->cleanTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    con->deleteTask("Clean", "Bath");

    std::vector<Task> tasks = testData->getAllTasks();

    QVERIFY(tasks.size() == 1);
    QVERIFY(tasks.at(0).getName() == "Wash");
    QVERIFY(tasks.at(0).getRoom() == "Kitchen");
    QVERIFY(tasks.at(0).getFrequency() == "Monthly");
}

void TestController::testGetTaskName() {
    destroyer->cleanTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    std::vector<std::string> names = con->getTaskName();

    QVERIFY(names.size() == 2);
    QVERIFY(names.at(0) == "Clean");
    QVERIFY(names.at(1) == "Wash");
}

void TestController::testGetTaskRoom() {
    destroyer->cleanTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    std::vector<std::string> rooms = con->getTaskRoom();

    QVERIFY(rooms.size() == 2);
    QVERIFY(rooms.at(0) == "Bath");
    QVERIFY(rooms.at(1) == "Kitchen");
}

void TestController::testGetTaskFrequency() {
    destroyer->cleanTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    std::vector<std::string> frequencies = con->getTaskFrequency();

    QVERIFY(frequencies.size() == 2);
    QVERIFY(frequencies.at(0) == "Daily");
    QVERIFY(frequencies.at(1) == "Monthly");
}

void TestController::testGetTasklistSize() {
    destroyer->cleanTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    QVERIFY(con->getTasklistSize() == 2);
}

void TestController::testAddConcreteTask() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    con->addConcreteTask(28, "Clean", "Test-User", "Bath");
    con->addConcreteTask(28, "Wash", "Test-User", "Kitchen");

    std::vector<ConcreteTask> tasks = testData->getAllConcreteTasks(28);

    QVERIFY(tasks.size() == 2);
    QVERIFY(tasks.at(0).getCalendarweek() == 28);
    QVERIFY(tasks.at(0).getResident() == "Test-User");
    QVERIFY(tasks.at(0).getTask().getName() == "Clean");
    QVERIFY(tasks.at(0).getTask().getRoom() == "Bath");
    QVERIFY(tasks.at(0).getTask().getFrequency() == "Daily");
    QVERIFY(tasks.at(1).getCalendarweek() == 28);
    QVERIFY(tasks.at(1).getResident() == "Test-User");
    QVERIFY(tasks.at(1).getTask().getName() == "Wash");
    QVERIFY(tasks.at(1).getTask().getRoom() == "Kitchen");
    QVERIFY(tasks.at(1).getTask().getFrequency() == "Monthly");
}

void TestController::testDeleteConcreteTask() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    taskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");
    taskExpert->createConcreteTask("Wash", "Test-User", 28, "Kitchen");

    con->deleteConcreteTask(28, "Clean", "Test-User", "Bath");

    std::vector<ConcreteTask> tasks = testData->getAllConcreteTasks(28);

    QVERIFY(tasks.size() == 1);
    QVERIFY(tasks.at(0).getCalendarweek() == 28);
    QVERIFY(tasks.at(0).getResident() == "Test-User");
    QVERIFY(tasks.at(0).getTask().getName() == "Wash");
    QVERIFY(tasks.at(0).getTask().getRoom() == "Kitchen");
    QVERIFY(tasks.at(0).getTask().getFrequency() == "Monthly");
}

void TestController::testGetConcreteTaskWeek() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    taskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");
    taskExpert->createConcreteTask("Wash", "Test-User", 28, "Kitchen");

    std::vector<int> taskWeeks = con->getConcreteTaskWeek();

    QVERIFY(taskWeeks.size() == 2);
    QVERIFY(taskWeeks.at(0) == 28);
    QVERIFY(taskWeeks.at(1) == 28);
}

void TestController::testGetConcreteTaskName() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    taskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");
    taskExpert->createConcreteTask("Wash", "Test-User", 28, "Kitchen");

    std::vector<std::string> taskNames = con->getConcreteTaskName();

    QVERIFY(taskNames.size() == 2);
    QVERIFY(taskNames.at(0) == "Clean");
    QVERIFY(taskNames.at(1) == "Wash");
}

void TestController::testGetConcreteTaskRes() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    taskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");
    taskExpert->createConcreteTask("Wash", "Test-User", 28, "Kitchen");

    std::vector<std::string> taskResidents = con->getConcreteTaskRes();

    QVERIFY(taskResidents.size() == 2);
    QVERIFY(taskResidents.at(0) == "Test-User");
    QVERIFY(taskResidents.at(1) == "Test-User");
}

void TestController::testGetConcreteTaskRoom() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    taskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");
    taskExpert->createConcreteTask("Wash", "Test-User", 28, "Kitchen");

    std::vector<std::string> taskRooms = con->getConcreteTaskRoom();

    QVERIFY(taskRooms.size() == 2);
    QVERIFY(taskRooms.at(0) == "Bath");
    QVERIFY(taskRooms.at(1) == "Kitchen");
}

void TestController::testGetConcreteTaskListSize() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* taskExpert = TaskExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    taskExpert->createTask("Clean", "Bath", "Daily");
    taskExpert->createTask("Wash", "Kitchen", "Monthly");

    taskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");
    taskExpert->createConcreteTask("Wash", "Test-User", 28, "Kitchen");

    QVERIFY(con->getConcreteTaskListSize());
}

void TestController::testAddItem() {
    destroyer->cleanShoppingList();

    Controller* con = Controller::getInstance(testData);

    con->addItem("Milk", "2");
    con->addItem("Butter", "3");

    std::vector<Shoppingitem> items = testData->getAllItems();

    QVERIFY(items.size() == 2);
    QVERIFY(items.at(0).getItemName() == "Milk");
    QVERIFY(items.at(0).getNumber() == "2");
    QVERIFY(items.at(1).getItemName() == "Butter");
    QVERIFY(items.at(1).getNumber() == "3");
}

void TestController::testDeleteItem() {
    destroyer->cleanShoppingList();

    ShoppingExpert* shoppingExpert = ShoppingExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    shoppingExpert->createItem("Milk", "2");
    shoppingExpert->createItem("Butter", "3");

    con->deleteItem("Milk");

    std::vector<Shoppingitem> items = testData->getAllItems();

    QVERIFY(items.size() == 1);
    QVERIFY(items.at(0).getItemName() == "Butter");
    QVERIFY(items.at(0).getNumber() == "3");
}

void TestController::testGetItemNames() {
    destroyer->cleanShoppingList();

    ShoppingExpert* shoppingExpert = ShoppingExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    shoppingExpert->createItem("Milk", "2");
    shoppingExpert->createItem("Butter", "3");

    std::vector<std::string> names = con->getItemNames();

    QVERIFY(names.size() == 2);
    QVERIFY(names.at(0) == "Milk");
    QVERIFY(names.at(1) == "Butter");
}

void TestController::testGetItemNumber() {
    destroyer->cleanShoppingList();

    ShoppingExpert* shoppingExpert = ShoppingExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    shoppingExpert->createItem("Milk", "2");
    shoppingExpert->createItem("Butter", "3");

    std::vector<std::string> numbers = con->getItemNumbers();

    QVERIFY(numbers.size() == 2);
    QVERIFY(numbers.at(0) == "2");
    QVERIFY(numbers.at(1) == "3");
}

void TestController::testGetItemlistSize() {
    destroyer->cleanShoppingList();

    ShoppingExpert* shoppingExpert = ShoppingExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    shoppingExpert->createItem("Milk", "2");
    shoppingExpert->createItem("Butter", "3");

    QVERIFY(con->getItemlistSize() == 2);
}

void TestController::testCurrentUser() {
    destroyer->cleanResidents();

    ResidentExpert* residentExpert = ResidentExpert::getInstance(testData);
    Controller* con = Controller::getInstance(testData);

    residentExpert->createResident("Test-User", 1234);

    con->setCurrentUser("Test-User");

    QVERIFY(con->getCurrentUser() == "Test-User");
}
