#include "numar_intreg_mare.h"
#include <iostream>
#include <list>
using namespace std;

numar_intreg_mare::numar_intreg_mare()
{
    this->numar.push_back(0);
}

numar_intreg_mare::numar_intreg_mare(int numarul)
{
    while(numarul)
    {
        this->numar.push_back(numarul%10);
        numarul = numarul / 10;
        this->numar.pop_front();
    }
}

numar_intreg_mare::numar_intreg_mare(const numar_intreg_mare& I)
{
    this->numar = I.numar;
    cout<<"S-a apelat copy constructorul.";
}

numar_intreg_mare::~numar_intreg_mare()
{
    this->numar.clear();
    cout<<endl<<"Toate numerele au fost sterse.";
}

int preluc_numar(numar_intreg_mare& I)
{
    int numa = 0;
    for (list<int>::iterator it = I.numar.begin(); it != I.numar.end(); ++it)
        numa = numa * 10 + *it;
    int n = 0;
    while(numa)
    {
        n = n * 10 + numa%10;
        numa = numa / 10;
    }
    return n;
}

istream& operator >> (istream& f, numar_intreg_mare& I)
{
    int a;
    f >> a;
    while(a)
    {
        I.numar.push_back(a%10);
        a = a / 10;
    }
    I.numar.pop_front();
    return f;
}

ostream& operator << (ostream& g, numar_intreg_mare& I)
{
    cout<< preluc_numar(I);
    return g;
}

int operator + (numar_intreg_mare& I, numar_intreg_mare& J)
{
    return preluc_numar(I) + preluc_numar(J);
}

int operator - (numar_intreg_mare& I, numar_intreg_mare& J)
{
    return preluc_numar(I) - preluc_numar(J);
}

int operator * (numar_intreg_mare& I, numar_intreg_mare& J)
{
    return preluc_numar(I) * preluc_numar(J);
}

int operator / (numar_intreg_mare& I, numar_intreg_mare& J)
{
    return preluc_numar(I) / preluc_numar(J);
}

int operator % (numar_intreg_mare& I, numar_intreg_mare& J)
{
    return preluc_numar(I) % preluc_numar(J);
}

int Euclid(numar_intreg_mare& I, numar_intreg_mare& J)
{
    int a = preluc_numar(I);
    int b = preluc_numar(J);
    while(a != b)
    {
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
