#ifndef TEMA3POOV2_PASARI_H
#define TEMA3POOV2_PASARI_H
#include <string>
#include "vertebrate.h"
using namespace std;

class Pasari : public vertebrate
{
    bool zburatoare;
    string culoare;
    public:
        Pasari(string denumire = "", int nr_cam_vent = 0, bool zburatoare = false, string culoare = "");
        virtual ~Pasari();
        Pasari(const Pasari& other);

        Pasari& operator = (const Pasari&);
        void afisare();
};

#endif