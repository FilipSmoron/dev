#include <iostream>

using namespace std;

class Samochod
{
    private:
    string marka;
    string model;
    int rocznik;
    int przebieg;

    public:
    void wczytaj()
    {
        cout << "Podaj marke: " << endl;
        cin >> marka;
        cout << "Podaj model: " << endl;
        cin >> model;
        cout << "Podaj rocznik: " << endl;
        cin >> rocznik;
        cout << "Podaj przebieg: " << endl;
        cin >> przebieg;

    }
    void wypisz()
    {
        cout <<"Marka: " << marka << ". Model: " << model << ". Rocznik: " << rocznik << ". Przebieg: " << przebieg <<endl;
    }
};

int main()
{
    Samochod s1;
    s1.wczytaj();
    s1.wypisz();
    Samochod s2;
    s2.wczytaj();
    s2.wypisz();
}
