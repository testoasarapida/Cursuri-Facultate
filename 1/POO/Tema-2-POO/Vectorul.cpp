#include "Vectorul.h"
#include <iostream>
#include <vector>
using namespace std;

Vectorul::Vectorul()
{
    this->v.push_back(0);
}
Vectorul::Vectorul(int dim, int *a)
{
    int i;
    for(i=0;i<dim;i++)
        this->v.push_back(a[i]);
}
Vectorul::~Vectorul()
{
    this->v.clear();
    cout<<"Informatiile din clasa Vector au fost sterse."<<endl;
}

Vectorul::Vectorul(const Vectorul& other)
{
    this->v = other.v;
    cout<<"S-a apelat copy constructorul."<<endl;
}


Vectorul& Vectorul::operator = (const Vectorul& C)
{
    this->v = C.v;
    return *this;
}

int Vectorul::aduyayy(int ok)
{
    return this->v[ok];
}

istream& operator >> (istream& f, Vectorul& I)
{
    int i,nr,n;
    f>>n;
    I.v.clear();
    for(i=0;i<n;i++)
    {
        f>>nr;
        I.v.push_back(nr);
    }
    return f;
}

ostream& operator << (ostream& g, Vectorul& I)
{
    int i;
    for(i=0;i<I.v.size();i++)
        cout<< I.v[i] << " ";
    cout<<endl;
    return g;
}

