#ifndef BLACKJACK_H
#define BLACKJACK_H


class Blackjack
{
    public:
        Blackjack();
        void Karty();
        void Menu();
        bool sprawdzanie();
        void ustawStawke();
        virtual ~Blackjack();
    protected:
    private:
        unsigned int stawka = 5;
};

#endif // BLACKJACK_H
