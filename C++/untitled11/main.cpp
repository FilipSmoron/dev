#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Prezydent
{
private:
    string imie;
    string nazwisko;
    int okres_rozpoczecia;
    int okres_zakonczenia;
    string partia;

public:
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    string getPartia() { return partia; }
    int getOkresRozpoczecia() { return okres_rozpoczecia; }
    int getOkresZakonczenia() { return okres_zakonczenia; }
    void setImie(string _imie) { imie = _imie; }
    void setNazwisko(string _nazwisko) { nazwisko = _nazwisko; }
    void setPartia(string _partia) { partia = _partia; }
    void setOkresRozpoczecia(int _okres_rozpoczecia) { okres_rozpoczecia = _okres_rozpoczecia; }
    void setOkresZakonczenia(int _okres_zakonczenia) { okres_zakonczenia = _okres_zakonczenia; }

    Prezydent() {}
};

Prezydent* tab[50]; // tablica wskaźników na prezydentów
int numer = 0; // aktualny rozmiar tablicy

string* split(string s, string delimiter) {
    int pos_start = 0;
    int pos_end;
    int delim_len = delimiter.length();

    string token;
    static string buffer[10];

    int idx = 0;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {

        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;

        buffer[idx] = token;
        idx++;
    }

    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    buffer[idx] = token;

    return buffer;
}

void loadData(string path) {
    string line;
    ifstream myfile("" + path);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            //split the string
            string* buffer = split(line, " ");

            Prezydent* new_prezydent = new Prezydent;
            new_prezydent->setImie(buffer[0]);
            new_prezydent->setNazwisko(buffer[1]);
            new_prezydent->setOkresRozpoczecia(stoi(buffer[2]));
            new_prezydent->setOkresZakonczenia(stoi(buffer[3]));
            new_prezydent->setPartia(buffer[4]);

            tab[numer] = new_prezydent;
            numer++;
        }
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void shortestRule() {
    int min = tab[0]->getOkresZakonczenia() - tab[0]->getOkresRozpoczecia();
    for (int i = 1; i < numer; i++) {
        int okres = tab[i]->getOkresZakonczenia() - tab[i]->getOkresRozpoczecia();
        if (okres < min) {
            min = okres;
        }
    }
    cout << "Najkrocej rzadzacy prezydenci (rzadzil(i) " << min + 1 << " lat):" << endl;
    for (int i = 0; i < numer; i++) {
        int okres = tab[i]->getOkresZakonczenia() - tab[i]->getOkresRozpoczecia();
        if (okres == min) {
            cout << tab[i]->getImie() << " " << tab[i]->getNazwisko() << endl;
        }
    }
}

void getByParty(string party) {
    cout << "Prezydenci z partii " << party << ":" << endl;
    for (int i = 0; i < numer; i++) {
        if (tab[i]->getPartia().compare(party) == 0) {
            cout << tab[i]->getImie() << " " << tab[i]->getNazwisko() << endl;
        }
    }
}


void getByYear(int year) {
    bool found = false;
    for (int i = 0; i < numer; i++) {
        if (tab[i]->getOkresRozpoczecia() <= year && tab[i]->getOkresZakonczenia() >= year) {
            cout << "Prezydent rzadzacy w roku " << year << ": " << tab[i]->getImie() << " " << tab[i]->getNazwisko() << endl;
            found = true;
        }
    }
    if (found = false) {
        cout << "Brak prezydenta rządzącego w roku " << year << endl;
    }
}

int main() {
    cout << "_____________LISTA PREZYDENTOW__________________" << endl;
    loadData("presidents.txt");
    shortestRule();
    getByParty("Unaffiliated");
    getByYear(1849);

//    cout << "_____________DANE PREZYDENTOW__________________" << endl;
//      for (int i = 0; i < numer; i++)
//    cout << tab[i]->getImie() << " " << tab[i]->getNazwisko() << " " << tab[i]->getOkresRozpoczecia() << " " << tab[i]->getOkresZakonczenia() << " " << tab[i]->getPartia() << endl;
//    for (int i = 0; i < numer; i++) {
//        delete tab[i];
//    }
//      delete[] *tab;
    return 0;
}
