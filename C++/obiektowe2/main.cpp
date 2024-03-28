#include <iostream>
#include <algorithm>

using namespace std;


//przestrzeń nazw
namespace MojaPrzestrzenNazw
{

    class Ksiazka
    {
    private:
        string tytul;
        string autor;
        int rok_wydania;
        static int licznik;
    public:
            //konstruktor domyślny
            Ksiazka()
        {
            cout << "Ksiazka " << licznik + 1 << " zostala utworzona." << endl;
            licznik++;
        }

        //metoda sprawdzająca czy książka została wydana w wieku XX
        void czyXXwiek()
        {
            if(rok_wydania >= 1901 && rok_wydania <= 2000)
                cout<<"Ksiazka zostala wydana w XX wieku!"<<endl << endl;
            else
                cout<<"Ksiazka nie zostala wydana w XX wieku!"<<endl << endl;
        }
        //dostep do pól prywatnych
        void setTytul(string t)
        {
            tytul = t;
        }
        void setAutor(string a)
        {
            autor = a;
        }
        void setRokWydania(int r)
        {
            rok_wydania = r;
        }
        string getTytul()
        {
            return tytul;
        }
        string getAutor()
        {
            return autor;
        }
        int getRokWydania()
        {
            return rok_wydania;
        }
        static int getLicznik()
        {
            return licznik;
        }

    };

//funkcje globalne porównywania dat wydania książek oraz sortowania
    bool porownajKsiazki( Ksiazka k1,  Ksiazka k2)
    {
        return k1.getRokWydania() > k2.getRokWydania();
    }

    void Sortowanie(Ksiazka* ksiazki, int i)
    {
        sort(ksiazki, ksiazki + i, porownajKsiazki);
    }

    // inicjalizacja pola statycznego
    int Ksiazka::licznik = 0;
}

int main() {
    //tworzenie obiektu ks1
    MojaPrzestrzenNazw::Ksiazka ks1;
    ks1.setAutor("Mojang");
    ks1.setTytul("Minecraft. Poradnik uzytkownikow czerwonego kamienia ");
    ks1.setRokWydania(2014);
    //tworzenie i umieszczenie obiektów klasy w tablicy
    MojaPrzestrzenNazw::Ksiazka ksiazki[4];
    ksiazki[0].setTytul("Hobbit, czyli tam i z powrotem");
    ksiazki[0].setAutor("J.R.R. Tolkien");
    ksiazki[0].setRokWydania(1937);
    ksiazki[1].setTytul("Symfonia C++ standard");
    ksiazki[1].setAutor("Jerzy Grebosz");
    ksiazki[1].setRokWydania(2005);
    ksiazki[2].setTytul("Lalka");
    ksiazki[2].setAutor("Boleslaw Prus");
    ksiazki[2].setRokWydania(1890);
    ksiazki[3].setTytul("Rok 1984");
    ksiazki[3].setAutor("George Orwell");
    ksiazki[3].setRokWydania(1949);

            cout << endl << "Ksiazka 1:" << endl;
            cout << "Tytul: " << ks1.getTytul() << endl;
            cout << "Autor: " << ks1.getAutor() << endl;
            cout << "Rok wydania: " << ks1.getRokWydania() << endl;
            ks1.czyXXwiek();
    //wypisywanie elementów tablicy
    for (int i = 0; i < 4; i++)
        {
            cout << endl << "Ksiazka " << i + 2 << ":" << endl;
            cout << "Tytul: " << ksiazki[i].getTytul() << endl;
            cout << "Autor: " << ksiazki[i].getAutor() << endl;
            cout << "Rok wydania: " << ksiazki[i].getRokWydania() << endl;
            ksiazki[i].czyXXwiek();
        }

    cout<<"Po posortowaniu tablicy"<<endl;
    MojaPrzestrzenNazw::Sortowanie(ksiazki, 4);

        for (int i = 0; i < 4; i++)
        {
            cout << endl << "Ksiazka " << i + 2 << ":" << endl;
            cout << "Tytul: " << ksiazki[i].getTytul() << endl;
            cout << "Autor: " << ksiazki[i].getAutor() << endl;
            cout << "Rok wydania: " << ksiazki[i].getRokWydania() << endl;
            ksiazki[i].czyXXwiek();
        }

        cout << endl << "Liczba wszystkich ksiazek: " << MojaPrzestrzenNazw::Ksiazka::getLicznik() << endl;
    }
