#include "Gracz.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <Bandyta.h>
#include <Blackjack.h>
#include <Ruletka.h>

using namespace std;

float kredyt = 100;
Bandyta b1;
Blackjack bj1;
Ruletka r1;
Gracz::Gracz()
{

}

Gracz::~Gracz()
{
    //dtor
}

void Gracz::dodajgracza()
{
    cout<<"Casino Royal wita przyszlych czlonkow kasyna!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Prosze o podanie wszystkich informacji ukazanych ponizej"<<endl;
    cout<<"Imie: ";
    cin>>Gracz::imie;
    cout<<"Nazwisko: ";
    cin>>Gracz::nazwisko;
        do
        {
            system("CLS");
            cout<<"Plec([K]kobieta/[M]mezczyzna): ";
            cin>>Gracz::plec;

        }while(Gracz::plec!="k" && Gracz::plec!="m");

        do
        {
            system("CLS");
            cin.clear();
            cin.sync();
            cout<<"Podaj wiek: ";
        }while(!(cin>>Gracz::wiek));
        if(wiek<18)
            cout<<"Jestes nieletni..";
        else
            Gracz::info();


}
void Gracz::info()
{
    system("CLS");
    cout
        <<"Gratulacje dostales sie!"<<endl<<endl
        <<"Twoje dane:"<<endl
        <<"Imie: "<<Gracz::imie<<endl
        <<"Nazwisko: "<<Gracz::nazwisko<<endl
        <<"Plec: "<<Gracz::plec<<endl
        <<"Wiek: "<<Gracz::wiek<<endl
        <<"Stan konta: "<<kredyt<<endl;
        system("PAUSE");
        Gracz::menuGry();
}
void Gracz::konto()
{
    system("CLS");
    cout<<"Twoj stan konta to: "<<kredyt<<endl;
    system("PAUSE");
    Gracz::menuGry();
}
void Gracz::menuGry()
{

    char wybor;
    do
    {
        system("CLS");
        cout<<"\t\tCasino Royal\n";
        cout
            <<"MENU"<<endl
            <<"1. GRAJ BANDYTE"<<endl
            <<"2. GRAJ RULETKE"<<endl
            <<"3. GRAJ BLACKJACK"<<endl
            <<"4. SPRAWDZ STAN KONTA"<<endl
            <<"5. WYJDZ Z KASYNA"<<endl<<endl
            <<"TWOJ WYBOR: ";
        cin >> wybor;
    }while(wybor!='1' && wybor!='2' && wybor!='3' && wybor!='4' && wybor!='5');

    if(wybor=='1')
        b1.menu();
    if(wybor=='2')
        r1.Menu();
    if(wybor=='3')
        bj1.Menu();
    if(wybor=='4')
        Gracz::konto();
}
