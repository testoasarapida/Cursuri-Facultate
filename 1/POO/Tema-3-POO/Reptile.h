#ifndef TEMA3POOV2_REPTILE_H
#define TEMA3POOV2_REPTILE_H
#include "vertebrate.h"
using namespace std;

class Reptile : public vertebrate
{
    int nr_picioare;
    int lungimea;
    public:
        Reptile(string denumire = "", int nr_cam_vent = 0, int nr_picioare = 0, int lungimea = 0);
        virtual ~Reptile();
        Reptile(const Reptile& other);

        Reptile& operator = (const Reptile&);
        void afisare();
};

#endif