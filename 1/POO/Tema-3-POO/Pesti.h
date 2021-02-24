#ifndef TEMA3POOV2_PESTI_H
#define TEMA3POOV2_PESTI_H
#include "vertebrate.h"
using namespace std;

class Pesti : public vertebrate
{
    bool rapitor;
    int lungime_in_cm;
    public:
        Pesti(string denumire = "hei", int nr_cam_vent = 0, bool rapitor = false, int lungime_in_cm = 0);
        virtual ~Pesti();
        Pesti(const Pesti& other);

        Pesti& operator = (const Pesti&);
        void afisare();
        bool rapeste();
};


#endif
