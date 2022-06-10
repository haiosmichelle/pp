#include<iostream>
#include<string.h>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;
class Catalog
{
string nume;
string prenume;
string note;
int id;
public:
Catalog(string informatii)
{
  stringstream catalog(informatii);
  catalog>>id;
  catalog>>nume;
  catalog>>prenume;
  catalog>>note;
}
  string getnume()
{
  return nume+" "+prenume;
}
  string getnote()
{
  return note;
}
  int getid()
{return id;}
};
class Materie
{
string materii;
public:
Materie(string mat)
{
  stringstream m(mat);
  m>>materii;
}
string getmat()
{
  return materii;
}
};
class lista
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
      if(i==0)
      {
        getline(f,l);
        Materie m(l);
        mat.push_back(m);
      }
      if(i!=0)
      {getline(f,linii);
        Catalog c(linii);
        elev.push_back(c);
        }
      i++;
    }
  f.close();
}
};
void afisare(Catalog c)
{
  cout<<"ID: "<<c.getid()<<" ";
  cout<<"Nume: "<<c.getnume()<<"  ";
  cout<<"Note: "<<c.getnote()<<endl;
}
int main()
{
lista list("catalog.txt");
for(int i=1;i<list.elev.size();i++)
  {
    Catalog c=list.elev.at(i);
    afisare(c);
  }
}