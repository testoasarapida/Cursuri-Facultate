#include "numar_rational_mare.h"
#include <iostream>
#include <list>
using namespace std;

numar_rational_mare::numar_rational_mare()
{
    this->numarator.push_back(0);
    this->numitor.push_back(0);
}

numar_rational_mare::numar_rational_mare(int numa, int numi)
{
    while(numa)
    {
        this->numarator.push_back(numa%10);
        numa = numa / 10;
        this->numarator.pop_front();
    }
    while(numi)
    {
        this->numitor.push_back(numi%10);
        numi = numi / 10;
        this->numitor.pop_front();
    }
}

numar_rational_mare::numar_rational_mare(const numar_rational_mare& R)
{
    this->numarator = R.numarator;
    this->numitor = R.numitor;
    cout<<"S-a apelat copy constructorul.";
}

numar_rational_mare::~numar_rational_mare()
{
    this->numarator.clear();
    this->numitor.clear();
    cout<<endl<<"Toate numerele au fost sterse.";
}

int preluc_numa(numar_rational_mare& R)
{
    int numa = 0;
    for (list<int>::iterator it = R.numarator.begin(); it != R.numarator.end(); ++it)
        numa = numa * 10 + *it;
    int n = 0;
    while(numa)
    {
        n = n * 10 + numa%10;
        numa = numa / 10;
    }
    return n;
}

int preluc_numi(numar_rational_mare& R)
{
    int numa = 0;
    for (list<int>::iterator it = R.numitor.begin(); it != R.numitor.end(); ++it)
        numa = numa * 10 + *it;
    int n = 0;
    while(numa)
    {
        n = n * 10 + numa%10;
        numa = numa / 10;
    }
    return n;
}

istream& operator >> (istream& f, numar_rational_mare& R)
{
    int a;
    f >> a;
    while(a)
    {
        R.numarator.push_back(a%10);
        a = a / 10;
    }
    R.numarator.pop_front();
    f >> a;
    while(a)
    {
        R.numitor.push_back(a%10);
        a = a / 10;
    }
    R.numitor.pop_front();
    return f;
}

ostream& operator << (ostream& g, numar_rational_mare& R)
{
    cout<< float(preluc_numa(R)) / float(preluc_numi(R));
    return g;
}

float operator + (numar_rational_mare& R, numar_rational_mare& Q)
{
    return float(preluc_numa(R)) / float(preluc_numi(R)) + float(preluc_numa(Q)) / float(preluc_numi(Q));
}

float operator * (numar_rational_mare& R, numar_rational_mare& Q)
{
    return float(preluc_numa(R)) / float(preluc_numi(R)) * float(preluc_numa(Q)) / float(preluc_numi(Q));
}

void ireductibil(numar_rational_mare& R)
{
    int a = preluc_numa(R);
    int b = preluc_numi(R);
    while(a != b)
        if(a > b)
            a = a - b;
        else
            b = b - a;
    cout<< "Fractie ireductibila: " << preluc_numa(R)/a << "/" << preluc_numi(R)/b;
}
