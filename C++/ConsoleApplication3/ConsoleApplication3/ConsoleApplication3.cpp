#include <iostream>
#include <ctime>
using namespace std;

void wagi(int tab[][8])
{

}

void wypisz(int tab[][8]) {

    for (int i = 0; i < 8; i++)
    {
        if (i == 0) {
            for (int k = 0; k < 9; k++) {
                if (k != 0) 
                { cout << "K" << k - 1 << "\t"; }
                else { cout << "\t"; }
            }
        }
        cout << endl;
        cout << "    W" << i << ": ";
        for (int j = 0; j < 8; j++)
        {
            cout << tab[i][j] << "\t";
        }

    }

}
void max_waga(int tab[][8]) {
    int value = 0, a = 0, b = 0; //wierzcholki
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (value < tab[i][j]) {
                value = tab[i][j];
                a = i; b = j;
            }
        }

    }
    cout << endl << "Wierzcholki Z najwiekszymi wagami: (" << a << ") " << " (" << b << ")";
}
int main()
{
    srand(time(NULL));
    int tab[8][8] = { 0 };

    tab[0][2] = 1;
    tab[0][4] = 1;
    tab[1][2] = 1;
    tab[1][3] = 1;
    tab[1][5] = 1;
    tab[2][0] = 1;
    tab[2][1] = 1;
    tab[2][5] = 1;
    tab[3][1] = 1;
    tab[3][4] = 1;
    tab[3][5] = 1;
    tab[3][6] = 1;
    tab[4][0] = 1;
    tab[4][3] = 1;
    tab[4][7] = 1;
    tab[5][1] = 1;
    tab[5][2] = 1;
    tab[5][3] = 1;
    tab[6][3] = 1;
    tab[6][7] = 1;
    tab[7][4] = 1;
    tab[7][6] = 1;

    int r;
    srand(time(NULL));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (tab[i][j] == 1) {
                r = rand() % 21 + 5;
                tab[i][j] = r;
                tab[j][i] = r;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (i == 0) {
            for (int k = 0; k < 9; k++) {
                if (k != 0) 
                { cout << "K" << k - 1 << "\t"; }
                else { cout << "\t"; }
            }
        }
        cout << endl;
        cout << "    W" << i << ": ";
        for (int j = 0; j < 8; j++)
        {
            cout << tab[i][j] << "\t";
        }

    }
    int value = 0, a = 0, b = 0; //wierzcholki
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (value < tab[i][j]) {
                value = tab[i][j];
                a = i; b = j;
            }
        }

    }
    cout << endl << "Wierzcholki z najwiekszymi wagami: (" << a << ") " << " (" << b << ")";
    return 0;
}

