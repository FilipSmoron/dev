#include <iostream>
using namespace std;

int main()
{
	float dni, kwota , procent, bartek = 0, tomek = 0;
	cout << "liczba dni: " << endl;
	cin >> dni;
	cout << "kwota: " << endl;
	cin >> kwota;
	cout << "procent wzrostu: " << endl;
	cin >> procent;

	for (auto i = 1; i <= dni; i++)
	{
		cout << "kwota w " << i << " dzien: " << kwota << endl;
		if (i % 2 == 0)
		{
			bartek += kwota;
		}
		else
		{
			tomek += kwota;
		}
		kwota = kwota + procent / 100;
	}
	cout << "saldo bartka to: " << bartek << endl;
	cout << "saldo tomka to: " << tomek;
}