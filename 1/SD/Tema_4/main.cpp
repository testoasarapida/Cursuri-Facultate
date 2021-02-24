#include <iostream>
using namespace std;

struct nod
{
    int a;
    nod *st;
    nod *dr;
    nod(int a, nod *st = NULL, nod *dr = NULL) : a(a), st(st), dr(dr){}
};
typedef nod *Binar;

Binar creeaza()
{
    return NULL;
}

void inserare(Binar& A, int valoare)
{
    if(A == NULL)
        A = new nod(valoare);
    else
    {
        if(valoare < A->a)
            if(A->st != NULL)
                inserare(A->st, valoare);
            else
                A->st = new nod(valoare);
        if(valoare > A->a)
            if(A->dr != NULL)
                inserare(A->dr, valoare);
            else
                A->dr = new nod(valoare);
    }
}

int cautare(Binar& A, int valoare)
{
    if(A == NULL)
        return 0;
    if(A->a == valoare)
        return 1;
    if(A->a < valoare)
        return cautare(A->st, valoare);
    else
        return cautare(A->dr, valoare);
}

void sterge(Binar& A, int valoare)
{
    if(A != NULL)
    {
        int ok = cautare(A, valoare);
        if(ok)
        {
            if(A != NULL)
            {
                Binar B;
                B = A;
                if(B->dr != NULL)
                {
                    A = B->dr;
                    if(B->st != NULL)
                    {
                        Binar C = B->dr;
                        while(C->st != NULL)
                            C = C->st;
                        C->st = B->st;
                    }
                }
                else
                    if(B->st != NULL)
                        A = B->st;
                    else
                        A = NULL;
                delete B;
            }
        }
    }
}
void SRD(Binar& A)
{
    if(A != NULL)
    {
        SRD(A->st);
        cout<<A->a<<" ";
        SRD(A->dr);
    }
}

void RSD(Binar& A)
{
    if(A != NULL)
    {
        cout<<A->a<<" ";
        RSD(A->st);
        RSD(A->dr);
    }
}


int main()
{
    Binar A;
    A = creeaza();
    int i, n, x;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>x;
        inserare(A, x);
    }
    cout<<endl<<endl<<"Rezultat cautare element: "<<cautare(A, 1)<<endl<<endl<<endl<<"Stergere element"<<endl<<endl<<endl;
    sterge(A, 1);
    cout<<"SRD: ";
    SRD(A);
    cout<<endl<<"RSD: ";
    RSD(A);
    return 0;
}
