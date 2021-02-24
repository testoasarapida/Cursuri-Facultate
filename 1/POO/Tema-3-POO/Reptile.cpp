#include <iostream>
#include "Reptile.h"
using namespace std;

Reptile::Reptile(string denumire, int nr_cam_vent, int nr_picioare, int lungimea) : vertebrate(denumire, nr_cam_vent), nr_picioare(nr_picioare), lungimea(lungimea)
{
    //cout<<"constructor Reptile"<<endl;
}

Reptile::~Reptile()
{
    this->denumire.clear();
    this->nr_cam_vent = 0;
    this->nr_picioare = 0;
    this->lungimea = 0;
    //cout<<"destructor Reptile"<<endl;
}

Reptile::Reptile(const Reptile &other) : vertebrate(other), nr_picioare(other.nr_picioare), lungimea(other.lungimea)
{
    //cout<<"CCconstructor Reptile"<<endl;
}

Reptile &Reptile::operator=(const Reptile& B)
{
    this->denumire = B.denumire;
    this->nr_cam_vent = B.nr_cam_vent;
    this->nr_picioare = B.nr_picioare;
    this->lungimea = B.lungimea;
    return *this;
}

void Reptile::afisare()
{
    cout<<this->denumire<<" "<<this->nr_cam_vent<<" "<<this->nr_picioare<<" "<<this->lungimea<<endl;
}


