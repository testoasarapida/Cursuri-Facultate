#include <iostream>
#include "nevertebrate.h"
using namespace std;

nevertebrate::nevertebrate(string denumire, int nr_cam_vent, bool carapace, int dimensiune_cm) : Animal (denumire, nr_cam_vent), carapace(carapace), dimensiune_cm(dimensiune_cm)
{
    //cout<<"constructor nevertebrate"<<endl;
}

nevertebrate::~nevertebrate()
{
    this->denumire.clear();
    this->nr_cam_vent = 0;
    this->carapace = false;
    this->dimensiune_cm = 0;
    //cout<<"destructor nevertebrate"<<endl;
}

nevertebrate::nevertebrate(const nevertebrate& other) : Animal(other), carapace(other.carapace), dimensiune_cm(other.dimensiune_cm)
{
    //cout<<"CCconstructor nevertebrate"<<endl;
}

nevertebrate &nevertebrate::operator = (const nevertebrate& B)
{
    this->denumire = B.denumire;
    this->nr_cam_vent = B.nr_cam_vent;
    this->carapace = B.carapace;
    this->dimensiune_cm = B.dimensiune_cm;
    return *this;
}

void nevertebrate::afisare()
{
    cout<<this->denumire<<" "<<this->nr_cam_vent<<" "<<this->carapace<<" "<<this->dimensiune_cm<<endl;
}