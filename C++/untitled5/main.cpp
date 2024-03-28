#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Wektor {
private:
    double x, y;

public:
    Wektor() {
        x = 0;
        y = 0;
    }

    Wektor(double a, double b) {
        x = a;
        y = b;
    }

    friend std::ostream& operator<<(std::ostream& os, const Wektor& w) {
        os << "[" << w.x << ", " << w.y << "]";
        return os;
    }

    Wektor operator+(const Wektor& w) {
        Wektor result(x + w.x, y + w.y);
        return result;
    }

    double operator*(const Wektor& w) {
        return x * w.x + y * w.y;
    }

    double getLength() {
        return sqrt(x * x + y * y);
    }

    static Wektor getRandomWektor() {
        double a = (double)(rand() % 31) - 15;
        double b = (double)(rand() % 31) - 15;
        return Wektor(a, b);
    }
};

void sortWektory(Wektor* tab, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tab[i].getLength() > tab[j].getLength()) {
                Wektor temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Wektor w1(3, 5);
    Wektor w2(-2, 7);
    std::cout << "w1 = " << w1 << std::endl;
    std::cout << "w2 = " << w2 << std::endl;
    std::cout << std::endl;

    Wektor w3 = w1 + w2;
    std::cout << "w1 + w2 = " << w3 << std::endl;
    std::cout << std::endl;

    double iloczyn_skalarny = w1 * w2;
    std::cout << "w1 * w2 = " << iloczyn_skalarny << std::endl;
    std::cout << std::endl;

    const int N = 20;
    Wektor tab[N];
    for (int i = 0; i < N; i++) {
        tab[i] = Wektor::getRandomWektor();
        std::cout << i + 1 << ". " << tab[i] << " dlugosc: " << tab[i].getLength() << std::endl;
    }
    std::cout << std::endl;

    sortWektory(tab, N);
    std::cout << "Posortowane wektory:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << i + 1 << ". " << tab[i] << " dlugosc: " << tab[i].getLength() << std::endl;
    }
    std::cout << std::endl;

    Wektor najblizszy;
    double min_odleglosc = INFINITY;
    for (int i = 0; i < N; i++) {
        double odleglosc = sqrt(pow(tab[i].getLength() - w1.getLength(), 2) + pow(tab
[i].getLength() - w1.getLength(), 2));
        if (odleglosc < min_odleglosc) {
            min_odleglosc = odleglosc;
            najblizszy = tab[i];
        }
    }
    std::cout << "Najblizszy wektor do w1 = " << najblizszy << " dlugosc: " << najblizszy.getLength() << std::endl;
    std::cout << std::endl;

    Wektor a(1, 2);
    Wektor b(3, 4);
    double radiany = acos(a * b / (a.getLength() * b.getLength()));
    double stopnie = radiany * 180 / M_PI;
    std::cout << "Kat pomiedzy a i b: " << stopnie << " stopni" << std::endl;
    std::cout << std::endl;

    return 0;
}