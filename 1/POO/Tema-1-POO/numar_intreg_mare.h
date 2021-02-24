#ifndef NUMAR_INTREG_MARE_H
#define NUMAR_INTREG_MARE_H
#include <list>
#include <iostream>
using namespace std;

class numar_intreg_mare
{
    list<int> numar;
    public:
        numar_intreg_mare();
        numar_intreg_mare(int numarul);
        numar_intreg_mare(const numar_intreg_mare&);
        virtual ~numar_intreg_mare();

        friend istream& operator >> (istream&, numar_intreg_mare&);
        friend ostream& operator << (ostream&, numar_intreg_mare&);
        friend int operator + (numar_intreg_mare&, numar_intreg_mare&);
        friend int operator - (numar_intreg_mare&, numar_intreg_mare&);
        friend int operator * (numar_intreg_mare&, numar_intreg_mare&);
        friend int operator / (numar_intreg_mare&, numar_intreg_mare&);
        friend int operator % (numar_intreg_mare&, numar_intreg_mare&);
        friend int Euclid(numar_intreg_mare&, numar_intreg_mare&);
        friend int preluc_numar(numar_intreg_mare&);

        friend class numar_rational_mare;

};


#endif // NUMAR_INTREG_MARE_H
