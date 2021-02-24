#include <iostream>
#include <fstream>
#include <vector>
#include "Vectorul.h"
#include "Matricea.h"
#include "Matrice_oarecare.h"
#include "Matrice_patratica.h"
using namespace std;

int main()
{

    ifstream fis("date.in");
    Vectorul A;
    int i, nr_linii, nr_coloane;
    cin>>nr_linii;
    cin>>nr_coloane;
    if(nr_linii != nr_coloane)
    {
        Matrice_oarecare M;
        M.incarcadimensiuni(nr_linii,nr_coloane);
        for(i=0;i<nr_linii;i++)
        {
            fis>>A;
            M.incarcavector(A);
        }
        cout<<M;
        M.verifica();
    }
    if(nr_linii == nr_coloane)
    {
        Matrice_patratica M;
        M.Pincarcadimensiuni(nr_linii,nr_coloane);
        for(i=0;i<nr_linii;i++)
        {
            fis>>A;
            M.incarcavector(A);
        }
        cout<<M;
        M.Pverifica();
    }
    return 0;
}
