#include<iostream>
#include<string>
using namespace std;
/*
Szyfr Cezara
Przesuniêcie=13
Spacja w ASCII =32
A=65
Z=90
*/
void szyfrowanie()//a
{
    cout << "Wpisz co chcesz zaszyfrowac: ";
    string x;
    getline(cin, x);

    //cout << x;
    for (int i = 0; i <= x.length(); i++)
    {
        if (int(x[i]) != 32)
        {
            x[i] = char(65 + (x[i] - 65 + 26 + 13) % 26);

        }
        /*  else
          {
              x[i] = char(65 + (x[i] - 62) % 26);
          }
          */
    }
    cout << "Po zaszyforwaniu: \n" << x << endl;
}

void deszyfrowanie()//b
{
    cout << "\nKod to FGHQVHWR VASBEZNGLXR GRPUAVPMAN\n\n";
    string y = "FGHQVHRR VASBEZNGLXR GRPUAVPMAN";

    for (int i = 0; i <= y.length(); i++)
    {
        if (int(y[i]) != 32)
        {
            y[i] = char(65 + (y[i] - 65 + 26 + 13) % 26);

        }

    }
    cout << "\nPo odszyforwaniu: \n" << y << endl;
}


int main()
{
    szyfrowanie();//a
    deszyfrowanie();//b

    return 0;
}