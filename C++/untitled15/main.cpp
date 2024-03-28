#include <iostream>
#include <string>

using namespace std;

struct Test {
    string testName;
    string testContent;
};

int main() {
    struct Test tests[5];
    tests[0] = {"Test 1", "Tresc testu 1"};
    tests[1] = {"Test 2", "Tresc testu 2"};
    tests[2] = {"Test 3", "Tresc testu 3"};
    tests[3] = {"Test 4", "Tresc testu 4"};
    tests[4] = {"Test 5", "Tresc testu 5"};

    int testchoice;
    string choice1;
    bool validChoice = true;

    cout << "Witaj w programie testowym!" << endl;
    cout << "Wybierz test z listy ponizej:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << tests[i].testName << endl;
    }

    cout << "6. Wyjscie" << endl;

    do {
        validChoice = true;
        cout << "Wybierz test: ";
        if (!(cin >> testchoice)) {
            validChoice = false;
            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
            cin.clear();
            while (cin.get() != '\n')
                continue;
        } else if (testchoice < 1 || testchoice > 6) {
            validChoice = false;
            cout << "Nie ma takiej opcji. Sprobuj ponownie." << endl;
        }
    } while (!validChoice);

    if (testchoice == 6) {
        cout << "Koniec." << endl;
    } else {
        cout << "Czy na pewno chcesz wybrac ten test? (y/n)" << endl;
        cin >> choice1;
        if (choice1 == "n") {
            main();
        } else if (choice1 == "y") {
            cout << "TEST: " << tests[testchoice - 1].testContent << endl;
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
                } else {
                    cout << "Test nie zostal zatwierdzony. Czy chcesz sprobowac ponownie? (y/n)" << endl;
                    cin >> confirm;
                    if (confirm == "n") {
                        cout << "Test nie zostal zatwierdzony. Koniec." << endl;
                        break;
                    }
                }
            } while (!answerConfirmed);
        } else
            cout << "Niepoprawny wybor." << endl;
    }

    return 0;
}
