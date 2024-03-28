#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct Dane {
    double x;
    double y;
};

double interpolacja(Dane d[], double xp, int n) {
    double yp = 0;

    for (int i = 0; i < n; i++) {
        double p = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                p = p * (xp - d[j].x) / (d[i].x - d[j].x);
            }
        }
        yp = yp + p * d[i].y;
    }

    return yp;
}

int main() {
    ifstream plik("dane.txt");

    if (!plik) {
        cerr << "Nie można otworzyć pliku." << endl;
        return 1;
    }

    vector<Dane> dane;

    Dane d;
    while (plik >> d.x >> d.y) {
        dane.push_back(d);
    }

    plik.close();

    int n;
    cout << "Podaj ilosc danych: ";
    cin >> n;

    double xp;
    cout << "Podaj punkt interpolacyjny: ";
    cin >> xp;

    cout << "Ilosc wezlow: " << n << endl;

    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "] = " << dane[i].x << ", y[" << i << "] = " << dane[i].y << endl;
    }

    double wynik = interpolacja(&dane[0], xp, n);
    cout << "Interpolowana wartosc w x = " << xp << " to: " << wynik <<endl;

    vector<Dane> dane1 = {{27, 3}, {64, 4}, {125, 5}, {216, 6}};

    double xp1 = pow(50, 1.0/3);

    for (int i = 0; i < dane1.size(); ++i) {
        cout << "x[" << i << "] = " << dane1[i].x << ", y[" << i << "] = " << dane1[i].y << endl;
    }

    double wynik1 = interpolacja(&dane1[0], xp1, dane1.size());
    cout << "Interpolowana wartosc w x = " << xp1 << " to: " << wynik1;

    return 0;
}
