#include<iostream>
#include<string.h>
#include<sstream>
#include<fstream>
#include<vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include "Catalog.h"
#include "Materie.h"
#include "lista.h"
#include "Menu.h"
#include <windows.h>
#include <conio.h>

using namespace std;

void afisare(Catalog c,Materie s){
  cout<<"Nume: "<<c.getnume()<<"  "<<endl;
  for(int i=0;i<c.getnote().size();i++)
    {cout<<"Materie: "<<s.getmat().at(i)<<" Note: "<<c.getnote().at(i)<<endl;}
  cout<<"--------------------------------------------"<<endl;

}

void dis()
{
lista <string> list("catalog.txt");
for(int i=1;i<list.elev.size();i++)
  {
    Catalog c=list.elev.at(i);
    Materie s=list.mat.at(0);
    afisare(c,s);
  }
  }

  int main()
{

    Menu menu;
    int op;
    do{
      menu.clear_screen(true);

    menu.set_color(menu.TURQUOISE);
    op=menu.Gmenu("   CATALOGUL UNEI CLASE","1 -> pentru a arata catalogul","2 -> pentru a adauga un elev","3 -> pentru a adauga materii noi","4 -> pentru a adauga o nota","5 -> pentru a adauga absente la o materie","6 -> pentru a modifica datele despre un elev","7 -> pentru a sterge un elev si a tuturor notelor sale","8 -> pentru meniul de vizualizari dupa criterii");
    switch(op)
    {
        case 1:{dis(); getch();break;}
            case 2:{lista <string> list("catalog.txt");list.adaug_elev("catalog.txt");break;}
            case 3:{lista <string> list("catalog.txt");list.adaug_materie("catalog.txt");break;}
            case 4:{lista <string> list("catalog.txt");list.adaug_not("catalog.txt");fflush(stdin);getch();break;}
            case 5:{lista <string> list("catalog.txt");list.adaug_absenta("catalog.txt");break;}
            case 6:{lista <string> list("catalog.txt");list.Modific_date("catalog.txt");break;}
            case 7:{lista <string> list("catalog.txt");list.sterg_elev("catalog.txt");fflush(stdin);getch();break;}
            case 8:{lista <string>  list("catalog.txt");list.altele("catalog.txt");break;}

    }}while(op!=0);
    /*int op;
    do
    {
        cout<<"Optiunea 1 pentru a arata catalogul"<<endl;
        cout<<"Optiunea 2 pentru a adauga un elev;"<<endl;
        cout<<"Optiunea 3 pentru a adauga materii noi;"<<endl;
        cout<<"Optiunea 4 pentru a adauga o nota;"<<endl;
        cout<<"Optiunea 5 pentru a adauga absente la o materie;"<<endl;
        cout<<"Optiunea 6 pentru a modifica datele despre un elev;"<<endl;
       cout<<"Optiunea 7 pentru a sterge un elev si a tuturor notelor sale;"<<endl;
       cout<<"Optiunea 8 pentru meniul de vizualizari dupa criterii"<<endl;
        cout<<"Optiunea 0 pentru exit!";
        cout<<"\nIntrodu optiunea dorita: ";
        cin>>op;
        switch(op)
        {
            case 1:dis();break;
            case 2:{lista <string> list("catalog.txt");list.adaug_elev("catalog.txt");break;}
            case 3:{lista <string>list("catalog.txt");list.adaug_materie("catalog.txt");break;}
            case 4:{lista <string>list("catalog.txt");list.adaug_not("catalog.txt");break;}
            case 5:{lista <string> list("catalog.txt");list.adaug_absenta("catalog.txt");break;}
            case 6:{lista <string>list("catalog.txt");list.Modific_date("catalog.txt");break;break;}
            case 7:{lista <string> list("catalog.txt");list.sterg_elev("catalog.txt");break;}
            case 8:lista <string> list("catalog.txt");list.altele("catalog.txt");altele();break;

        }
    }while(op!=0);*/
}
