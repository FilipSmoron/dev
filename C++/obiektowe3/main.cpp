#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
class Bohater;
class Przedmiot {
private:
    string nazwa;
    int atak;
    int obrona;
public:
    Przedmiot() {
    nazwa = "";
    atak = 0;
    obrona = 0;
}
    Przedmiot(string nazwa) : nazwa(nazwa) {
        atak = rand() % 101 + 100;
        obrona = rand() % 101;
    }

    int getAtak() {
        return atak;
    }

    int getObrona() {
        return obrona;
    }

    string getNazwa() {
        return nazwa;
    }
friend void pojedynek(Bohater& bohater1, Bohater& bohater2);
};

class Bohater {
private:
    string pseudonim;
    string klasa;
    int punktyZycia;
    Przedmiot ekwipunek[4];
public:
    Bohater() {
        cout << "Utworzona konstruktor domyslny" << endl;
        punktyZycia = 1200;
        pseudonim = "Domyslny";
        klasa = "Wojownik";
        ekwipunek[0] = Przedmiot("Topor");
        ekwipunek[1] = Przedmiot("Tarcza");
        ekwipunek[2] = Przedmiot("Zbroja");
        ekwipunek[3] = Przedmiot("Helm");
    }

    Bohater(string pseudonim1, string klasa1, int punktyZycia1) {
        cout << "Utworzona konstruktor wieloargumentowy" << endl << endl;
        pseudonim = pseudonim1;
        klasa = klasa1;
        punktyZycia = punktyZycia1;
        ekwipunek[0] = Przedmiot("Kusza");
        ekwipunek[1] = Przedmiot("Belty");
        ekwipunek[2] = Przedmiot("Szata");
        ekwipunek[3] = Przedmiot("Peleryna");
    }

    void wypisz()  {
        cout << "Bohater: " << pseudonim << endl;
        cout << "Klasa: " << klasa << endl;
        cout << "Punkty zycia: " << punktyZycia << endl;
        cout << "Ekwipunek:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << ekwipunek[i].getNazwa() << ":" << endl;
            cout << "Atak: " << ekwipunek[i].getAtak() << endl;
            cout << "Obrona: " << ekwipunek[i].getObrona() << endl;
        }
        cout << endl;
    }
friend void pojedynek(Bohater& bohater1, Bohater& bohater2);
};

void pojedynek(Bohater& bohater1, Bohater& bohater2) {
    cout << "Rozpoczecie pojedynku bohatera: " << bohater1.pseudonim << " oraz bohatera: " << bohater2.pseudonim << endl;
    Sleep(2000);
    int punktyZycia1 = bohater1.punktyZycia;
    int punktyZycia2 = bohater2.punktyZycia;

    // Sumy ataku i sumy obrony kazdego bohatera
    int sumaAtaku1 = 0;
    int sumaAtaku2 = 0;
    int sumaObrony1 = 0;
    int sumaObrony2 = 0;
    for (int i = 0; i < 4; i++) {
        sumaAtaku1 += bohater1.ekwipunek[i].getAtak();
        sumaAtaku2 += bohater2.ekwipunek[i].getAtak();
        sumaObrony1 += bohater1.ekwipunek[i].getObrona();
        sumaObrony2 += bohater2.ekwipunek[i].getObrona();
    }

    // Bohaterzy atakuja sie nawzajem
    int obrazenia1 = sumaAtaku1 - sumaObrony2;
    int obrazenia2 = sumaAtaku2 - sumaObrony1;

        punktyZycia2 -= obrazenia1;
        punktyZycia1 -= obrazenia2;

    // Wyœwietlenie wyniku
    if (punktyZycia1 > punktyZycia2) {
        cout << "Zwyciezca jest " << bohater1.pseudonim << "." << endl;
        cout << "Pozostale punkty zycia bohatera " << bohater1.pseudonim << ": " << punktyZycia1 << endl;
        cout << "Pozostale punkty zycia bohatera " << bohater2.pseudonim << ": " << punktyZycia2 << endl;
    } else {
        cout << "Zwyciezca jest " << bohater2.pseudonim << "." << endl;
        cout << "Pozostale punkty zycia bohatera " << bohater2.pseudonim << ": " << punktyZycia2 << endl;
        cout << "Pozostale punkty zycia bohatera " << bohater1.pseudonim << ": " << punktyZycia1 << endl;
    }
}

int main() {
    srand(time(NULL));
    Bohater bohater1;
    Bohater bohater2("Elrond", "Strzelec", 1000);
    bohater1.wypisz();
    bohater2.wypisz();
    pojedynek(bohater1, bohater2);
    return 0;
}
