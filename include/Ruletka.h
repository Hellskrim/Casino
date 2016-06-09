#ifndef RULETKA_H
#define RULETKA_H


class Ruletka
{
    public:
        Ruletka();
        virtual ~Ruletka();
        void ustawStawke();
        bool sprawdzanie();
        void Menu();
        void Gra();
    protected:
    private:
        unsigned int stawka = 5;
        int liczba;
};

#endif // RULETKA_H
