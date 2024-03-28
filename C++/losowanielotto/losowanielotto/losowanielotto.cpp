#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int liczba;

int main()
{
	cout << "Witaj w losowaniu! Za 3 sekundy nastapi zwolnienie blokady\n";
	Sleep(3000);

	srand(time(NULL));
	for (int i = 0; i < 6; i++) 
	{
		liczba = rand() % 49 + 1;
		cout << "\a" << liczba << endl;
		Sleep(1000);
	}
	getchar();
	return 0;
}
