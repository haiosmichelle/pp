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
#pragma once
#include <windows.h>
#include <conio.h>
#include "Menu.h"
using namespace std;

template <typename T> class lista
{public:
vector<Catalog>elev;
vector<Materie>mat;
lista(string file)
{
  ifstream f(file);
  string linii,l;
  int i=0;
  while(!f.eof())
    {
      if(i!=0)
      {getline(f,linii);
        Catalog c(linii);
        elev.push_back(c);
        }
    i++;
    }
  f.close();
  f.open("catalog.txt");
  i=0;
  while(!f.eof())
    {
      if(i==0)
      {getline(f,l);
        Materie m(l);
        mat.push_back(m);
        break;
        }
    }
  f.close();
}
void adaug_elev(string file)
{
    int i,l,g,v,t;
   ofstream f;
   char nume[100],note[100];
  int id;
   f.open(file, ios_base::app);
  lista list(file);
  cout<<"Nume elev: ";
  cin.get(nume,100);
  cin.get();
  f<<endl<<nume<<" ";
  Materie s=list.mat.at(0);
  for(int i=0;i<s.getmat().size();i++)
    {
      cout<<"Note la materia "<<s.getmat().at(i)<<": ";
      cin.get(note,100);
      f<<note<<" ";
      cin.get();
    }
  f.close();
}
void adaug_materie(string file)
{
  char materie[1000],note[100];
  string mate;
  vector<string>noti;
   ofstream f;
  lista list(file);
  cin.get();
  cout<<"Materiile:\n";
    Materie s=list.mat.at(0);
  for(int i=0;i<s.getmat().size();i++)
  {
      cout<<s.getmat()[i]<<endl;
  }
  cout<<"Ce materie doresti sa adaugi: ";
  cin.get(materie,1000);
  cin.get();
  mate=materie;
  for(int i=1;i<list.elev.size();i++)
    {
      cout<<"Ce note are elevul "<<list.elev.at(i).getnume()<<" la materia "<<mate<<": ";
  cin.get(note,100);
  cin.get();
  noti.push_back(note);
  }
  f.open(file, ios_base::out);
    for(int i=0;i<s.getmat().size();i++)
      {
       f<<s.getmat().at(i)<<" ";
      }
   f<<mate;
     for(int t=0,i=1;t<noti.size() && i<list.elev.size();t++,i++)
       {  f<<endl;
        f<<list.elev.at(i).getnume()<<" ";
      for(int j=0;j<list.elev.at(i).getnote().size();j++)
        {
          f<<list.elev.at(i).getnote().at(j)<<" ";
        }
      f<<noti.at(t);
       }

  f.close();
  }
void adaug_not(string file)
{
   ofstream f;
  char nota[100],mate[100],nume[100];
  string materi;
  string noti1;
  string num;
  cout<<"ce nota doresti sa adaugi: ";
  cin.get(nota,100);
  cin.get();
  lista list(file);
  cout<<"Materiile:\n";
    Materie s=list.mat.at(0);
  for(int i=0;i<s.getmat().size();i++)
  {
      cout<<s.getmat()[i]<<endl;
  }
  cout<<"La ce materie doresti sa introduci nota: ";
  cin.get(mate,100);
  cin.get();
   cout<<"Elevii clasei sunt:\n";
   for(int i=1;i<list.elev.size();i++)
    {
      cout<<list.elev[i].getnume()<<"\n";
      }
  cout<<"La ce elev doresti sa introduci nota: ";
  cin.get(nume,100);
  cin.get();
  num=nume;
  materi=mate;
  noti1=nota;
  f.open(file,ios_base::out);
   Materie l=list.mat.at(0);
    for(int i=0;i<l.getmat().size();i++)
      {
       f<<l.getmat().at(i)<<" ";
      }

    for(int j=1;j<list.elev.size();j++)
   {f<<endl;
     f<<list.elev.at(j).getnume()<<" ";
     if(list.elev.at(j).getnume()==num)
     {for(int i=0;i<s.getmat().size();i++)
    {
      if(s.getmat().at(i)==materi)
      {
      f<<list.elev.at(j).getnote().at(i)<<","<<noti1<<" "; }
     else{f<<list.elev.at(j).getnote().at(i)<<" ";}
      }
       }
     else
     {
      for(int i=0;i<s.getmat().size();i++)
    { f<<list.elev.at(j).getnote().at(i)<<" ";
     }}}
  f.close();
  }
void adaug_absenta(string file)
{
   ofstream f;
  char nota[100],mate[100],nume[100];
  string materi;
  string noti1;
  string num;
  lista list(file);
   cout<<"Materiile:\n";
    Materie s=list.mat.at(0);
  for(int i=0;i<s.getmat().size();i++)
  {
      cout<<s.getmat()[i]<<endl;
  }
  cout<<"La ce materie doresti sa introduci absenta: ";
  cin.get(mate,100);
  cin.get();
   cout<<"Elevii clasei sunt:\n";
   for(int i=1;i<list.elev.size();i++)
    {
      cout<<list.elev[i].getnume()<<"\n";
      }
  cout<<"La ce student doresti sa introduci absenta: ";
  cin.get(nume,100);
  cin.get();
  num=nume;
  materi=mate;
   Materie l=list.mat.at(0);
   f.open(file,ios_base::out);
    for(int i=0;i<l.getmat().size();i++)
      {
       f<<l.getmat().at(i)<<" ";
      }

    for(int j=1;j<list.elev.size();j++)
   {f<<endl;
     f<<list.elev.at(j).getnume()<<" ";
     if(list.elev.at(j).getnume()==num)
     {for(int i=0;i<s.getmat().size();i++)
    {
      if(s.getmat().at(i)==materi)
      {
      f<<list.elev.at(j).getnote().at(i)<<","<<"ABSENT "; }
     else{f<<list.elev.at(j).getnote().at(i)<<" ";}
      }
       }
     else
     {
      for(int i=0;i<s.getmat().size();i++)
    { f<<list.elev.at(j).getnote().at(i)<<" ";
     }}}
   num.clear();
    materi.clear();
  f.close();
  }
void sterg_elev(string file){
   string elevu;
     lista list(file);
   char el[200];
    cout<<"Elevii clasei sunt:\n";
   for(int i=1;i<list.elev.size();i++)
    {
      cout<<list.elev[i].getnume()<<"\n";
      }
  cout<<"Ce elev doresti sa stergi->";
  cin.get(el,200);
  cin.get();
  elevu=el;
  for(int i=1;i<list.elev.size();i++)
    {
      if(list.elev[i].getnume()==elevu)
      {

        list.elev.erase(list.elev.begin()+i);

      }
    }
   ofstream f;
    f.open(file,ios_base::out);
   Materie l=list.mat.at(0);
    for(int i=0;i<l.getmat().size();i++)
      {
       f<<l.getmat().at(i)<<" ";
      }
  Materie s=list.mat.at(0);
    for(int j=1;j<list.elev.size();j++)
   {f<<endl;
     f<<list.elev.at(j).getnume()<<" ";
     {for(int i=0;i<s.getmat().size();i++)
    {
      f<<list.elev.at(j).getnote().at(i)<<" ";
      }}}
      f.close();
      }
void Modific_date(string file){
  system("cls");
  string elevu;
  char el[200];
  lista list(file);
  cout<<"Elevii clasei sunt:\n";
   for(int i=1;i<list.elev.size();i++)
    {
      cout<<list.elev[i].getnume()<<"\n";
      }
  cout<<"La care elev doresti sa schimbi datele -> ";
  cin.get(el,200);
  cin.get();
  elevu=el;
  int t=0,z=0;
  getch();
 ofstream f;
    f.open(file,ios_base::out);
   Materie l=list.mat.at(0);
    for(int i=0;i<l.getmat().size();i++)
      {
       f<<l.getmat().at(i)<<" ";
      }
  Materie s=list.mat.at(0);
  int op;
  for(int j=1;j<list.elev.size();j++)
   {f<<endl;
     if(list.elev[j].getnume()!=elevu)
     {f<<list.elev.at(j).getnume()<<" ";
      for(int i=0;i<s.getmat().size();i++)
    {
      f<<list.elev.at(j).getnote().at(i)<<" ";
      }
       }
    else{
do{
cout<<"Ce doresti sa schimbi:\n1 -> NUME;\n2 -> NOTA;\n0 -> EXIT;\nOptiunea dorita este: ";
cin>>op;
switch(op)
{
  case 1:{int op1;z++;
    cout<<"Doresti sa-i schimbi:\n1 -> PRENUME;\n2 -> NUMELE DE FAMILIE;\n3 -> TOT NUMELE;\nOptiunea dorita este: ";
cin>>op1;
if(op1==1)
{
string prenume;
cout<<"Ce prenume sa aiba: ";
cin.ignore();
getline(cin,prenume);
f<<list.elev.at(j).getnumefam()<<" "<<prenume<<" ";
}
else
  if(op1==2)
  {
    string nume_fam;
    cout<<"Ce nume de familie sa aiba: ";
    cin.ignore();
    getline(cin,nume_fam);
    f<<nume_fam<<" "<<list.elev.at(j).getprenume()<<" ";
  }
  else
     if(op1==3)
     {
       string nume;
       cout<<"Ce nume sa aiba: ";
       cin.ignore();
    getline(cin,nume);
   f<<nume<<" ";
     }
   getch(); break;}
  case 2:{
    vector<string>vec;
    string temp="";
     if(z==0)
     {
        f<<list.elev.at(j).getnume()<<" ";
     }
    string mat;
    char nota1[10],nota2[10];
    cout<<"Materiile sunt:\n";
    for(int i=0;i<s.getmat().size();i++)
      {cout<<s.getmat()[i]<<endl;}
    cout<<"la ce materie doresti sa-i schimbi nota -> ";
    cin.ignore();
    getline(cin,mat);
    cout<<"Notele de la materie:\n";
     for(int i=0;i<s.getmat().size();i++)
      {
        if(s.getmat()[i]==mat)
        {

      cout<<list.elev.at(j).getnote().at(i)<<endl;
        }
      }
    cout<<"Care nota doriti sa o schimbati dupa prima aparitie: ";
  cin.get(nota1,10);
  cin.get();
  string note1;
  note1=nota1;
  cout<<"Cu ce nota doriti sa schimbati: ";
  cin.get(nota2,10);
  cin.get();
  string note2;
  note2=nota2;
  for(int i=0;i<s.getmat().size();i++)
      {
        if(s.getmat()[i]==mat)
        {

      for(int l=0;l<list.elev.at(j).getnote()[i].size();l++)
        {char n=list.elev.at(j).getnote()[i][l];
            if(n==',')
            {
              vec.push_back(temp);
              temp="";
            }
          else
            {
              temp.push_back(n);
            }
        }
        int v=0;
        vec.push_back(temp);
        for(int l=0;l<vec.size();l++)
          {
            if(vec[l]==note1 && v==0)
            {
              vec.erase(vec.begin()+l);
              vec.insert(vec.begin()+l,note2);
              v++;
            }
            if(l==vec.size()-1)
            {
              f<<vec[l]<<" ";
            }
            else
            {
              f<<vec[l]<<",";
            }
          }
        }
        else
        {f<<list.elev.at(j).getnote().at(i)<<" ";
          }
      }
    t++;
   getch(); break;}
}}while(op!=0);
    if(t==0)
    {
     for(int i=0;i<s.getmat().size();i++)
    {
      f<<list.elev.at(j).getnote().at(i)<<" ";
      }}}}}

void altele(string file)
{
  int op;
  Menu menu;
  vector<float>medii;
  lista list(file);
  do{
   menu.clear_screen(true);

    menu.set_color(menu.TURQUOISE);
    op=menu.Gmenu("0 -> Exit;","1 -> Afisarea mediilor elevilor la fiecare materie","2 -> Afisarea clasamentului pe clasa dupa medii","3 -> Afisarea absolventilor;");
 switch(op)
   {
     case 1:{
       int ab;
       int purtare;
       vector<string>vec;
       string temp="";
       cout<<"--------------MEDIILE---------------\n";
       Materie s=list.mat[0];
       for(int j=1;j<list.elev.size();j++)
         {cout<<"Elevul -> "<<list.elev[j].getnume()<<"\n------------------------------------------------\n";
           ab=0;
           purtare=10;
           for(int i=0;i<s.getmat().size();i++)
         {cout<<s.getmat()[i]<<" -> ";
           string temp="";
          double medii;
          int suma=0;
            for(int l=0;l<list.elev.at(j).getnote()[i].size();l++)
        {
          char n=list.elev.at(j).getnote()[i][l];
            if(n==',')
            {
              vec.push_back(temp);
              temp="";
            }
          else
            {
              temp.push_back(n);
            }
        }
         vec.push_back(temp);
        for(int l=0;l<vec.size();l++)
          {
             if(vec[l]!="ABSENT")
            {suma=suma+stoi(vec[l]);}
            else
            {
              ab++;
            }
          }
          medii=(double)suma/vec.size();
          cout<<round(medii)<<endl;
           vec.clear();
         }
          if(ab>=10)
          {
            purtare=purtare-ab%10;
          }
           cout<<"Purtare -> "<<purtare<<endl;
           cout<<"------------------------------------------------\n";}

      getch(); break;}
     case 2:{
       int ab,purtare;
       double med;
      int m;
       vector<string>vec;
       string temp="";
       cout<<"--------------CLASAMENTUL PE SEMESTRU(de la mic la mare)---------------\n";
       Materie s=list.mat[0];
       for(int j=1;j<list.elev.size();j++)
         {ab=0;
           purtare=10;
           m=0;
           for(int i=0;i<s.getmat().size();i++)
         {
           string temp="";
          int meda;
          int suma=0;
            for(int l=0;l<list.elev.at(j).getnote()[i].size();l++)
        {
          char n=list.elev.at(j).getnote()[i][l];
            if(n==',')
            {
              vec.push_back(temp);
              temp="";
            }
          else
            {
              temp.push_back(n);
            }
        }
         vec.push_back(temp);
        for(int l=0;l<vec.size();l++)
          {
            if(vec[l]!="ABSENT")
            {suma=suma+stoi(vec[l]);}
            else
            {
              ab++;
            }
          }
          meda=round((double)suma/vec.size());
           vec.clear();
          m=meda+m;
         }
           if(ab>=10)
          {
            purtare=purtare-ab%10;
          }
          m=m+purtare;
          list.elev[j].medii=double((m/(s.getmat().size()+1)));
          }
       sort(list.elev.begin(),list.elev.end());
       for(int j=1;j<list.elev.size();j++)
         {
           cout<<"Elevul -> "<<list.elev[j].getnume()<<" -> Media anuala: "<<list.elev[j].medii<<endl<<endl;
         }
      getch(); break;}
     case 3:{
       int ab,purtare;
       double med;
      int m;
      cout<<"---------------------ABSOLVENTI----------------------------"<<endl;
       vector<string>vec;
       string temp="";
       Materie s=list.mat[0];
       for(int j=1;j<list.elev.size();j++)
         {ab=0;
           purtare=10;
           m=0;
           for(int i=0;i<s.getmat().size();i++)
         {
           string temp="";
          int meda;
          int suma=0;
            for(int l=0;l<list.elev.at(j).getnote()[i].size();l++)
        {
          char n=list.elev.at(j).getnote()[i][l];
            if(n==',')
            {
              vec.push_back(temp);
              temp="";
            }
          else
            {
              temp.push_back(n);
            }
        }
         vec.push_back(temp);
        for(int l=0;l<vec.size();l++)
          {
            if(vec[l]!="ABSENT")
            {suma=suma+stoi(vec[l]);}
            else
            {
              ab++;
            }
          }
          meda=round((double)suma/vec.size());
           vec.clear();
          m=meda+m;
         }
           if(ab>=10)
          {
            purtare=purtare-ab%10;
          }
          m=m+purtare;
          list.elev[j].medii=double((m/(s.getmat().size()+1)));
          }
       for(int j=1;j<list.elev.size();j++)
         {
          if(list.elev[j].medii<5)
          {
            cout<<"Elevul -> "<<list.elev[j].getnume()<<" nu a absolvit;"<<endl<<endl;
          }
          else
            if(list.elev[j].medii>=5 && purtare<=6)
            {
              cout<<"Elevul -> "<<list.elev[j].getnume()<<" nu a absolvit;"<<endl<<endl;
            }
           else
              if(list.elev[j].medii>=5 && purtare>6)
              {
                cout<<"Elevul -> "<<list.elev[j].getnume()<<" a absolvit;"<<endl<<endl;
              }
           }
      getch(); break;}
   }
  }while(op!=0);
}
};
