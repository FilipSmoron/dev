#include <iostream>
#include <cmath>

using namespace std;

class Wielomian {
    int stopien;
    double* wspolczynniki;
public:
    friend ostream& operator << (ostream& os, Wielomian w);
    friend Wielomian operator * (Wielomian w, double liczba);
    friend Wielomian operator + (Wielomian w1, Wielomian w2);

    Wielomian(int stopien, double* wspolczynniki) {
        this->stopien = stopien;
        this->wspolczynniki = new double[stopien];
        for (int i = 0; i < stopien; i++) {
            this->wspolczynniki[i] = wspolczynniki[i];
        }
    }

    Wielomian(Wielomian& w) {
        stopien = w.stopien;
        wspolczynniki = new double[stopien];
        for (int i = 0; i < stopien; i++) {
            wspolczynniki[i] = w.wspolczynniki[i];
        }
    }

    ~Wielomian() {
        delete[] wspolczynniki;
    }
};

    ostream& operator << (ostream& os, Wielomian w) {

        for (int i = w.stopien - 1; i >= 0; i--) {
            if (w.wspolczynniki[i] == 0) continue;
            if (w.wspolczynniki[i] > 0 && i != w.stopien - 1) os << "+";
            if (w.wspolczynniki[i] != 1 || i == 0) os << w.wspolczynniki[i];
            if (i != 0) os << "x";
            if (i > 1) os << "^" << i;
        }
        return os;
    }
    Wielomian operator * (Wielomian w, double liczba) {
        Wielomian new_w(w.stopien, w.wspolczynniki);
        for (int i = 0; i < w.stopien; i++) {
            new_w.wspolczynniki[i] *= liczba;
        }
        return new_w;
    }
    Wielomian operator + (Wielomian w1, Wielomian w2) {
        int max_stopien = max(w1.stopien, w2.stopien);
        int min_stopien = min(w1.stopien, w2.stopien);
        Wielomian new_w(max_stopien, new double[max_stopien]);
        for (int i = 0; i < min_stopien; i++) {
            new_w.wspolczynniki[i] = w1.wspolczynniki[i] + w2.wspolczynniki[i];
        }
        if (w1.stopien > w2.stopien) {
            for (int i = min_stopien; i < max_stopien; i++) {
                new_w.wspolczynniki[i] = w1.wspolczynniki[i];
            }
        } else {
            for (int i = min_stopien; i < max_stopien; i++) {
                new_w.wspolczynniki[i] = w2.wspolczynniki[i];
            }
        }
        return new_w;
    }
    int main() {
        double wspolczynniki1[] = {-5, 1};
        double wspolczynniki2[] = {1, 0, -7, -3.4};
        double wspolczynniki3[] = {0, 0, 0, -7, 0, 7.8};
        Wielomian w1(2, wspolczynniki1);
        Wielomian w2(4, wspolczynniki2);
        Wielomian w3(6, wspolczynniki3);
        cout << w1 << endl;
        cout << w2 << endl;
        cout << w3 << endl;
        cout << "w1 + w2 + w3 = " << w1 + w2 + w3 << endl;
        cout << "w2 * 3 = " << w2 * 3 << endl;
        return 0;
    }