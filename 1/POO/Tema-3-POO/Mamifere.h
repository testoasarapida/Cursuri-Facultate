#ifndef TEMA3POOV2_MAMIFERE_H
#define TEMA3POOV2_MAMIFERE_H
#include "vertebrate.h"
using namespace std;

class Mamifere : public vertebrate
{
    bool domestic;
    int greutate;
    public:
        Mamifere(string denumire = "", int nr_cam_vent = 0, bool domestic = false, int greutate = 0);
        virtual ~Mamifere();
        Mamifere(const Mamifere& other);

        Mamifere& operator = (const Mamifere&);
        void afisare();
};

#endif