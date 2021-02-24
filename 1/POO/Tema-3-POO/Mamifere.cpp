#include <iostream>
#include "Mamifere.h"

Mamifere::Mamifere(string denumire, int nr_cam_vent, bool domestic, int greutate) : vertebrate(denumire, nr_cam_vent), domestic(domestic), greutate(greutate)
{
    //cout<<"constructor Mamifere"<<endl;
}

Mamifere::~Mamifere()
{
    this->denumire.clear();
    this->nr_cam_vent = 0;
    this->domestic = 0;
    this->greutate = 0;
    //cout<<"destructor Mamifere"<<endl;
}

Mamifere::Mamifere(const Mamifere &other) : vertebrate(other), domestic(other.domestic), greutate(other.greutate)
{
    //cout<<"CCconstructor Mamifere"<<endl;
}

Mamifere &Mamifere::operator=(const Mamifere& B)
{
    this->denumire = B.denumire;
    this->nr_cam_vent = B.nr_cam_vent;
    this->domestic = B.domestic;
    this->greutate = B.greutate;
    return *this;
}

void Mamifere::afisare()
{
    cout<<this->denumire<<" "<<this->nr_cam_vent<<" "<<this->domestic<<" "<<this->greutate<<endl;
}

