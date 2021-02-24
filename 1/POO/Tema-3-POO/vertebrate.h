#ifndef TEMA3POOV2_VERTEBRATE_H
#define TEMA3POOV2_VERTEBRATE_H
#include <string>
#include "Animal.h"
using namespace std;

class vertebrate : public Animal
{
    public:
        vertebrate(string denumire = "", int nr_cam_vent = 0);
        virtual ~vertebrate();
        vertebrate(const vertebrate& other);

        vertebrate& operator = (const vertebrate&);
        virtual void afisare() = 0;
};

#endif
