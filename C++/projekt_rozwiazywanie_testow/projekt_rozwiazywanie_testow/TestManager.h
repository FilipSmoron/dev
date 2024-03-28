#ifndef TEST_MANAGER_H
#define TEST_MANAGER_H

#include <iostream>
#include <string>

class Test {
public:
    std::string testName;
    std::string testContent;

    Test() {}

    Test(const std::string& name, const std::string& content) : testName(name), testContent(content) {}

    void displayTest() {
        std::cout << "TEST: " << testContent << std::endl;
    }
};

class TestManager {
private:
    Test tests[5];

public:
    TestManager();

    void displayTests();

    int getTestChoice();

    void runTest(int testChoice);
};

#endif // TEST_MANAGER_H
