#ifndef NUMAR_RATIONAL_MARE_H
#define NUMAR_RATIONAL_MARE_H
#include <list>
#include <iostream>
#include "numar_intreg_mare.h"
using namespace std;

class numar_rational_mare
{
    list<int> numarator;
    list<int> numitor;
    public:
        numar_rational_mare();
        numar_rational_mare(int numa, int numi);
        numar_rational_mare(const numar_rational_mare&);
        virtual ~numar_rational_mare();

        friend istream& operator >> (istream&, numar_rational_mare&);
        friend ostream& operator << (ostream&, numar_rational_mare&);
        friend float operator + (numar_rational_mare&, numar_rational_mare&);
        friend float operator * (numar_rational_mare&, numar_rational_mare&);
        friend void ireductibil(numar_rational_mare&);
        friend int preluc_numa(numar_rational_mare&);
        friend int preluc_numi(numar_rational_mare&);
};

#endif // NUMAR_RATIONAL_MARE_H
