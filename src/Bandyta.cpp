#include "Bandyta.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <Gracz.h>

using namespace std;

extern float kredyt;
Gracz g1;

Bandyta::Bandyta()
{

}
void Bandyta::menu()
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

    switch(wybor)
    {
        case '1':
            if(Bandyta::sprawdzanie()) Bandyta::wyswietlBeben();
            else Bandyta::menu();
            break;
        case '2':
            if(kredyt==0) {cout<<"\nBrak srodkow na koncie\n"; system("PAUSE"); Bandyta::menu();}
            else Bandyta::ustawStawke();
            break;
        case '3':
            g1.menuGry();
    };
}
void Bandyta::wyswietlBeben()
{
    system("CLS");
        kredyt-=stawka;
        cout<<stawka<<endl;
        char zgoda;
        srand(time(NULL));

        bool wygrana = false;
        bool wygrana2 = false;
        bool wygrana3 = false;
        bool wygrana4 = false;
        bool wygrana5 = false;

        int bonus = stawka;
        int bonus2 = stawka;
        int bonus3 = stawka;
        int bonus4 = stawka;
        int bonus5 = stawka;


        for(int i=0; i<3;i++)
            for(int j=0;j<3;j++)
                beben[i][j]=rand()%3+1; //i - wiersze, j - kolumny

        cout<<"\n\n\n\n\n";
        cout<<"       ---------------------------\n";
        for(int i=0; i<3;i++)
        {

            for(int j=0;j<3;j++)
            {

                cout<<"\t|   "<<beben[i][j];

                if(j==2)
                    {
                        cout<<"   |";
                        cout<<endl<<"       ---------------------------";
                    }

            }

            cout<<endl;
        }
        if(beben[0][0]==beben[0][1] && beben[0][1]==beben[0][2])
        {
            if(beben[0][0]==1) bonus*=1;
            if(beben[0][0]==2) bonus*=2;
            if(beben[0][0]==3) bonus*=3;
            wygrana = true;
        }
        if(beben[1][0]==beben[1][1] && beben[1][1]==beben[1][2])
        {
            if(beben[1][0]==1) bonus2*=1;
            if(beben[1][0]==2) bonus2*=2;
            if(beben[1][0]==3) bonus2*=3;
            wygrana2 = true;
        }
        if(beben[2][0]==beben[2][1] && beben[2][1]==beben[2][2])
        {
            if(beben[2][0]==1) bonus3*=1;
            if(beben[2][0]==2) bonus3*=2;
            if(beben[2][0]==3) bonus3*=3;
            wygrana3 = true;
        }
        if(beben[0][0]==beben[1][1] && beben[1][1]==beben[2][2])
        {
            if(beben[0][0]==1) bonus4*=1;
            if(beben[0][0]==2) bonus4*=2;
            if(beben[0][0]==3) bonus4*=3;
            wygrana4 = true;
        }
        if(beben[2][0]==beben[1][1] && beben[1][1]==beben[0][2])
        {
            if(beben[2][0]==1) bonus5*=1;
            if(beben[2][0]==2) bonus5*=2;
            if(beben[2][0]==3) bonus5*=3;
            wygrana5 = true;
        }

        cout<<"\n\n\n\n\n";
        cout<<"Stan konta przed gr¹: "<<kredyt<<endl<<endl;
        if(wygrana==true)
            kredyt += bonus;
        if(wygrana2==true)
            kredyt += bonus2;
        if(wygrana3==true)
            kredyt += bonus3;
        if(wygrana4==true)
            kredyt += bonus4;
        if(wygrana5==true)
            kredyt += bonus5;

        cout<<"Stan konta po grze: "<<kredyt<<endl<<endl;

        do
        {
            //system("CLS");
            cout<<"Chcesz powtorzyc?[T/N]:  ";
            cin>>zgoda;
        }while(zgoda!='t' && zgoda!='n');

        if(zgoda=='t')
            {
                if(Bandyta::sprawdzanie()) Bandyta::wyswietlBeben();
                else Bandyta::menu();
            }
        else if(zgoda=='n')
            Bandyta::menu();

}
void Bandyta::ustawStawke()
{
    do
    {
        system("CLS");
        cout<<"Ustaw swoja stawke do gry: ";
        cin >> stawka;
        if(stawka == 0 || stawka>kredyt) {cout<<"Brak srodkow na koncie"<<endl; system("PAUSE"); }
    }while(stawka == 0 || stawka>kredyt);
        Bandyta::menu();
}

bool Bandyta::sprawdzanie()
{
    if(kredyt==0 || kredyt<stawka)
    {
        cout<<"Za malo zetonow!\n";
        system("PAUSE");
        return false;
        Bandyta::menu();
    }
    else return true;
}
Bandyta::~Bandyta()
{
    //dtor
}
