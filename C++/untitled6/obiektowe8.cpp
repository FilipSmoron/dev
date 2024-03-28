#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Wektor {
private:
    double x;
    double y;

public:
    // Konstruktory
    Wektor()  {}
    Wektor(double x, double y){
        this->x = x;
        this->y = y;
    }

    // Metody
    double dlugosc() {
        return sqrt(x * x + y * y);
    }

    // Przeciążone operatory
    Wektor operator+(const Wektor& other) {
        return Wektor(x + other.x, y + other.y);
    }

    double operator*(const Wektor& other) {
        return x * other.x + y * other.y;
    }

    friend ostream& operator<<(ostream& out, const Wektor& w) {
        out << "[" << w.x << "," << w.y << "]";
        return out;
    }
    static Wektor znajdzNajblizszyWektor(Wektor tablica[],  int rozmiar) {
        Wektor najblizszy = tablica[0];
        double roznica = abs(najblizszy.dlugosc() - Wektor(3, 5).dlugosc());
        for (int i = 1; i < rozmiar; i++) {
            double roznicaAktualna = abs(tablica[i].dlugosc() - Wektor(3, 5).dlugosc());
            if (roznicaAktualna < roznica) {
                najblizszy = tablica[i];
                roznica = roznicaAktualna;
            }
        }
        return najblizszy;
    }
    static double obliczKat(Wektor& w1, Wektor& w2) {
        return acos((w1 * w2) / (w2.dlugosc() * w1.dlugosc())) * 180 / M_PI;
    }
    static bool compare(Wektor& w1, Wektor& w2) {
        return w1.dlugosc() < w2.dlugosc();
    }
};

int main() {
    // a) Tworzenie wektorów i wypisywanie ich na ekranie
    Wektor w1(3, 5);
    Wektor w2(-2, 7);
    cout << "Wektor 1: " << w1 << endl;
    cout << "Wektor 2: " << w2 << endl;

    // b) Dodawanie wektorów i wypisywanie wyniku na ekranie
    Wektor suma = w1 + w2;
    cout << "Suma wektorow: " << suma << endl;

    // c) Obliczanie iloczynu skalarnego i wypisywanie wyniku na ekranie
    double iloczyn = w1 * w2;
    cout << "Iloczyn skalarny: " << iloczyn << endl;

    // d) Tworzenie i sortowanie tablicy wektorów
    srand(time(NULL));
    Wektor tab[20];
    for (int i = 0; i < 20; i++) {
        double x = (rand() % 31) - 15; // losowe wartości z zakresu [-15, 15)
        double y = (rand() % 31) - 15;
        tab[i] = Wektor(x, y);
    }
    sort(tab, tab + 20, Wektor::compare);


    // Wypisywanie tablicy na ekranie
    cout << "Posortowana tablica wektorow:" << endl;
    for (int i = 0; i < 20; i++) {
        cout << i + 1 << ": " << tab[i] << endl;
    }


    // e) Szukanie wektora o długości najbliższej [3,5] i wyświetlenie wyniku
    Wektor najblizszy = Wektor::znajdzNajblizszyWektor(tab, 20);
    cout << "Najblizszy wektor do [3,5]: " << najblizszy << " jego dlugosc to: " << najblizszy.dlugosc() << endl;

    cout << "Dlugosc wektora [3,5]: " << Wektor(3, 5).dlugosc() << endl;

// f) Obliczanie kąta między dwoma wektorami i wyświetlenie wyniku
    double kat = Wektor::obliczKat(w1, w2);
    cout << "Kat miedzy wektorami: " << kat << " stopni" << endl;
}