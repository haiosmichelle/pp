#include<iostream>
#include<string.h>
#include<sstream>
#include<fstream>
#include<vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#pragma once
using namespace std;

class Catalog
{
string nume;
string prenume;
vector<string>note;
public:
float medii;
Catalog(string informatii)
{
  stringstream catalog(informatii);
  catalog>>nume;
  catalog>>prenume;
  string num;
  while (catalog >> num) note.push_back(num);
}
string getprenume()
{
  return prenume;
}
string getnumefam()
{
  return nume;
}
  string getnume()
{
  return nume+" "+prenume;
}
  vector<string> getnote()
{
  return note;
}
friend bool operator <(const Catalog & a,const Catalog &b)
{
  return a.medii< b.medii;
}
};
