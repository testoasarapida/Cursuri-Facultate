#include <iostream>
#include "vertebrate.h"
using namespace std;

vertebrate::vertebrate(string denumire, int nr_cam_vent) : Animal(denumire, nr_cam_vent)
{
    //cout<<"constructor vertebrate"<<endl;
}

vertebrate::~vertebrate()
{
    this->denumire.clear();
    this->nr_cam_vent = 0;
    //cout<<"destructor vertebrate"<<endl;
}

vertebrate::vertebrate(const vertebrate& other) : Animal(other)
{
    //cout<<"CCconstructor vertebrate"<<endl;
}

vertebrate& vertebrate::operator = (const vertebrate& B)
{
    this->denumire = B.denumire;
    this->nr_cam_vent = B.nr_cam_vent;
    return *this;
}


