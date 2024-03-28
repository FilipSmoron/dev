#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string imie;
    string nazwisko;
    string kierunek;
    int rok;
public:
    string getImie() {
        return imie;
    }
    string getNazwisko() {
        return nazwisko;
    }
    string getKierunek() {
        return kierunek;
    }
    int getRok() {
        return rok;
    }
    void setImie(string imie) {
        this->imie = imie;
    }
    void setNazwisko(string nazwisko) {
        this->nazwisko = nazwisko;
    }
    void setKierunek(string kierunek) {
        this->kierunek = kierunek;
    }void setRok(int rok) {
        this->rok = rok;
    }
};
class Grupa {
private:
    int numerGrupy;
    const int iloscMiejsc = 10;
    Student* studenci = new Student[iloscMiejsc];
public:
    int getnumerGrupy() {
        return numerGrupy;
    }
    int getiloscMiejsc() {
        return iloscMiejsc;
    }
    Student* getStudenci() {
        return this->studenci;
    }
    void setNumerGrupy(int numerGrupy) {
        this->numerGrupy = numerGrupy;
    }
    void wypisz() {
        cout << "Numer Grupy: " << numerGrupy << endl;
        for (int i = 0; i < iloscMiejsc; ++i) {
            cout << "Imie: " << studenci[i].getImie() << endl;
            cout << "Nazwisko: " << studenci[i].getNazwisko() << endl;
            cout << "Kierunek: " << studenci[i].getKierunek() << endl;
            cout << "Rok: " << studenci[i].getRok() << endl;
        }
    }
    void dodajStudentow(Student tabStudentow[]) {
        for (int i = 0; i < iloscMiejsc; ++i) {
            studenci[i] = tabStudentow[i];
        }

    }
    void zmienRok(int i, int w) {
        studenci[i].setRok(w);

    }
};
int main() {
    Student a;
    a.setNazwisko("Debowski");
    cout << a.getNazwisko() << endl;
    Student* tabP = new Student[10];
    string imie;
    string nazwisko;
    string kierunek;


    Grupa b;
    b.dodajStudentow(tabP);
    b.zmienRok(10, 24);
    b.wypisz();

    delete[]tabP;


    return 0;
}