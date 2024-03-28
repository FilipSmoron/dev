#include <iostream>
#include <string>

using namespace std;

class Osoba {
protected:
    string imie;
    string nazwisko;
    int rok_urodzenia;
//    friend Osoba** filtrujOsoby(Osoba** osoby, int n);
public:
    Osoba(string i, string n, int r) {
        imie = i;
        nazwisko = n;
        rok_urodzenia = r;
    }
    virtual void wyswietl() {
        cout << "Imie: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Rok urodzenia: " << rok_urodzenia << endl;
    }
};

class Student : public Osoba {
private:
    string kierunek;
    int rok_studiow;
public:
    Student(string i, string n, int r, string k, int rs) : Osoba(i, n, r) {
        kierunek = k;
        rok_studiow = rs;
    }
    void wyswietl() {
        Osoba::wyswietl();
        cout << "Kierunek: " << kierunek << endl;
        cout << "Rok studiow: " << rok_studiow << endl;
    }
};

class Pracownik : public Osoba {
private:
    string miejsce_pracy;
    string zawod;
public:
    Pracownik(string i, string n, int r, string mp, string z) : Osoba(i, n, r) {
        miejsce_pracy = mp;
        zawod = z;
    }
    Pracownik(const Pracownik& p) : Osoba(p.imie, "Kowal", 1982) {
        miejsce_pracy = p.miejsce_pracy;
        zawod = p.zawod;
    }
    void wyswietl() {
        Osoba::wyswietl();
        cout << "Miejsce pracy: " << miejsce_pracy << endl;
        cout << "Zawod: " << zawod << endl;
    }

};

/*Osoba** filtrujOsoby(Osoba** osoby, int n) {
}*/
int main() {

    Osoba *osoba = new Osoba("Jan", "Kowalczyk", 1987);
    osoba->wyswietl();
    cout << endl;

    Student student("Michal", "Kowalski", 2003, "Informatyka techniczna", 1);
    student.wyswietl();
    cout << endl;

    Pracownik pracownik1("Anna", "Zawadzka", 1989, "Firma Lotus", "Programistka");
    Pracownik pracownik2 = pracownik1;
    pracownik2.wyswietl();
    cout << endl;

    Osoba *tablica[4];
    tablica[0] = osoba;
    tablica[1] = &student;
    tablica[2] = &pracownik1;
    tablica[3] = &pracownik2;

    for (int i = 0; i < 4; i++) {
        tablica[i]->wyswietl();
        cout << endl;
    }

 delete osoba;

    return 0;
}