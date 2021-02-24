#ifndef TEMA3POOV2_NEVERTEBRATE_H
#define TEMA3POOV2_NEVERTEBRATE_H
#include "Animal.h"
using namespace std;

class nevertebrate : public Animal
{
    bool carapace;
    int dimensiune_cm;
    public:
        nevertebrate(string denumire = "", int nr_cam_vent = 0, bool carapace = false, int dimensiune_cm = 0);
        virtual ~nevertebrate();
        nevertebrate(const nevertebrate& other);

        nevertebrate& operator = (const nevertebrate&);
        void afisare();
};

#endif // NEVERTEBRATE_H
