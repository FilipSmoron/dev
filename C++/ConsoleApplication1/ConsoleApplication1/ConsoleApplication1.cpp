#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
	double b{};
	int k;
	double t{};
	int d;
	int i=1;
	cout << "kwota" << endl;
	cin >> k;
	cout << "dni" << endl;
	cin >> d;
	while (i<=d)
	{
		if (d%2==0)
		{
			t =t+k;
		}
		else
		{
			b =b+k;
		}

		k = k * 1, 07;
		i++;
	}
	cout << b << endl;
	cout << t << endl;
}