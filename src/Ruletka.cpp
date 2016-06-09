#include "Ruletka.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <Gracz.h>

extern float kredyt;
Gracz g3;

Ruletka::Ruletka()
{
    //ctor
}
void Ruletka::Menu()
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
            if(Ruletka::sprawdzanie()) Ruletka::Gra();
            else Ruletka::Menu();
            break;
        case '2':
            if(kredyt==0) {cout<<"\nBrak srodkow na koncie\n"; system("PAUSE"); Ruletka::Menu();}
            else Ruletka::ustawStawke();
            break;
        case '3':
            g3.menuGry();
    };
}


void Ruletka::Gra()
{
    int tab[37][2];
    int i = 0;
    int j = 0;
    srand(time(NULL));

    char wybor;
    kredyt-=stawka;

    for(i=0;i<37;i++)
        for(j=0;j<2;j++)
            tab[i][j] = i;

    for(i = 0; i<37; i++)
    {
        for(j=1;j<2;j++)
        {
            if(i%2==0)
                tab[i][j]=0;
            if(i%2==1)
                tab[i][j]=1;
        }
    }

    do
    {
        system("CLS");
        cout<<"Obstawiaj!"<<endl
            <<"1. Jedna liczba"<<endl
            <<"2. Parzyste"<<endl
            <<"3. Nieparzyste"<<endl
            <<"4. Czarne"<<endl
            <<"5. Czerwone"<<endl
            <<"6. Niskie(1-18)"<<endl
            <<"7. Wysokie(19-36)"<<endl
            <<"Twoj wybor: ";
        cin >>wybor;
    }while(wybor!='1' && wybor!='2' && wybor!='3' && wybor!='4' && wybor!='5' && wybor!='6' && wybor!='7');

    i = rand()%36;

    char zgoda;
    if(wybor == '1')
    {
        do
        {
            system("CLS");
            cout<<"Wybierz liczbe (0-36):  ";
            cin>>liczba;
        }while(liczba<0 || liczba>36);
        if(tab[i][j]==liczba)
        {
            cout<<"\nwygrales!\n";
            kredyt+=stawka*4;
        }
        else
        {
            cout<<tab[i][j]<<endl;
            cout<<"\nprzegryw\n";
        }

        do
        {
            //system("CLS");
            cout<<"Chcesz powtorzyc?[T/N]:  ";
            cin>>zgoda;
        }while(zgoda!='t' && zgoda!='n');

        if(zgoda=='t')
            {
                if(Ruletka::sprawdzanie()) Ruletka::Gra();
                else Ruletka::Menu();
            }
        else if(zgoda=='n')
            Ruletka::Menu();

    }


    if(wybor == '2')
    {
        if(tab[i][j]%2==0)
        {
            cout<<"\nwygrales!\n";
            kredyt+=stawka*2;
        }
        else
        {
            cout<<tab[i][j]<<endl;
            cout<<"\nprzegryw\n";
        }

        do
        {
            //system("CLS");
            cout<<"Chcesz powtorzyc?[T/N]:  ";
            cin>>zgoda;
        }while(zgoda!='t' && zgoda!='n');

        if(zgoda=='t')
            {
                if(Ruletka::sprawdzanie()) Ruletka::Gra();
                else Ruletka::Menu();
            }
        else if(zgoda=='n')
            Ruletka::Menu();

    }

    if(wybor == '3')
    {
        if(tab[i][j]%2==1)
        {
            cout<<"\nwygrales!\n";
            kredyt+=stawka*2;
        }
        else
        {
            cout<<tab[i][j]<<endl;
            cout<<"\nprzegryw\n";
        }

        do
        {
            //system("CLS");
            cout<<"Chcesz powtorzyc?[T/N]:  ";
            cin>>zgoda;
        }while(zgoda!='t' && zgoda!='n');

        if(zgoda=='t')
            {
                if(Ruletka::sprawdzanie()) Ruletka::Gra();
                else Ruletka::Menu();
            }
        else if(zgoda=='n')
            Ruletka::Menu();

    }

    if(wybor == '4')
    {
        if(tab[i][j]%2==0)
        {
            cout<<"\nwygrales!\n";
            kredyt+=stawka*2;
        }
        else
        {
            cout<<tab[i][j]<<endl;
            cout<<"\nprzegryw\n";
        }

        do
        {
            //system("CLS");
            cout<<"Chcesz powtorzyc?[T/N]:  ";
            cin>>zgoda;
        }while(zgoda!='t' && zgoda!='n');

        if(zgoda=='t')
            {
                if(Ruletka::sprawdzanie()) Ruletka::Gra();
                else Ruletka::Menu();
            }
        else if(zgoda=='n')
            Ruletka::Menu();

    }

    if(wybor == '5')
    {
        if(tab[i][j]%2==0)
        {
            cout<<"\nwygrales!\n";
            kredyt+=stawka*2;
        }
        else
        {
            cout<<tab[i][j]<<endl;
            cout<<"\nprzegryw\n";
        }

        do
        {
            //system("CLS");
            cout<<"Chcesz powtorzyc?[T/N]:  ";
            cin>>zgoda;
        }while(zgoda!='t' && zgoda!='n');

        if(zgoda=='t')
            {
                if(Ruletka::sprawdzanie()) Ruletka::Gra();
                else Ruletka::Menu();
            }
        else if(zgoda=='n')
            Ruletka::Menu();

    }

    if(wybor == '6')
    {
        if(tab[i][j]<=18)
        {
            cout<<"\nwygrales!\n";
            kredyt+=stawka*2;
        }
        else
        {
            cout<<tab[i][j]<<endl;
            cout<<"\nprzegryw\n";
        }

        do
        {
            //system("CLS");
            cout<<"Chcesz powtorzyc?[T/N]:  ";
            cin>>zgoda;
        }while(zgoda!='t' && zgoda!='n');

        if(zgoda=='t')
            {
                if(Ruletka::sprawdzanie()) Ruletka::Gra();
                else Ruletka::Menu();
            }
        else if(zgoda=='n')
            Ruletka::Menu();

    }

    if(wybor == '7')
    {
        if(tab[i][j]>=19)
        {
            cout<<"\nwygrales!\n";
            kredyt+=stawka*2;
        }
        else
        {
            cout<<tab[i][j]<<endl;
            cout<<"\nprzegryw\n";
        }

        do
        {
            //system("CLS");
            cout<<"Chcesz powtorzyc?[T/N]:  ";
            cin>>zgoda;
        }while(zgoda!='t' && zgoda!='n');

        if(zgoda=='t')
            {
                if(Ruletka::sprawdzanie()) Ruletka::Gra();
                else Ruletka::Menu();
            }
        else if(zgoda=='n')
            Ruletka::Menu();

    }

}



void Ruletka::ustawStawke()
{
    do
    {
        system("CLS");
        cout<<"Ustaw swoja stawke do gry: ";
        cin >> stawka;
        if(stawka == 0 || stawka>kredyt) {cout<<"Brak srodkow na koncie"<<endl; system("PAUSE"); }
    }while(stawka == 0 || stawka>kredyt);
        Ruletka::Menu();
}

bool Ruletka::sprawdzanie()
{
    if(kredyt==0 || kredyt<stawka)
    {
        cout<<"Za malo zetonow!\n";
        system("PAUSE");
        return false;
        Ruletka::Menu();
    }
    else return true;
}

Ruletka::~Ruletka()
{
    //dtor
}
