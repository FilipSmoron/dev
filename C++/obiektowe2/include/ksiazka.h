#ifndef KSIAZKA_H
#define KSIAZKA_H


class ksiazka
{
    public:
        ksiazka(string nazwa, string autor, int rok_wydania);
        virtual ~ksiazka();

        int Getrok() { return rok; }
        void Setrok(int val) { rok = val; }
        string Getnazwa() { return nazwa; }
        void Setnazwa(string val) { nazwa = val; }
        string Getautor() { return autor; }
        void Setautor(string val) { autor = val; }

    protected:

    private:
        int rok;
        string nazwa;
        string autor;
};

#endif // KSIAZKA_H
