#ifndef TEMA3POOV2_ATLAZOOLOGIC_H
#define TEMA3POOV2_ATLAZOOLOGIC_H

#include <iostream>
#include <list>
#include "Animal.h"

template<class T>
class AtlaZoologic
{
    //list<T*> lista;
    public:
        AtlaZoologic();
        virtual ~AtlaZoologic();
        AtlaZoologic(const AtlaZoologic& other);
        template <class U>
        AtlaZoologic<T>& operator += (const U &B);
        /*template<>
        AtlasZoologic &operator += (const Pesti &B)
        {
            this->lista.push_back(B);
            cout << "cucu" << endl;
            return *this;
        }*/
        void afi();

};


#endif
