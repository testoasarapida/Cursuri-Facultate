#include <iostream>
#include <fstream>
#include <list>
#include "numar_intreg_mare.h"
#include "numar_rational_mare.h"
using namespace std;
int main()
{
    ifstream fis("date.in");

    numar_intreg_mare A,B;
    fis >> A;
    fis >> B;
    cout<< "Clasa numar_intreg_mare" <<endl<<endl;
    cout<< "Afisare: " << A << " " << B <<endl;
    cout<< "Adunare: " << A + B <<endl;
    cout<< "Scadere: " << A - B <<endl;
    cout<< "Inmultire: " << A * B <<endl;
    cout<< "Catul impartirii: " << A / B <<endl;
    cout<< "Restul impartirii: " << A % B <<endl;
    cout<< "CMMDC: " << Euclid(A,B)<<endl;
    cout<<endl<<endl;

    numar_rational_mare C,D;
    fis >> C;
    fis >> D;
    cout<< "Clasa numar_rational_mare"<<endl<<endl;
    cout<< "Afisare: " << C << " " << D <<endl;
    cout<< "Adunare: " << C + D <<endl;
    cout<< "Inmultire: " << C * D <<endl;
    ireductibil(C);
    cout<<endl;
    fis.close();
    return 0;
}
