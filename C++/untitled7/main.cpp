#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Zwierze {
protected:
    string imie;
    int liczba_nog;
    double masa;
    friend void sortuj_zwierzeta(Zwierze* tab[], int n);
public:
    Zwierze(string i = "", double m = 0.0, int n = 0) : imie(i), masa(m), liczba_nog(n) {}

    virtual void wyswietl() {
        cout << "Zwierze: " << imie << ", masa: " << masa << " kg, liczba nog: " << liczba_nog << endl;
    }

};

class Pies : public Zwierze {
private:
    string rasa;
    string kolor_siersci;

public:
    Pies(string i, double m, int n, string r, string k) : Zwierze(i, m, n), rasa(r), kolor_siersci(k) {}

    void wyswietl() {
        cout << "Pies: " << imie << ", masa: " << masa << " kg, liczba nog: " << liczba_nog << ", rasa: " << rasa << ", kolor siersci: " << kolor_siersci << endl;
    }
};

class Papuga : public Zwierze {
private:
    string kolor_pior;

public:
    Papuga(string i, double m, int n, string k) : Zwierze(i, m, n), kolor_pior(k) {}

    Papuga(const Papuga& p) : Zwierze("Pala", p.masa * 1.2, p.liczba_nog), kolor_pior(p.kolor_pior) {}

    void wyswietl() {
        cout << "Papuga: " << imie << ", masa: " << masa << " kg, liczba nog: " << liczba_nog << ", kolor pior: " << kolor_pior << endl;
    }
};

void sortuj_zwierzeta(Zwierze* tab[], int n) {
    sort(tab, tab + n, [](Zwierze* a, Zwierze* b) { return a->masa < b->masa; });
}

int main() {
    // a) Stwórz obiekt klasy Zwierze. Wyświetl dane zwierzęcia.
    Zwierze m("Mis", 50.0, 4);
    m.wyswietl();

    // b) Stwórz dynamiczny obiekt klasy Pies przy użyciu konstruktora wieloargumentowego. Wyświetl dane obiektu.
    Pies *p = new Pies("Reksio", 10.0, 4, "owczarek niemiecki", "czarny");
    p->wyswietl();

    // c) Stwórz 2 obiekty klasy Papuga, przy czym drugi utwórz przy użyciu konstruktora kopiującego.
    Papuga pa1("Ala", 0.5, 2, "zielony");
    Papuga pa2 = pa1;
    pa2.wyswietl();

    // d) Stwórz tablicę 4-elementową dynamiczną wskaźników na obiekty klasy Zwierze.
    Zwierze *tab[4];
// Ustaw wskaźniki na utworzone wcześniej obiekty.
    tab[0] = &m;
    tab[1] = p;
    tab[2] = &pa1;
    tab[3] = &pa2;
// Wyświetl tablicę używając pętli (muszą zostać wyświetlone wszystkie dane).
    for (int i = 0; i < 4; i++) {
        tab[i]->wyswietl();
    }
    // e) Stwórz funkcję globalną, która posortuje tablicę wskaźników (utworzoną w punkcie d) rosnąco względem mas zwierząt, na które te wskaźniki są ustawione. Wyświetl posortowaną tablicę.
    sortuj_zwierzeta(tab, 4);
    cout << "Posortowane zwierzeta:" << endl;
    for (int i = 0; i < 4; i++) {
        tab[i]->wyswietl();
    }

// Zwolnij pamięć zaalokowaną dla dynamicznego obiektu klasy Pies.
    delete p;

    return 0;
}