#include <iostream>
#include <fstream>
#include <list>
#include "Animal.h"
#include "nevertebrate.h"
#include "vertebrate.h"
#include "Pesti.h"
#include "Mamifere.h"
#include "Pasari.h"
#include "Reptile.h"
using namespace std;

template<class T>
class AtlasZoologic
{
    list<T*> lista;
    int n;
    int pesti_mari;
    public:
        AtlasZoologic()
        {
            this->n = 0;
            this->pesti_mari = 0;
            //cout<<"constructor AtlasZoologic"<<endl;
        }
        virtual ~AtlasZoologic()
        {
            //cout<<"destructor AtlasZoologic"<<endl;
        }
        AtlasZoologic(const AtlasZoologic& other)
        {
            //cout<<"CCconstructor AtlasZoologic"<<endl;
        }
        template< typename U>
        AtlasZoologic &operator += (const U &B)
        {
            this->lista.push_back(B);
            this->n++;
            if (typeid(U) == typeid(Pesti*))
            {
                list<Animal*>::iterator i;
                this->pesti_mari = 0;
                for(i = this->lista.begin(); i != this->lista.end(); i++)
                {
                    Pesti* ok = dynamic_cast<Pesti*>(*i);
                    if(ok)
                    {
                        if (dynamic_cast<Pesti *>(*i)->rapeste())
                            this->pesti_mari++;
                    }
                }
            }
            cout<<"Pana acum au fost cititi "<<this->pesti_mari<<" rapitori mai mari de 1 metru."<<endl;
            return *this;
        }
        void afi()
        {
            cout<<endl;
            list<Animal*>::iterator i;
            for(i = this->lista.begin(); i != this->lista.end(); i++)
            {
                (*i)->afisare();
                Animal::traieste_animalul();
            }
            cout<<endl<<"Au fost citite "<<n<<" animale."<<endl;
        }
};

int main()
{
    ifstream f("file.txt");
    AtlasZoologic<Animal> atlas;
    int nr, i;
    string x;
    f>>nr;
    for(i = 0; i < nr; i++)
    {
        string denumire;
        int nr_ventricule;
        f>>x;
        if (x == "PESTE")
        {
            bool rapitor;
            int lungime;
            f>>denumire>>nr_ventricule>>rapitor>>lungime;
            Pesti* pes = new Pesti(denumire, nr_ventricule, rapitor, lungime);
            atlas += pes;
        }
        if (x == "NEVERTEBRAT")
        {
            bool carapace;
            int dimensiune_cm;
            f>>denumire>>nr_ventricule>>carapace>>dimensiune_cm;
            nevertebrate* nev = new nevertebrate(denumire, nr_ventricule, carapace, dimensiune_cm);
            atlas += nev;
        }
        if (x == "MAMIFER")
        {
            bool domestic;
            int greutate;
            f>>denumire>>nr_ventricule>>domestic>>greutate;
            Mamifere* mam = new Mamifere(denumire, nr_ventricule, domestic, greutate);
            atlas += mam;
        }
        if (x == "PASARE")
        {
            bool zburatoare;
            string culoare;
            f>>denumire>>nr_ventricule>>zburatoare>>culoare;
            Pasari* pas = new Pasari(denumire, nr_ventricule, zburatoare, culoare);
            atlas += pas;
        }
        if (x == "REPTILA")
        {
            int nr_picioare;
            int lungimea;
            f>>denumire>>nr_ventricule>>nr_picioare>>lungimea;
            Reptile* rep = new Reptile(denumire, nr_ventricule, nr_picioare, lungimea);
            atlas += rep;
        }
    }
    atlas.afi();
}
