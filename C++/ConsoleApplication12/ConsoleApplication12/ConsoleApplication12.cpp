#include <iostream>
#include <string>

using namespace std;

class Ksiazka {
private:
    string tytul;
    string autor;
    int rok;
    static int licznik;
public:
    Ksiazka() {
        cout << "Ksiazka zostala utworzona." << endl;
        licznik++;
    }

    void setTytul(string tytul1) {
        tytul = tytul1;
    }

    string getTytul() const {
        return tytul;
    }

    void setAutor(string autor1) {
        autor = autor1;
    }

    string getAutor() const {
        return autor;
    }

    void setRok(int rok1) {
        rok = rok1;
    }

    int getRok() const {
        return rok;
    }

    static void setLicznik(int licznik1) {
        licznik = licznik1;
    }

    static int getLicznik() {
        return licznik;
    }

    bool czyXXwiek() const {
        return (rok >= 1901 && rok <= 2000);
    }

    void wypisz() const {
        cout << "Tytul: " << tytul << endl;
        cout << "Autor: " << autor << endl;
        cout << "Rok wydania: " << rok << endl;
    }
};

int Ksiazka::licznik = 0;

int main() {
    Ksiazka k[4];
    k[0].setTytul("W pustyni i w puszczy");
    k[0].setAutor("Henryk Sienkiewicz");
    k[0].setRok(1910);
    k[0].wypisz();
    cout << "Liczba utworzonych ksiazek: " << Ksiazka::getLicznik() << endl;

    k[1].setTytul("Krzyzacy");
    k[1].setAutor("Henryk Sienkiewicz");
    k[1].setRok(1900);
    k[1].wypisz();
    cout << "Liczba utworzonych ksiazek: " << Ksiazka::getLicznik() << endl;

    k[2].setTytul("Lalka");
    k[2].setAutor("Boleslaw Prus");
    k[2].setRok(1889);
    k[2].wypisz();
    cout << "Liczba utworzonych ksiazek: " << Ksiazka::getLicznik() << endl;

    k[3].setTytul("pip");
    k[3].setAutor("ka");
    k[3].setRok(1969);
    k[3].wypisz();
    cout << "Liczba utworzonych ksiazek: " << Ksiazka::getLicznik() << endl;
    return 0;
}