#include "Matrice_patratica.h"
#include "Vectorul.h"

Matrice_patratica::Matrice_patratica(int o, int Pi, int Pj) :Matricea(o), Pi(Pi), Pj(Pj)
{
    cout<<"S-a apelat clasa Matrice_patratica."<<endl;
}

Matrice_patratica::~Matrice_patratica()
{
    int k,l;
    for(k=0;k<this->Pi;k++)
        for(l=0;l<this->Pj;l++)
            this->Phopa[k][l] = NULL;
    this->Pi = NULL;
    this->Pj = NULL;
    this->Pcontor = NULL;
    cout<<"Toate informatiile din clasa Matrice_patratica au fost sterse."<<endl;
}

Matrice_patratica::Matrice_patratica(const Matrice_patratica& other2): Matricea(other2), Pi(other2.Pi), Pj(other2.Pj)
{
    cout<<"cc S-a apelat clasa Matrice_patratica.";
}

void Matrice_patratica::incarcavector(Vectorul& I)
{
    this->m = I;
    this->Pincarcamatrice(Pcontor);
    this->Pcontor++;
}
void Matrice_patratica::Pincarcamatrice(int contorul)
{
    int k=0;
    for(k=0;k<this->Pj;k++)
        this->Phopa[contorul][k] = this->m.aduyayy(k);
}
void Matrice_patratica::Pincarcadimensiuni(int k,int l)
{
    this->Pi = k;
    this->Pj = l;
}
void Matrice_patratica::Pverifica()
{
    int k,l,tr_inf=0,tr_sup=0,diag=1;
    for(k=0;k<this->Pi;k++)
        for(l=0;l<this->Pj;l++)
            if(k>l && this->Phopa[k][l] != 0)
                tr_inf = 1;
            else
                if(l>k && this->Phopa[k][l] != 0)
                    tr_sup = 1;
                else
                    if(l==k && this->Phopa[k][l] == 0)
                        diag = 0;
    if(tr_inf == 0 && tr_sup == 0 && diag == 1)
        cout<<"Matrice diagonala"<<endl;
    else
        if(tr_inf == 0 && tr_sup == 1 && diag == 1)
            cout<<"Matrice triunghiulara superior."<<endl;
        else
            if(tr_inf == 1 && tr_sup == 0 && diag == 1)
                cout<<"Matrice triunghiulara inferior."<<endl;
            else
                cout<<"Matricea nu este triunghiulara sau diagonala."<<endl;
    cout<<endl<<endl;

}
ostream& operator << (ostream& g, Matrice_patratica& M)
{
    cout<<endl<<endl;
    int k,l;
    for(k=0;k<M.Pi;k++)
    {
        for(l=0;l<M.Pj;l++)
        {
            cout<<M.Phopa[k][l]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    if(M.Pi == 1)
        cout<<"Determinantul este "<<M.Phopa[0][0]<<"."<<endl;
    else
        if(M.Pi == 2)
            cout<<"Determinantul este "<<M.Phopa[0][0]*M.Phopa[1][1]-M.Phopa[0][1]*M.Phopa[1][0]<<"."<<endl;
        else
            if(M.Pi == 3)
                cout<<"Determinantul este " <<M.Phopa[0][0]*M.Phopa[1][1]*M.Phopa[2][2]+M.Phopa[1][0]*M.Phopa[2][1]*M.Phopa[0][2]+M.Phopa[2][0]*M.Phopa[0][1]*M.Phopa[1][2]-(M.Phopa[0][2]*M.Phopa[1][1]*M.Phopa[2][0]+M.Phopa[1][0]*M.Phopa[0][1]*M.Phopa[2][2]+M.Phopa[0][0]*M.Phopa[2][1]*M.Phopa[1][2])<<"."<<endl;
    cout<<endl;
    return g;
}
