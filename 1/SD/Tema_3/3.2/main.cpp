#include <iostream>
using namespace std;
struct arbore
{
    int n,v[100];
};
arbore hippyfy(arbore A,int n,int i)
{
    int mic = i;
    int stanga = 2*i+1;
    int dreapta = 2*i+2;
    if(stanga < n && A.v[stanga] < A.v[mic])
        mic = stanga;
    if(dreapta < n && A.v[dreapta] < A.v[mic])
        mic = dreapta;
    if(mic != i)
    {
        swap(A.v[mic],A.v[i]);
        return hippyfy(A,n,mic);
    }
    else
        return A;
}
arbore sortare(arbore A,int n)
{
    n--;
    while(n>0)
    {
        swap(A.v[0],A.v[n]);
        A = hippyfy(A,n,0);
        n--;
    }
    return A;
}
int main()
{
    arbore A;
    int i,j;
    cin>>A.n;
    for(i=0;i<A.n;i++)
        cin>>A.v[i];

    cout<<"hippiyfy"<<endl;
    for(i = A.n/2-1; i>=0; i--)
        A = hippyfy(A,A.n,i);

    for(i=0;i<A.n;i++)
        cout<<A.v[i]<<" ";

    cout<<endl<<"sortare"<<endl;
    A = sortare(A,A.n);
    for (i=0,j=A.n-1;i<j;i++,j--)
        swap(A.v[i],A.v[j]);

    for(i=0;i<A.n;i++)
        cout<<A.v[i]<<" ";
    return 0;
}
