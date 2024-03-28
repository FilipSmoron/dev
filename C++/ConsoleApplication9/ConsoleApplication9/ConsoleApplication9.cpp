#include <iostream>
#include<string>
using namespace std;

class Student
{
private:
    string IMIE, KIERUNEK, NAZWISKO;
    int ROK = 0;
public:
    //settery i gettery (IMIE, NAZWISKO, KIERUNEK, ROK)

    void setIMIE(string IMIE1)
    {
        IMIE = IMIE1;
    }
    string getIMIE()
    {
        return IMIE;
    }
    void setNAZWISKO(string NAZWISKO1)
    {
        NAZWISKO = NAZWISKO1;
    }
    string getNAZWISKO()
    {
        return NAZWISKO;
    }
    void setKIERUNEK(string KIERUNEK1)
    {
        KIERUNEK = KIERUNEK1;
    }
    string getKIERUNEK()
    {
        return KIERUNEK;
    }
    void setROK(int ROK1)
    {
        ROK = ROK1;
    }
    int getROK()
    {
        return ROK;
    }


};
//klasa Grupa (numer grupy, limit miejsc, ID)
class Grupa
{
private:
    int numerGrupy = 0;
    const int limitMiejsc = 10;
    Student tab[10] = {};
    int ID = 0;

public:

    int getlimitMiejsc()
    {
        return limitMiejsc;
    }
    int getID()
    {
        return ID;
    }
    void setnumerGrupy(int numerGrupy1)
    {
        numerGrupy = numerGrupy1;
    }
    int getnumerGrupy()
    {
        return numerGrupy;
    }
    void dodajStudenta(Student student)
    {
        if (ID <= limitMiejsc)
        {
            tab[ID] = student;
            cout << "Student zostal dodany do grupy." << endl;
        }
        else
        {
            cout << "Limit miejsc w grupie." << endl;
        }
        ID++;
    }

    //funkcja przepisywania studentow
    void przepiszStudenta(Grupa* grupa, string IMIE, string NAZWISKO)
    {

        Student* NewStudent = new Student;
        string IMIE2, NAZWISKO2, KIERUNEK2;
        int ROK2 = 0;

        for (int i = 0; i < 10; i++) {
            int s1 = IMIE.compare(tab[i].getIMIE());
            int s2 = NAZWISKO.compare(tab[i].getNAZWISKO());


            if (s1 == 0 && s2 == 0) {

                IMIE2 = tab[i].getIMIE();
                NAZWISKO2 = tab[i].getNAZWISKO();
                KIERUNEK2 = tab[i].getKIERUNEK();
                ROK2 = tab[i].getROK();
                tab[i] = {};
                Student* NewStudent = new Student;
                NewStudent->setIMIE(IMIE2);
                NewStudent->setNAZWISKO(NAZWISKO2);
                NewStudent->setKIERUNEK(KIERUNEK2);
                NewStudent->setROK(ROK2);
                grupa->dodajStudenta(*NewStudent);

            }
        }

    }
    //funkcja wypisywania
    void wypisz()
    {
        cout << endl << endl << "Dane " << numerGrupy << " grupy" << endl << endl;
        cout << "Nr grupy: " << numerGrupy << endl;
        cout << "Limit miejsc grupy: " << limitMiejsc << endl;

        for (int i = 0; i <= ID - 1; i++)
        {
            cout << "Student " << i + 1 << ":" << endl;
            cout << tab[i].getIMIE() << endl;
            cout << tab[i].getNAZWISKO() << endl;
            cout << tab[i].getKIERUNEK() << endl;
            cout << tab[i].getROK() << endl;
        }
    }
};

int main()
{

    Student* student1 = new Student;
    Student* student2 = new Student;

    Grupa grupa1;
    Grupa grupa2;

    //Nadanie wartości, settery
    student1->setIMIE("Filip");
    student1->setNAZWISKO("Smoron");
    student1->setKIERUNEK("Informatyka Techniczna");
    student1->setROK(1);
    student2->setIMIE("Mariusz");
    student2->setNAZWISKO("Tabor");
    student2->setKIERUNEK("Psychologia");
    student2->setROK(2);


    Student tablica[2] = { *student1,*student2 };

    //Wypisanie wartości (dane studentów), gettery
    for (int i = 0; i < 2; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << tablica[i].getIMIE() << endl;
        cout << tablica[i].getNAZWISKO() << endl;
        cout << tablica[i].getKIERUNEK() << endl;
        cout << tablica[i].getROK() << endl;
    }

    grupa1.setnumerGrupy(1);
    grupa2.setnumerGrupy(2);
    grupa1.dodajStudenta(*student1);
    grupa1.dodajStudenta(*student2);
    grupa1.wypisz();
    grupa1.przepiszStudenta(&grupa2, "Filip", "Smoron");
    grupa1.wypisz();
    grupa2.wypisz();

    delete student1, student2;
}