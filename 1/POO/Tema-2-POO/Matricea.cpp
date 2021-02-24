#include "Matricea.h"
#include <iostream>
#include <vector>
#include "Vectorul.h"
using namespace std;

#include <fstream>
ifstream fis("date.in");

Matricea::Matricea(int o) :o(o)
{
    cout<<"S-a apelat clasa Matricea."<<endl;
}

Matricea::~Matricea()
{
    this->m.v.clear();
    this->o = NULL;
    cout<<"Informatiile din clasa Matricea au fost sterse."<<endl;
}
Matricea::Matricea(const Matricea& other) : o(other.o)
{
    cout<<"cc S-a apelat clasa Matricea."<<endl;
}

istream& operator >> (istream& f, Matricea& M)
{
    Vectorul A;
    fis>>A;
    M.m = A;
    return f;
}
ostream& operator << (ostream& g, Matricea& M)
{
    cout<<M.m;
    cout<<endl;
    return g;
}


