#include "TestManager.h"
#include <iostream>

TestManager::TestManager() {
    tests[0] = { "Test 1", "Tresc testu 1" };
    tests[1] = { "Test 2", "Tresc testu 2" };
    tests[2] = { "Test 3", "Tresc testu 3" };
    tests[3] = { "Test 4", "Tresc testu 4" };
    tests[4] = { "Test 5", "Tresc testu 5" };
}

void TestManager::displayTests() {
    std::cout << "Witaj w programie testowym!" << std::endl;
    std::cout << "Wybierz test z listy ponizej:" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << ". " << tests[i].testName << std::endl;
    }

    std::cout << "6. Wyjscie" << std::endl;
}

int TestManager::getTestChoice() {
    int choice;
    std::cout << "Wybierz test: ";
    while (!(std::cin >> choice) || choice < 1 || choice > 6) {
        std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
        std::cout << "Wybierz test: ";
    }
    return choice;
}

void TestManager::runTest(int testChoice) {
    if (testChoice == 6) {
        std::cout << "Koniec." << std::endl;
    }
    else {
        tests[testChoice - 1].displayTest();
        std::string answer;
        bool answerConfirmed = false;

        do {
            std::cout << "Wybierz odpowiedz: ";
            std::cin >> answer;
            std::string confirm;
            std::cout << "Czy na pewno chcesz zatwierdzic odpowiedz? (y/n)" << std::endl;
            std::cin >> confirm;

            if (confirm == "y") {
                answerConfirmed = true;
                std::cout << "Test zakonczony." << std::endl;
            }
            else {
                std::cout << "Test nie zostal zatwierdzony. Czy chcesz sprobowac ponownie? (y/n)" << std::endl;
                std::cin >> confirm;

                if (confirm == "n") {
                    std::cout << "Test nie zostal zatwierdzony. Koniec." << std::endl;
                    break;
                }
            }
        } while (!answerConfirmed);
    }
}