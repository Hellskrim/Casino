#ifndef BANDYTA_H
#define BANDYTA_H


class Bandyta
{
    public:
        Bandyta();
        void menu();
        void wyswietlBeben();
        void ustawStawke();
        bool sprawdzanie();
        virtual ~Bandyta();
    protected:
    private:
        int beben[3][3];
        unsigned int stawka = 5;
};

#endif // BANDYTA_H
