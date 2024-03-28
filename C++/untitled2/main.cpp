#include <iostream>
#include<cmath>
#include<math.h>
#include<cmath>
using namespace std;
static void wypiszdowolny();
class Punkt {
private:
	int x=0;
	int y=0;
	friend  class Prostokat;
	friend class Okrag;
	friend  void wypiszdowolny();



public:
	Punkt(int x1, int y1) :x(x1),y(y1)
	{

	}
	Punkt()
	{

	}

	static void wypiszdowolny(Punkt punkt)
	{
		cout << endl << "Punkt o wspolrzednej (" << punkt.x << "," << punkt.y << ")." << endl;
	}
};

class Prostokat {
private:
	Punkt lewy_dolny_wierzcholek;
	int szerokosc=0;
	int wysokosc=0;
	//friend class Punkt;
	friend class Punkt;
	friend void wypiszdowolny();

public:
	Prostokat()
	{

	}

	Prostokat(Punkt lewy_dolny_wierzcholek1,int szerokosc1,int wysokosc1):lewy_dolny_wierzcholek(lewy_dolny_wierzcholek1),szerokosc(szerokosc1),wysokosc(wysokosc1)
	{

	}
	static void czywspolne(Punkt tablica[],Prostokat prostokat)
	{
		for (int i=0;i<3; i++)
		{
			if (prostokat.szerokosc>sqrt((tablica[i].x-prostokat.lewy_dolny_wierzcholek.x) ^ 2) && prostokat.wysokosc>sqrt((tablica[i].y-prostokat.lewy_dolny_wierzcholek.y ) ^ 2))
			{
				cout << endl << "Punkt ("<< tablica[i].x<<","<< tablica[i].y << ") nalezy do prostokata" << endl;
			}
			else
			{
				cout << endl << "Punkt (" << tablica[i].x << "," << tablica[i].y << ") nie nalezy do prostokata" << endl;
			}
		}
	}
	static void wypiszdowolny(Prostokat prostokat)
	{
		cout << endl << "Prostokat o wspolrzednej lewego dolnego wierzcholka(" << prostokat.lewy_dolny_wierzcholek.x << "," << prostokat.lewy_dolny_wierzcholek.y << ")." << endl;
		cout << "Wysokosc: "<<prostokat.wysokosc<<endl;
		cout << "Szerokosc: " << prostokat.szerokosc << endl;
	}
};

class Okrag {
private:
	Punkt srodek_okregu;
	int promien=0;
	friend void wypiszdowolny();

public:
	Okrag()
	{

	}

	/*Okrag(Punkt srodek_okregu1, int promien1) :srodek_okregu(srodek_okregu1), promien(promien1)
	{

	}*/
	static void setOkregi(Okrag tablica[],int n)
	{
		srand(time(NULL));
		for (int i=0;i<n;i++)
		{
			tablica[i].srodek_okregu.x= rand() % 6;
			tablica[i].srodek_okregu.y= -rand() % 6;
			tablica[i].promien=(rand() % 10)+1;
		}
	}
	static void setOkregidyn(Okrag tablica[], int n)
	{
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			tablica[i].srodek_okregu.x = (-rand() % 16) + 10;
			tablica[i].srodek_okregu.y = (-rand() % 16) + 5;
			tablica[i].promien = (rand() % 15) + 1;
		}
	}

	static void czyPrzecina(Okrag tablica1[],int n,Okrag tablica2[],int m)
	{

		int licznik = 0;
		for (int i=0;i<n;i++)
		{

			for (int j=0;j<m;j++)
			{

				if ((sqrt((tablica2[j].srodek_okregu.x-tablica1[i].srodek_okregu.x) ^ 2 + (tablica2[j].srodek_okregu.y - tablica1[i].srodek_okregu.y) ^ 2)<(tablica1[i].promien+tablica2[j].promien))&&fabs(tablica2[j].promien-tablica1[i].promien< sqrt((tablica2[j].srodek_okregu.x - tablica1[i].srodek_okregu.x) ^ 2 + (tablica2[j].srodek_okregu.y - tablica1[i].srodek_okregu.y) ^ 2)))
				{
					licznik++;
					break;
				}

			}




		}
		cout <<endl<< licznik << " okregow z tablicy pierwszej przecina sie z okregami z tablicy drugiej" << endl;
	}
	static void wypiszdowolny(Okrag okrag)
	{
		cout << endl << "Okrag o srodku o wspolrzednych: (" << okrag.srodek_okregu.x << "," << okrag.srodek_okregu.y << ")." << endl;
		cout << "Promien: " << okrag.promien << endl;

	}
};




int main(void)
{

	//A
	Punkt tablica[3] = { {5,2}, {-9,-9}, {2,3} };
	//B

	Prostokat prostokat1(Punkt( - 8, -6), 13, 10);
	//C
	Prostokat::czywspolne(tablica, prostokat1);
	//D
	Okrag tablica1[100];
	Okrag::setOkregi(tablica1, 100);

	Okrag* tablica2 = new Okrag[50];
	Okrag::setOkregidyn(tablica2, 50);
	//E
	Okrag::czyPrzecina(tablica1, 100, tablica2, 50);
	//F
	Prostokat::wypiszdowolny(prostokat1);
	Punkt::wypiszdowolny(tablica[1]);
	Okrag::wypiszdowolny(tablica2[1]);



	delete[] tablica2;
}