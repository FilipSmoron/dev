#include <iostream>

using namespace std;

class Student {
private:
    string imie;
    string nazwisko;
    string kierunek;
    int rok_studiow;
public:
    Student() {
        this->imie = "Jan";
        this->nazwisko = "Kowalski";
        this->kierunek = "Informatyka";
        this->rok_studiow = 1;
    }
    Student(string imie, string nazwisko, string kierunek, int rok_studiow) {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->kierunek = kierunek;
        this->rok_studiow = rok_studiow;
    }
};

class Grupa {
private:
    string numer_grupy;
    const int limit_miejsc = 10;
    Student tablica_studentow[limit_miejsc];
};

int main() {
    Student* student = new Student();

    return 0;
}
