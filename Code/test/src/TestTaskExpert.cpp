#include "../lib/TestTaskExpert.h"

TestTaskExpert::TestTaskExpert(CommunityData *testData, TestDatabaseDeleter *destroyer) {
    this->testData = testData;
    this->destroyer = destroyer;
}

void TestTaskExpert::testCreateTask() {
    destroyer->cleanTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createTask("Wash", "Kitchen", "Monthly");

    std::vector<Task> tasks = testData->getAllTasks();

    QVERIFY(tasks.size() == 2);
    QVERIFY(tasks.at(0).getName() == "Clean");
    QVERIFY(tasks.at(0).getRoom() == "Bath");
    QVERIFY(tasks.at(0).getFrequency() == "Daily");
    QVERIFY(tasks.at(1).getName() == "Wash");
    QVERIFY(tasks.at(1).getRoom() == "Kitchen");
    QVERIFY(tasks.at(1).getFrequency() == "Monthly");
}

void TestTaskExpert::testDeleteTask() {
    destroyer->cleanTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createTask("Wash", "Kitchen", "Monthly");

    testTaskExpert->deleteTask("Clean", "Bath");

    std::vector<Task> tasks = testData->getAllTasks();

    QVERIFY(tasks.size() == 1);
    QVERIFY(tasks.at(0).getName() == "Wash");
    QVERIFY(tasks.at(0).getRoom() == "Kitchen");
    QVERIFY(tasks.at(0).getFrequency() == "Monthly");
}

void TestTaskExpert::testTaskNameGetter() {
    destroyer->cleanTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createTask("Wash", "Kitchen", "Monthly");

    std::vector<std::string> names = testTaskExpert->taskNameGetter();

    QVERIFY(names.size() == 2);
    QVERIFY(names.at(0) == "Clean");
    QVERIFY(names.at(1) == "Wash");
}

void TestTaskExpert::testTaskRoomGetter() {
    destroyer->cleanTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createTask("Wash", "Kitchen", "Monthly");

    std::vector<std::string> rooms = testTaskExpert->taskRoomGetter();

    QVERIFY(rooms.size() == 2);
    QVERIFY(rooms.at(0) == "Bath");
    QVERIFY(rooms.at(1) == "Kitchen");
}

void TestTaskExpert::testTaskFrequencyGetter() {
    destroyer->cleanTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createTask("Wash", "Kitchen", "Monthly");

    std::vector<std::string> frequencies = testTaskExpert->taskFrequencyGetter();

    QVERIFY(frequencies.size() == 2);
    QVERIFY(frequencies.at(0) == "Daily");
    QVERIFY(frequencies.at(1) == "Monthly");
}

void TestTaskExpert::testGetTasks() {
    destroyer->cleanTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createTask("Wash", "Kitchen", "Monthly");

    std::vector<Task> tasks = testTaskExpert->getTasks();

    QVERIFY(tasks.size() == 2);
    QVERIFY(tasks.at(0).getName() == "Clean");
    QVERIFY(tasks.at(0).getRoom() == "Bath");
    QVERIFY(tasks.at(0).getFrequency() == "Daily");
    QVERIFY(tasks.at(1).getName() == "Wash");
    QVERIFY(tasks.at(1).getRoom() == "Kitchen");
    QVERIFY(tasks.at(1).getFrequency() == "Monthly");
}

void TestTaskExpert::testCreateConcreteTask() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");

    std::vector<ConcreteTask> tasks = testData->getAllConcreteTasks(28);

    QVERIFY(tasks.size() == 1);
    QVERIFY(tasks.at(0).getTask().getName() == "Clean");
    QVERIFY(tasks.at(0).getTask().getRoom() == "Bath");
    QVERIFY(tasks.at(0).getTask().getFrequency() == "Daily");
    QVERIFY(tasks.at(0).getResident() == "Test-User");
    QVERIFY(tasks.at(0).getCalendarweek() == 28);
}

void TestTaskExpert::testDeleteConcreteTask() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");
    testTaskExpert->createConcreteTask("Clean", "Test-User2", 28, "Bath");

    testTaskExpert->deleteConcreteTask("Clean", "Test-User2", 28, "Bath");

    std::vector<ConcreteTask> tasks = testData->getAllConcreteTasks(28);

    QVERIFY(tasks.size() == 1);
    QVERIFY(tasks.at(0).getTask().getName() == "Clean");
    QVERIFY(tasks.at(0).getTask().getRoom() == "Bath");
    QVERIFY(tasks.at(0).getTask().getFrequency() == "Daily");
    QVERIFY(tasks.at(0).getResident() == "Test-User");
    QVERIFY(tasks.at(0).getCalendarweek() == 28);
}

void TestTaskExpert::testConcreteTaskGetter() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");

    std::vector<ConcreteTask> tasks = testTaskExpert->concreteTaskGetter(28);

    QVERIFY(tasks.size() == 1);
    QVERIFY(tasks.at(0).getTask().getName() == "Clean");
    QVERIFY(tasks.at(0).getTask().getRoom() == "Bath");
    QVERIFY(tasks.at(0).getTask().getFrequency() == "Daily");
    QVERIFY(tasks.at(0).getResident() == "Test-User");
    QVERIFY(tasks.at(0).getCalendarweek() == 28);
}

void TestTaskExpert::testConcreteTaskNameGetter() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");

    std::vector<std::string> names = testTaskExpert->concreteTaskNameGetter(28);

    QVERIFY(names.size() == 1);
    QVERIFY(names.at(0) == "Clean");
}

void TestTaskExpert::testConcreteTaskRoomGetter() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");

    std::vector<std::string> rooms = testTaskExpert->concreteTaskRoomGetter(28);

    QVERIFY(rooms.size() == 1);
    QVERIFY(rooms.at(0) == "Bath");
}

void TestTaskExpert::testConcreteTaskWeekGetter() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");

    std::vector<int> weeks = testTaskExpert->concreteTaskWeekGetter(28);

    QVERIFY(weeks.size() == 1);
    QVERIFY(weeks.at(0) == 28);
}

void TestTaskExpert::testConcreteTaskResGetter() {
    destroyer->cleanTasks();
    destroyer->cleanConcreteTasks();

    TaskExpert* testTaskExpert = TaskExpert::getInstance(testData);

    testTaskExpert->createTask("Clean", "Bath", "Daily");
    testTaskExpert->createConcreteTask("Clean", "Test-User", 28, "Bath");

    std::vector<std::string> residents = testTaskExpert->concreteTaskResGetter(28);

    QVERIFY(residents.size() == 1);
    QVERIFY(residents.at(0) == "Test-User");
}
