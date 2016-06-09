#ifndef GRACZ_H
#define GRACZ_H
#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;

class Gracz
{
    public:
        Gracz();
        void dodajgracza();
        void info();
        void menuGry();
        void konto();
        virtual ~Gracz();
    protected:
    private:
        string imie, nazwisko, plec;
        unsigned int wiek;
};

#endif // GRACZ_H
