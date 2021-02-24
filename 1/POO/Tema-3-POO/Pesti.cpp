#include <iostream>
#include "Pesti.h"
using namespace std;

#include "Pesti.h"

Pesti::Pesti(string denumire, int nr_cam_vent, bool rapitor, int lungime_in_cm) : vertebrate(denumire, nr_cam_vent), rapitor(rapitor), lungime_in_cm(lungime_in_cm)
{
    //cout<<"construcor Pesti"<<endl;
}

Pesti::~Pesti()
{
    this->denumire.clear();
    this->nr_cam_vent = 0;
    this->rapitor = false;
    this->lungime_in_cm = 0.0;
    //cout<<"destructor Pesti"<<endl;
}

Pesti::Pesti(const Pesti &other) : vertebrate(other), rapitor(other.rapitor), lungime_in_cm(other.lungime_in_cm)
{
    //cout<<"CCconstructor Pesti"<<endl;
}

Pesti &Pesti::operator=(const Pesti& B)
{
    this->denumire = B.denumire;
    this->nr_cam_vent = B.nr_cam_vent;
    this->rapitor = B.rapitor;
    this->lungime_in_cm = B.lungime_in_cm;
    return *this;
}

void Pesti::afisare()
{
    cout<<this->denumire<<" "<<this->nr_cam_vent<<" "<<this->rapitor<<" "<<this->lungime_in_cm<<endl;
}

bool Pesti::rapeste()
{
    if(this->rapitor && this->lungime_in_cm > 100)
        return true;
    return false;
}



