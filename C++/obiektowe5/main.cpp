#include <iostream>
#include <cmath>
#include<ctime>


using namespace std;
class Okrag;
class Prostokat;
class Punkt {
private:
    int x;
    int y;

    //deklaracja przyjazni
    friend class Prostokat;
    friend class Okrag;
    friend void wypisz (Punkt punkt);
    friend void wypisz(Prostokat prostokat);
    friend void wypisz(Okrag okrag);
public:
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    Punkt(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Punkt() {}

};

class Prostokat {
private:
    Punkt ldw; //lewy dolny wierzcholek
    int szerokosc;
    int wysokosc;

    friend void wypisz (Prostokat prostokat);
public:
    int getSzerokosc() {
        return szerokosc;
    }
    int getWysokosc() {
        return wysokosc;
    }
    Prostokat(Punkt ldw, int szerokosc, int wysokosc) {
        this->ldw = ldw;
        this->szerokosc = szerokosc;
        this->wysokosc = wysokosc;
    }

    static void czyWspolne(Punkt tab[], Prostokat prostokat) {
        for (int i = 0; i < 3; i++) {
            if (tab[i].x >= prostokat.ldw.x && tab[i].x <= (prostokat.ldw.x + prostokat.szerokosc) && tab[i].y >= prostokat.ldw.y && tab[i].y <= (prostokat.ldw.y + prostokat.wysokosc))
                cout << "Punkt x = " << tab[i].x <<", y = " << tab[i].y << " lezy w prostokacie" << endl;
            else {
                cout << "Punkt x = " << tab[i].x <<", y = " << tab[i].y <<" nie lezy w prostokacie" << endl;
            }


        }

    }

};

class Okrag {
private:
    Punkt srodek;
    int promien;

    friend void wypisz (Okrag okrag);
public:
    int getPromien() {
        return promien;
    }
    Punkt getSrodek() {
        return srodek;
    }

    Okrag(Punkt punkt, int i) {
        srodek = punkt;
        promien = i;


    }
    Okrag() {
    }
    static void losuj1(Okrag tab1[], int n) {
        srand( (time(NULL)));
        for (int i = 0; i < n; i++) {
            tab1[i].srodek.x = rand() % 5 + 1;
            tab1[i].srodek.y = -(rand() % 5 + 1);
            tab1[i].promien =  (rand() % 9 + 1) + 1;
        }
    }
    static void losuj2(Okrag tab2[], int m) {
        srand ( (time(NULL)));
        for (int i = 0; i < m; i++) {
            tab2[i].srodek.x = -(rand() % 15 + 1) + 10;
            tab2[i].srodek.y = -(rand() % 15 + 1) + 5;
            tab2[i].promien =  (rand() % 14 + 1) + 1;
        }
    }
    static void zliczPrzeciecia(Okrag tab1[], Okrag tab2[],int n, int m) {
        int licznik = 0;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if ((sqrt(pow((tab2[j].srodek.x-tab1[i].srodek.x), 2) + pow((tab2[j].srodek.y - tab1[i].srodek.y), 2) < (tab1[i].promien+tab2[j].promien)) && fabs(tab2[j].promien-tab1[i].promien) < ((sqrt(pow((tab2[j].srodek.x-tab1[i].srodek.x), 2) + pow((tab2[j].srodek.y - tab1[i].srodek.y), 2)))))) {
                    licznik++;
                    break;
                }
            }
        }
        cout << "Liczba okregow przecinajacych sie: " << licznik << endl;
    }
    /*static void print(Okrag tab[], int n) //wypisuje wszystkie okregi
    {
        for (int i = 0; i < 100; i++) {
            cout << "Okrag nr " << i+1 << " ma srodek w punkcie x = " << tab[i].srodek.x << ", y = " << tab[i].srodek.y << " i promien = " << tab[i].promien << endl;
        }
    }*/

};

void wypisz(Punkt punkt) {
    cout << "Punkt o wspolrzednych (" << punkt.x << "," << punkt.y << ")" << endl;
}


void wypisz(Prostokat prostokat) {
    cout << "Prostokat z lewym dolnym wierzcholkiek (" << prostokat.ldw.x << "," << prostokat.ldw.y << "), szerokoscia " << prostokat.szerokosc << " i wysokoscia " << prostokat.wysokosc << endl;
}


void wypisz(Okrag okrag) {
    cout << "Okrag o srodku (" << okrag.srodek.x << "," << okrag.srodek.y << ") i promieniu " << okrag.promien << endl;
}


int main() {

    Okrag tab1[100];
    Okrag::losuj1(tab1, 100);

    Okrag *tab2 = new Okrag[50];
    Okrag::losuj2(tab2, 50);

    Okrag::zliczPrzeciecia(tab1, tab2,100, 50);

    Punkt tab[3] = {Punkt( 5, 2), Punkt(-9, -9), Punkt(2, 3)};
    Prostokat prostokat(Punkt(-8, -6), 13, 10);
    Prostokat::czyWspolne(tab, prostokat);

    wypisz(Okrag(Punkt(6, 1), 8));
    wypisz(Prostokat(Punkt(21, 3), 0, 7));
    wypisz(Punkt(9, 6));


    delete[] tab2;
    return 0;
}
