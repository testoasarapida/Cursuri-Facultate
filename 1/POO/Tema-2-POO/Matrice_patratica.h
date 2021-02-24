#ifndef MATRICE_PATRATICA_H
#define MATRICE_PATRATICA_H

#include <Matricea.h>


class Matrice_patratica : public Matricea
{
    private:
        int Pi;
        int Pj;
        int Pcontor = 0;
        int Phopa[10][10];
    public:
        Matrice_patratica(int o = 1, int Pi = 0, int Pj = 0);
        virtual ~Matrice_patratica();
        Matrice_patratica(const Matrice_patratica&);

        void Pincarcadimensiuni(int,int);
        void incarcavector(Vectorul&);
        void Pincarcamatrice(int);
        void Pverifica();

        friend ostream& operator << (ostream&, Matrice_patratica&);
        friend istream& operator >> (istream&, Matrice_patratica&);
};

#endif // MATRICE_PATRATICA_H
