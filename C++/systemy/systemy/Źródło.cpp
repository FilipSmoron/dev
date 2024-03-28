# include <iostream>    
using namespace std;
int main()
{
    for (;;)
    {
        cout << "Zamiana liczb pomiedzy dziesietnym, a innymi systemami" << endl << endl;
        int tab[1] = { 0 };
        int ile = 0;
        int x, y;
        cout << "Podaj liczbe w systemie dziesietnym, ktora chcesz zamienic:";
        cin >> x;
        cout << "Na jaki system chcesz zamienic?\n 2 - dwojkowy\n 3 - trojkowy\n 5 - piatkowy\n 6 - szostkowy\n 7 - siodemkowy\n 8 - osemkowy\n 9 - dziewiatkowy\n 11 - jedenastkowy\n 13 - trzynastkowy\n 16 - szesnastkowy\n 20 - dwudziestkowy\n";
        cin >> y;
        if (y == 16)
        {
            cout << "Wartosc w systemie szesnastkowym:\n";
            cout << hex << x;
            cout << " \n";




        }

        else if (y != 16);
        {
            while (x > 0)
            {
                tab[ile] = x % y;
                x /= y;
                ile++;
            }
            for (int i = ile - 1; i >= 0; i--) cout << tab[i];
            cout << endl;

            cin >> x;
            return 0;
        }
    }
}