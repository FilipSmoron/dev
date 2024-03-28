#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Ulamek {
private:
    int licznik;
    int mianownik;
public:
    Ulamek() {
        this->licznik = 0;
        this->mianownik = 1;
    }
    Ulamek(int l, int m) {
        licznik = l;
        mianownik = m;
    }
    Ulamek(int i) {
        licznik = i;
        mianownik = 1;
    }
    int getLicznik()  {
        return licznik;
    }
    int getMianownik() {
        return mianownik;
    }

    void skrocUlamek() {
        int a = licznik;
        int b = mianownik;
        int c;
        int nwd;
        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }
        nwd = a;
        licznik = licznik/nwd;
        mianownik = mianownik/nwd;
    }

    operator double() const {
        return static_cast<double>(licznik) / mianownik;
    }
    /*Ulamek operator+(int x) const {
        return Ulamek(licznik + x * mianownik, mianownik);
    }*/
};



Ulamek dodaj( Ulamek x1, Ulamek x2) {
    int l = x1.getLicznik() * x2.getMianownik() + x2.getLicznik() * x1.getMianownik();
    int m = x1.getMianownik() * x2.getMianownik();
    return Ulamek(l, m);
}

double kwadratLiczby(double liczba) {
    return liczba * liczba;
}

void losujUlamki(int n, Ulamek* tablica) {
    for (int i = 0; i < n; i++) {
        int l = -(rand () % 2001) + 1000;
        int m = -(rand() % 2001) + 1000;
        tablica[i] = Ulamek(l, m);
        cout << "Ulamek " << i + 1 << ": " << l << "/" << m << endl;
    }
    Ulamek max = tablica[0];
    for (int i = 1; i < n; i++) {
        if (tablica[i].getLicznik() * max.getMianownik() > max.getLicznik() * tablica[i].getMianownik()) {
            max = tablica[i];
        }
    }
    cout << "Najwiekszy ulamek: " << max.getLicznik() << "/" << max.getMianownik() << endl;
}

int main() {
    srand(time(NULL));
    Ulamek tab[3] = {Ulamek(1, 2), Ulamek(5, 8), Ulamek(7, 9) };
    for (int i = 0; i < 3; i++) {
        cout << "Ulamek " << i + 1 << ": " << tab[i].getLicznik() << "/" << tab[i].getMianownik() << endl;
    }

    Ulamek x1 = dodaj(tab[0], tab[1]);
    cout << "Suma dodawania 1 i 2 ulamka = " << x1.getLicznik() << "/" << x1.getMianownik() << endl;

    Ulamek x2 = dodaj(tab[0], 7);
    cout << "Suma dodawania ulamka 1 i liczby 7 = " << x2.getLicznik() << "/" << x2.getMianownik() << endl;

    Ulamek x3(88, 22);
    x3.skrocUlamek();
    cout << "Ulamek 88/22 po skroceniu: " << x3.getLicznik() << "/" << x3.getMianownik() << endl;

    double kwadrat = kwadratLiczby((double)tab[2]);
    cout << "Kwadrat ulamka 7/9 wynosi: " << kwadrat << endl;

    int n = 10;
    Ulamek* tablicaUlamkow = new Ulamek[n];
    losujUlamki(n, tablicaUlamkow);
    delete[] tablicaUlamkow;

    return 0;
}
