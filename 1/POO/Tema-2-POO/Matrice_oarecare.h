#ifndef MATRICE_OARECARE_H
#define MATRICE_OARECARE_H

#include "Matricea.h"


class Matrice_oarecare : public Matricea
{
    private:
        int i;
        int j;
        int contor = 0;
        int hopa[10][10];
    public:
        Matrice_oarecare(int o = 1, int i = 0, int j = 0);
        virtual ~Matrice_oarecare();
        Matrice_oarecare(const Matrice_oarecare&);

        void incarcadimensiuni(int,int);
        void incarcavector(Vectorul&);
        void incarcamatrice(int);
        void verifica();

        friend ostream& operator << (ostream&, Matrice_oarecare&);
        friend istream& operator >> (istream&, Matrice_oarecare&);
};

#endif // MATRICE_OARECARE_H
