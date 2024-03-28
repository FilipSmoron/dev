#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
using namespace std;

int main()
{
    cout << "Podaj ilosc odcinkow: ";
    int n;
    cin >> n;

    int punkty_x[2 * n];
    int punkty_y[2 * n];
    float dl_odcinkow(n);

    srand(time(NULL));

    for (int i = 0; i < 2 * n; i++)
    {
        punkty_x[i] = rand() % 40 - 20;
        punkty_y[i] = rand() % 40 - 20;  //losowanie puntkow
    }
    for (int i = 0; i < 2 * n; i += 2)
    {
        cout << punkty_x[i] << " " << punkty_y[i] << endl;
        cout << punkty_x[i + 1] << " " << punkty_y[i + 1] << endl << endl;

    }
    float min_dl = 0;
    int pom = 0;
    for (int i = 0; i < n; i++)
    {
        dl_odcinkow[i] = sqrt(pow((punkty_x[pom + 1] - punkty_x[pom]), 2) + pow((punkty_y[pom + 1] - punkty_y[pom]), 2));


        if (i != 0) {
            if (dl_odcinkow[i] < min_dl)
            {
                min_dl = dl_odcinkow[i];
            }
        }
        else {
            min_dl = dl_odcinkow[i];
        }

        pom += 2;
    }


    for (int j = 0; j < n; j++)
    {
        cout << j + 1 << " odcinek dl: " << dl_odcinkow[j] << endl;
    }
    cout << "\n min dlugosc: " << min_dl;
}