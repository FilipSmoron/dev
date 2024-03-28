#include <iostream>


using namespace std;


class Produkt{
private:
    string nazwa;
    double cena;
    friend void zadanie4();
};

void zadanie1(){
    for(int i = 300; i <= 1200; i++){
        if(i % 2 != 0){
            cout << i << " ";
        }
        if(i % 100 == 0){
            cout << "*** ";
        }
        if(i % 400 == 0){
            cout << endl;
        }
    }
}

void zadanie2(){
    int A[10];
    int *B;
    int ujemne = 0;
    int pominiete = 0;
    for(int i = 0; i < 10; i++){
        cout << "Podaj liczbe: ";
        cin >> A[i];
        if(A[i] < 0){
            ujemne++;
        }
    }
    B = new int[ujemne];
    for(int i = 0; i < 10; i++){
        if(A[i] < 0){
            B[i] = A[i];
        }else{
            pominiete++;
        }
    }
    cout << "Liczby ujemne: ";
    for(int i = 0; i < ujemne; i++){
        cout << B[i] << " ";
    }
    cout << endl;
    cout << "Liczb ujemnych: " << ujemne << endl;
    cout << "Liczb pominiete: " << pominiete << endl;
    delete [] B;
}

void zadanie3(double km){
    double mile_lad = km * 0.621371;
    double mile_mor = km * 0.539957;
    cout << "Mile ladowe: " << mile_lad << endl;
    cout << "Mile morskie: " << mile_mor << endl;
}

void zadanie4(){
    Produkt produkty[10];
    for(int i = 0; i < 10; i++){
        cout << "Podaj nazwe produktu: ";
        cin >> produkty[i].nazwa;
        cout << "Podaj cene produktu: ";
        cin >> produkty[i].cena;
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 9; j++){
            if(produkty[j].cena < produkty[j+1].cena){
                swap(produkty[j], produkty[j+1]);
            }
        }
    }
    cout << "Posortowane produkty: " << endl;
    for(int i = 0; i < 10; i++){
        cout << produkty[i].nazwa << " " << produkty[i].cena << endl;
    }
}


int main() {
//    zadanie1();
//    zadanie2();
//    double km;
//    cout << "Podaj odleglosc w kilometrach: ";
//    cin >> km;
//    zadanie3(km);
//    zadanie4();


    return 0;
}
