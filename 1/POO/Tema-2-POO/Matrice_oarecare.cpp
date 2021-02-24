#include "Matrice_oarecare.h"
#include "Vectorul.h"

Matrice_oarecare::Matrice_oarecare(int o, int i, int j) :Matricea(o), i(i), j(j)
{
    cout<<"S-a apelat clasa Matrice_oarecare."<<endl;
}

Matrice_oarecare::~Matrice_oarecare()
{
    int k,l;
    for(k=0;k<this->i;k++)
        for(l=0;l<this->j;l++)
            this->hopa[k][l] = NULL;
    this->i = NULL;
    this->j = NULL;
    this->contor = NULL;
    cout<<"Toate informatiile din clasa Matrice_oarecare au fost sterse."<<endl;
}

Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare& other1): Matricea(other1), i(other1.i), j(other1.j)
{
    cout<<"cc S-a apelat clasa Matrice_oarecare.";
}

void Matrice_oarecare::incarcavector(Vectorul& I)
{
    this->m = I;
    this->incarcamatrice(contor);
    this->contor++;
}
void Matrice_oarecare::incarcamatrice(int contorul)
{
    int k=0;
    for(k=0;k<this->j;k++)
        this->hopa[contorul][k] = this->m.aduyayy(k);
}
void Matrice_oarecare::incarcadimensiuni(int k,int l)
{
    this->i = k;
    this->j = l;
}
void Matrice_oarecare::verifica()
{
    int k,l,tr_inf=0,tr_sup=0,diag=1;
    for(k=0;k<this->i;k++)
        for(l=0;l<this->j;l++)
            if(k>l && this->hopa[k][l] != 0)
                tr_inf = 1;
            else
                if(l>k && this->hopa[k][l] != 0)
                    tr_sup = 1;
                else
                    if(l==k && this->hopa[k][l] == 0)
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
ostream& operator << (ostream& g, Matrice_oarecare& M)
{
    cout<<endl<<endl;
    int k,l;
    for(k=0;k<M.i;k++)
    {
        for(l=0;l<M.j;l++)
        {
            cout<<M.hopa[k][l]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return g;
}

