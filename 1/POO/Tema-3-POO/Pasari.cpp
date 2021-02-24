#include <iostream>
#include "Pasari.h"
using namespace std;

Pasari::Pasari(string denumire, int nr_cam_vent, bool zburatoare, string culoare) : vertebrate(denumire, nr_cam_vent), zburatoare(zburatoare), culoare(culoare)
{
    //cout<<"constructor Pasari"<<endl;
}

Pasari::~Pasari()
{
    this->denumire.clear();
    this->nr_cam_vent = 0;
    this->zburatoare = false;
    this->culoare.clear();
    //cout<<"constructor Pasari"<<endl;
}

Pasari::Pasari(const Pasari &other) : vertebrate(other), zburatoare(other.zburatoare), culoare(other.culoare)
{
    //cout<<"CCconstructor Pasari"<<endl;
}

Pasari &Pasari::operator=(const Pasari& B)
{
    this->denumire = B.denumire;
    this->nr_cam_vent = B.nr_cam_vent;
    this->zburatoare = B.zburatoare;
    this->culoare = B.culoare;
    return *this;
}

void Pasari::afisare()
{
    cout<<this->denumire<<" "<<this->nr_cam_vent<<" "<<this->zburatoare<<" "<<this->culoare<<endl;
}
