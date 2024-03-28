#include <iostream>
using namespace std;
class Pasazer
        {
        private:
            string imie;
            string nazwisko;
            int rok_urodzenia;
            static int licznik;
        public:
            string getImie() { return imie; }
            string getNazwisko() { return nazwisko; }
            int getRok_urodzenia() { return rok_urodzenia; }
            static int getLicznik() { return licznik; }
            void setImie(string imie) { this->imie = imie; }
            void setNazwisko(string nazwisko) { this->nazwisko = nazwisko; }
            void setRok_urodzenia(int rok_urodzenia) { this->rok_urodzenia = rok_urodzenia; }
            void setLicznik(int licznik) { this->licznik = licznik; }
            Pasazer(string imie, string nazwisko, int rok_urodzenia)
            {
                this->imie = imie;
                this->nazwisko = nazwisko;
                this->rok_urodzenia = rok_urodzenia;
                licznik++;
            }
            Pasazer()
            {
                this->imie = "Jan";
                this->nazwisko = "Kowalski";
                this->rok_urodzenia = 1990;
                licznik++;
            }
            Pasazer(const Pasazer &p)
            {
                this->imie = p.imie;
                this->nazwisko = p.nazwisko;
                this->rok_urodzenia = p.rok_urodzenia;
                licznik++;
            }
            ~Pasazer()
            {
                licznik--;
            }
    void wypisz()
    {
        if (rok_urodzenia == NULL || nazwisko == " " || imie==" ")
        {cout << " ";}
        else {
            cout << endl << "Imie: " << imie << endl;
            cout << "Nazwisko: " << nazwisko << endl;
            cout << "Rok urodzenia: " << rok_urodzenia << endl << endl;
        }

    }


        };
class Autokar
        {
        private:
            string miejsceDocelowe;
            int predkoscMaksymalna;
            const static int iloscMiejsc=20;
            int liczbaPasazerow;
            Pasazer *tab[iloscMiejsc];
        public:
            Autokar(const Autokar &p)
            {
                this->miejsceDocelowe = p.miejsceDocelowe;
                this->predkoscMaksymalna = p.predkoscMaksymalna;
                this->liczbaPasazerow = p.liczbaPasazerow;
                for (int i = 0; i < iloscMiejsc; i++)
                {
                    this->tab[i] = p.tab[i];
                }

            }
            Autokar()
            {
             miejsceDocelowe = "Krakow";
                predkoscMaksymalna = 100;
                liczbaPasazerow = 0;
                for (int i = 0; i < iloscMiejsc; i++)
                {
                    tab[i] = NULL;
                }
            }
            Autokar(string miejsceDocelowe, int predkoscMaksymalna)
            {
                this->miejsceDocelowe = miejsceDocelowe;
                this->predkoscMaksymalna = predkoscMaksymalna;
                liczbaPasazerow = 0;
                for (int i = 0; i < iloscMiejsc; i++)
                {
                    tab[i] = NULL;
                }
            }
            ~Autokar()
            {

            }
            string getMiejsceDocelowe() { return miejsceDocelowe; }
            int getPredkoscMaksymalna() { return predkoscMaksymalna; }
            void setMiejsceDocelowe(string miejsceDocelowe) { this->miejsceDocelowe = miejsceDocelowe; }
            void setPredkoscMaksymalna(int predkoscMaksymalna) { this->predkoscMaksymalna = predkoscMaksymalna; }
            int getLiczbaPasazerow() { return liczbaPasazerow; }
            void setLiczbaPasazerow(int liczbaPasazerow) { this->liczbaPasazerow = liczbaPasazerow; }
    void dodajPasazera(Pasazer *a)
    {
        if(liczbaPasazerow<iloscMiejsc)
        {
            tab[liczbaPasazerow] = a;
            liczbaPasazerow++;
        }
        else
        {
            cout << "Brak miejsca w autokarze" << endl;
        }
    }

    void wypisz()
    {
        cout << "Miejsce docelowe: " << miejsceDocelowe << endl;
        cout << "Predkosc maksymalna: " << predkoscMaksymalna << endl;
        cout << "Liczba miejsc: " << iloscMiejsc << endl;
        cout << "Liczba pasazerow: " << liczbaPasazerow << endl;
        for (int i = 0; i < 20; ++i)
        {
            if (tab[i] != nullptr)
                tab[i]->wypisz();
        }
    }

    void setPassengerToNull(int i)
    {
        this->tab[i] = nullptr;
        this->liczbaPasazerow--;
    }


};
int Pasazer::licznik = 0;



int main() {

Pasazer p1;
Pasazer p2("Anna", "Kowalska", 1980);
Pasazer p3(p2);
cout << p1.getImie() << " " << p1.getNazwisko() << " " << p1.getRok_urodzenia() << endl;
cout << p2.getImie() << " " << p2.getNazwisko() << " " << p2.getRok_urodzenia() << endl;
cout << p3.getImie() << " " << p3.getNazwisko() << " " << p3.getRok_urodzenia() << endl;
Pasazer ** tab = new Pasazer*[100];
    for (int i = 0; i < 100; ++i) {
        tab[i] = new Pasazer("Pasazer", "Jakies", 1989);
    }
cout <<"Ilosc Pasazerow: "<< Pasazer::getLicznik()<<endl;
Autokar a1;
a1.dodajPasazera(&p1);
a1.dodajPasazera(&p2);
a1.dodajPasazera(&p3);
int a = a1.getLiczbaPasazerow();
    for (int i = 0; i < 20-a; ++i) {;
        a1.dodajPasazera(tab[i]);
    }
a1.wypisz();
    Autokar a2(a1);
    cout <<endl<<"Autokar 2: "<<endl<<endl;
    a2.setPassengerToNull(0);
    a2.setPassengerToNull(1);
    a2.setPassengerToNull(2);
    a2.wypisz();
    for (int i = 0; i < 100; ++i) {
        delete tab[i];
    }
    delete [] tab;

    cout <<endl << "Liczba utworzonych pasazerow: "<< Pasazer::getLicznik() << endl;


    return 0;
}
