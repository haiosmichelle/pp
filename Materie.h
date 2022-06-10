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
class Materie
{
vector<string >materii;
public:
Materie(string mat)
{
  stringstream m(mat);
  string mi;
  while(m>>mi){materii.push_back(mi);}
}
vector<string> getmat()
{
  return materii;
}
};
