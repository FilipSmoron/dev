#include <iostream>
using namespace std;
struct Student
{
	string imie;
	string nazwisko;
	string kierunek;
	int rok;
	int semestr;
};


int main() {
	Student tab[3];
	cout << "Podaj imie, nazwisko, kierunek, rok i semestr" << endl;
	for (int i = 0; i < 3; i++) {

		cin >> tab[i].imie >> tab[i].nazwisko >> tab[i].rok >> tab[i].semestr;
	}

	cout << tab[0].imie << " " << tab[0].nazwisko << " " << tab[0].kierunek << " " << tab[0].semestr << " " << tab[0].rok << endl;

	return 0;
}
