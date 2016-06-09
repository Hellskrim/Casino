#include "Blackjack.h"
#include "cstdlib"
#include <iostream>
#include <vector>
#include <algorithm>
#include <Gracz.h>
#include <time.h>

using namespace std;

extern float kredyt;
Gracz g2;

Blackjack::Blackjack()
{
    //ctor
}

void Blackjack::Menu()
{
    char wybor;
    do
    {
        system("CLS");
        cout
        <<"MENU"<<endl
        <<"1. GRAJ"<<endl
        <<"2. USTAW STAWKE"<<endl
        <<"3. WROC DO MENU GLOW"<<endl<<endl
        <<"TWOJ WYBOR: ";
        cin >> wybor;
    }while(wybor!='1' && wybor!='2' && wybor!='3');

    switch (wybor)
    {
        case '1':
            if(Blackjack::sprawdzanie()) Blackjack::Karty();
            else Blackjack::Menu();
            break;
        case '2':
            if(kredyt==0) {cout<<"\nBrak srodkow na koncie\n"; system("PAUSE"); Blackjack::Menu();}
            else Blackjack::ustawStawke();
            break;
        case '3':
            g2.menuGry();
            break;
    };
}
void Blackjack::Karty()
{
    srand(time(NULL));
    system("CLS");
    vector <int> tab;
    vector <int>::iterator iterat;
    vector <int>::iterator iterat2;
    char wyb;
    kredyt -= stawka;
    for(int i=0; i<52; i++)
    {
        if(i<=3)
            tab.push_back(2);
        if(i>3 && i<=7)
            tab.push_back(3);
        if(i>7 && i<=11)
            tab.push_back(4);
        if(i>11 && i<=15)
            tab.push_back(5);
        if(i>15 && i<=19)
            tab.push_back(6);
        if(i>19 && i<=23)
            tab.push_back(7);
        if(i>23 && i<=27)
            tab.push_back(8);
        if(i>27 && i<=31)
            tab.push_back(9);
        if(i>31 && i<=35)
            tab.push_back(10);
        if(i>35 && i<=39)
            tab.push_back(10);
        if(i>39 && i<=43)
            tab.push_back(10);
        if(i>43 && i<=47)
            tab.push_back(10);
        if(i>47 && i<=51)
            tab.push_back(11);
    }
    random_shuffle(iterat=tab.begin(),iterat2=tab.end());
    vector <int> krupier;
    vector <int> gracz;
    int licznik = 0;
    char zgoda;
    char as;
    cout<<"Twoja pierwsza karta: "<<tab[licznik]<<endl;
    licznik++;
    cout<<"Pierwsza karta krupiera: zakryta"<<endl;
    licznik++;
    cout<<"Twoja druga karta: "<<tab[licznik]<<endl;
    licznik++;
    cout<<"Druga karta krupiera: "<<tab[licznik]<<endl;
    licznik++;

    if(tab[0] == 11)
    {
        do
        {
            cout<<"Masz asa, dobierz wartosc"<<endl;
            cout<<"1. Wartosc 1"<<endl;
            cout<<"2. Wartosc 11"<<endl;
            cin>>as;
        }while(as!='1' && as!='2');
        if(as=='1')
            tab[0]=1;
        if(as=='2')
            tab[0]=11;
    }

    if(tab[2] == 11)
    {
        do
        {
            cout<<"Masz asa, dobierz wartosc"<<endl;
            cout<<"1. Wartosc 1"<<endl;
            cout<<"2. Wartosc 11"<<endl;
            cin>>as;
        }while(as!='1' && as!='2');
        if(as=='1')
            tab[2]=1;
        if(as=='2')
            tab[2]=11;
    }

    do
    {
        cout<<"Co chcesz zrobic?"<<endl
            <<"1. Pass"<<endl
            <<"2. Dobierz"<<endl
            <<"Twoj wybor: ";
        cin >> wyb;

    }while(wyb!='1' && wyb!='2');
    int pomoc_gracz=tab[0]+tab[2];
    int pomoc_krupier=tab[1]+tab[3];
    if(wyb=='1')
    {

        cout<<"Wartosci kart krupiera: "<<tab[1]<<" "<<tab[3]<<endl;
        while(pomoc_krupier<17)
        {
            cout<<"Wartosc dobranej karty krupiera: "<<tab[licznik]<<endl;
            pomoc_krupier+=tab[licznik];
            licznik++;
        };
        cout<<"\nWartosc kart krupiera: "<<pomoc_krupier;
        cout<<"\nWartosc kart gracza: "<<pomoc_gracz;

        if(pomoc_gracz<pomoc_krupier && pomoc_krupier<=21 || pomoc_gracz>21)
            cout<<"\nPrzegrales!";
        if(pomoc_gracz>pomoc_krupier && pomoc_gracz<=21 || pomoc_krupier>21)
        {
            cout<<"\nWygrales!";
            kredyt+=stawka*2;
        }
        if(pomoc_gracz==pomoc_krupier)
        {
            cout<<"\nRemis!";
            kredyt+=stawka;
        }

        cout<<endl;

        system("PAUSE");

        do
        {
            system("CLS");
            cout<<"Chcesz powtorzyc gre?[T/N]:  ";
            cin>>zgoda;
        }while(zgoda!='t' && zgoda!='n');

        if(zgoda=='t')
            {
                if(Blackjack::sprawdzanie()) Blackjack::Karty();
                else Blackjack::Menu();
            }
        else if(zgoda=='n')
            Blackjack::Menu();
    }

    bool dobieram = true;
    char kolejna;
    if(wyb=='2')
    {
        cout<<"Wartosci Twoich kart: "<<tab[0]<<" "<<tab[2]<<endl;
        cout<<"Wartosc dobranej karty: "<<tab[licznik];

        if(tab[licznik] == 11)
        {
            do
            {
                cout<<"Masz asa, dobierz wartosc"<<endl;
                cout<<"1. Wartosc 1"<<endl;
                cout<<"2. Wartosc 11"<<endl;
                cin>>as;
            }while(as!='1' && as!='2');
            if(as=='1')
                tab[licznik]=1;
            if(as=='2')
                tab[licznik]=11;
        }

        pomoc_gracz+=tab[licznik];
        licznik++;
        while(dobieram == true)
        {
            do
            {
                cout<<"\nCzy chcesz dobrac kolejna karte?[T/N]: ";
                cin >> kolejna;
                if(kolejna == 't')
                {
                    dobieram = true;
                    cout<<"Wartosc dobranej karty: "<<tab[licznik]<<endl;
                    if(tab[licznik] == 11)
                    {
                        do
                        {
                            cout<<"/nMasz asa, dobierz wartosc"<<endl;
                            cout<<"1. Wartosc 1"<<endl;
                            cout<<"2. Wartosc 11"<<endl;
                            cin>>as;
                        }while(as!='1' && as!='2');
                        if(as=='1')
                            tab[licznik]=1;
                        if(as=='2')
                            tab[licznik]=11;
                    }
                    pomoc_gracz+=tab[licznik];
                    licznik++;
                    if(pomoc_gracz>21) {dobieram = false; break;}
                }
                if(kolejna == 'n')
                {
                    dobieram = false;
                    break;
                }
            }while(kolejna!='t' && kolejna!='n');

        };
        if(pomoc_gracz<22)
        {
            cout<<"Wartosci kart krupiera: "<<tab[1]<<" "<<tab[3]<<endl;
            while(pomoc_krupier<17)
            {
                cout<<"Wartosc dobranej karty krupiera: "<<tab[licznik]<<endl;
                pomoc_krupier+=tab[licznik];
                licznik++;
            };
            cout<<"\nWartosc kart krupiera: "<<pomoc_krupier;
            cout<<"\nWartosc kart gracza: "<<pomoc_gracz;

            if(pomoc_gracz<pomoc_krupier && pomoc_krupier<=21 || pomoc_gracz>21)
                cout<<"\nPrzegrales!";
            else if(pomoc_gracz>pomoc_krupier && pomoc_gracz<=21 || pomoc_krupier>21)
            {
                cout<<"\nWygrales!";
                kredyt+=stawka*2;
            }
            else if(pomoc_gracz==pomoc_krupier)
            {
                cout<<"\nRemis!";
                kredyt+=stawka;
            }
            cout<<endl;
            system("PAUSE");
            do
            {
                system("CLS");
                cout<<"Chcesz powtorzyc gre?[T/N]:  ";
                cin>>zgoda;
            }while(zgoda!='t' && zgoda!='n');

            if(zgoda=='t')
            {
                if(Blackjack::sprawdzanie()) Blackjack::Karty();
                else Blackjack::Menu();
            }
            else if(zgoda=='n')
                Blackjack::Menu();
        }
        else
        {
            cout<<"Krupier wygral, Twoja wartosc kart: "<<pomoc_gracz<<endl;
            system("PAUSE");
            do
            {
                system("CLS");
                cout<<"Chcesz powtorzyc gre?[T/N]:  ";
                cin>>zgoda;
            }while(zgoda!='t' && zgoda!='n');

            if(zgoda=='t')
            {
                if(Blackjack::sprawdzanie()) Blackjack::Karty();
                else Blackjack::Menu();
            }
            else if(zgoda=='n')
                Blackjack::Menu();
        }

    }
}
void Blackjack::ustawStawke()
{
    do
    {
        system("CLS");
        cout<<"Ustaw swoja stawke do gry: ";
        cin >> stawka;
        if(stawka == 0 || stawka>kredyt) {cout<<"Brak srodkow na koncie"<<endl; system("PAUSE"); }
    }while(stawka == 0 || stawka>kredyt);
        Blackjack::Menu();
}

bool Blackjack::sprawdzanie()
{
    if(kredyt==0 || kredyt<stawka)
    {
        cout<<"Za malo zetonow!\n";
        system("PAUSE");
        return false;
        Blackjack::Menu();
    }
    else return true;
}
Blackjack::~Blackjack()
{
    //dtor
}
