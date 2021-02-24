#ifndef MATRICEA_H
#define MATRICEA_H
#include <vector>
#include "Vectorul.h"
using namespace std;


class Matricea
{
    protected:
        Vectorul m;
        int o;
    public:
        Matricea(int o = 1);
        virtual ~Matricea();
        Matricea(const Matricea&);

        virtual void incarcavector(Vectorul&) = 0;

        friend istream& operator >> (istream&, Matricea&);
        friend ostream& operator << (ostream&, Matricea&);

};

#endif // MATRICEA_H
