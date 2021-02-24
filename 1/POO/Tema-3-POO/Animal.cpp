#include <iostream>
#include "Animal.h"
using namespace std;

Animal::Animal(string denumire, int nr_cam_vent) : denumire(denumire), nr_cam_vent(nr_cam_vent)
{
    //cout<<"constructor Animal"<<endl;
    if(nr_cam_vent < 2)
        throw(Exceptie());
}

Animal::~Animal()
{
    this->denumire.clear();
    this->nr_cam_vent = 0;
    //cout<<"destructor Animal"<<endl;
}

Animal::Animal(const Animal& other) : denumire(other.denumire), nr_cam_vent(other.nr_cam_vent)
{
    //cout<<"CCconstructor Animal"<<endl;
}

Animal& Animal::operator = (const Animal& B)
{
    this->denumire = B.denumire;
    this->nr_cam_vent = B.nr_cam_vent;
    return *this;
}

void citire_manuala(Animal& A)
{
    cin>>A.denumire>>A.nr_cam_vent;
}

istream &operator>>(istream& f, Animal& A)
{
    cin>>A.denumire>>A.nr_cam_vent;
    return f;
}

const Animal::traieste_animalul()
{
    if(Animal::traieste)
        cout<<"Traieste."<<endl;
    return 1;
}
