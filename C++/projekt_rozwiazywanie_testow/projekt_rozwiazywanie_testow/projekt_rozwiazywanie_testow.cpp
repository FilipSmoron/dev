#include <iostream>
#include <string>

using namespace std;

class Test {
public:
    string testName;
    string testContent;

    Test() {}

    Test(string name, string content) : testName(name), testContent(content) {}

    void displayTest() {
        cout << "TEST: " << testContent << endl;
    }
};

class TestManager {
private:
    Test tests[5];

public:
    TestManager() {
        tests[0] = { "Test 1", "Tresc testu 1" };
        tests[1] = { "Test 2", "Tresc testu 2" };
        tests[2] = { "Test 3", "Tresc testu 3" };
        tests[3] = { "Test 4", "Tresc testu 4" };
        tests[4] = { "Test 5", "Tresc testu 5" };
    }

    void displayTests() {
        cout << "Witaj w programie testowym!" << endl;
        cout << "Wybierz test z listy ponizej:" << endl;

        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << tests[i].testName << endl;
        }

        cout << "6. Wyjscie" << endl;
    }

    int getTestChoice() {
        int choice;
        cout << "Wybierz test: ";
        while (!(cin >> choice) || choice < 1 || choice > 6) {
            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Wybierz test: ";
        }
        return choice;
    }

    void runTest(int testChoice) {
        if (testChoice == 6) {
            cout << "Koniec." << endl;
        }
        else {
            tests[testChoice - 1].displayTest();
            string answer;
            bool answerConfirmed = false;

            do {
                cout << "Wybierz odpowiedz: ";
                cin >> answer;
                string confirm;
                cout << "Czy na pewno chcesz zatwierdzic odpowiedz? (y/n)" << endl;
                cin >> confirm;

                if (confirm == "y") {
                    answerConfirmed = true;
                    cout << "Test zakonczony." << endl;
                }
                else {
                    cout << "Test nie zostal zatwierdzony. Czy chcesz sprobowac ponownie? (y/n)" << endl;
                    cin >> confirm;

                    if (confirm == "n") {
                        cout << "Test nie zostal zatwierdzony. Koniec." << endl;
                        break;
                    }
                }
            } while (!answerConfirmed);
        }
    }
};

int main() {
    TestManager testManager;
    testManager.displayTests();
    int testChoice = testManager.getTestChoice();
    testManager.runTest(testChoice);

    return 0;
}