#ifndef TEMA3POOV2_ANIMAL_H
#define TEMA3POOV2_ANIMAL_H
#include <string>
#include "Exceptie.h"
using namespace std;

class Animal
{
protected:
    string denumire;
    int nr_cam_vent;
    static const int traieste = 1;
public:
    Animal(string denumire = "", int nr_cam_vent = 0);
    virtual ~Animal();
    Animal(const Animal& other);

    Animal& operator = (const Animal&);
    virtual void afisare() = 0;
    static const traieste_animalul();
    friend void citire_manuala(Animal&);
    friend istream& operator >> (istream&, Animal&);
};

#endif