#include "AtlaZoologic.h"
#include <iostream>

template <class T>
AtlaZoologic<T>::AtlaZoologic()
{
    cout<<"constructor AtlasZoologic"<<endl;
}

template <class T>
AtlaZoologic<T>::~AtlaZoologic()
{
    cout<<"destructor AtlasZoologic"<<endl;
}

template <class T>
AtlaZoologic<T>::AtlaZoologic(const AtlaZoologic& other)
{
    cout<<"CCconstructor AtlasZoologic"<<endl;
}

template <class T>
void AtlaZoologic<T>::afi()
{
    list<Animal*>::iterator i;
    for(i = this->lista.begin(); i != this->lista.end(); i++)
        (*i)->afisare();
}

template <class T>
template <class U>
AtlaZoologic<T> &AtlaZoologic<T>::operator += (const U &B)
{
    this->lista.push_back(B);
    return *this;
}
