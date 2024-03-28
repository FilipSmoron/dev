#include <iostream>


using namespace std;

// definicja przestrzeni nazw
namespace MojaPrzestrzenNazw {
    // definicja klasy Ksiazka
    class Ksiazka {
    private:
        string tytuł;
        string autor;
        int rok_wydania;
        static int licznik;
    public:
        Ksiazka() {
            cout << "Ksiazka zostaza utworzona." << endl;
            licznik++;
        }
        bool czyXXwiek() {
            return (rok_wydania >= 1900 && rok_wydania <= 1999);
        }
        // metody dostępowe do pól prywatnych
        void setTytuł(string t) { tytuł = t; }
        void setAutor(string a) { autor = a; }
        void setRokWydania(int r) { rok_wydania = r; }
        string getTytuł() const { return tytuł; }
        string getAutor() const { return autor; }
        int getRokWydania() const { return rok_wydania; }
        static int getLicznik() { return licznik; }
    };

    // inicjalizacja pola statycznego
    int Ksiazka::licznik = 0;
}

int main() {
    // tworzenie obiektów klasy Ksiazka i umieszczanie ich w tablicy
    MojaPrzestrzenNazw::Ksiazka książki[4];
    książki[0].setTytuł("Wladca Pierscieni");
    książki[0].setAutor("J.R.R. Tolkien");
    książki[0].setRokWydania(1954);
    książki[1].setTytuł("Harry Potter i Kamien Filozoficzny");
    książki[1].setAutor("J.K. Rowling");
    książki[1].setRokWydania(1997);
    książki[2].setTytuł("Lalka");
    książki[2].setAutor("Boleslaw Prus");
    książki[2].setRokWydania(1890);
    książki[3].setTytuł("Folwark zwierzecy");
    książki[3].setAutor("George Orwell");
    książki[3].setRokWydania(1945);

    // wyświetlanie danych utworzonych książek
    for (int i = 0; i < 4; i++) {
        cout << "Ksiazka " << i + 1 << ":" << endl;
        cout << "Tytul: " << książki[i].getTytuł() << endl;
        cout << "Autor: " << książki[i].getAutor() << endl;
        cout << "Rok wydania: " << książki[i].getRokWydania() << endl;
    }
}