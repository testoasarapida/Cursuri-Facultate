#include <iostream>
using namespace std;
struct arbore
{
    int n,v[100];
};
arbore stergere_varf(arbore A)
{
    int i=0,j;
    while( (2*i+1<A.n) || (2*i+2<A.n) )
        if(A.v[2*i+1] < A.v[2*i+2])
        {
            swap(A.v[i],A.v[2*i+1]);
            i=2*i+1;
        }
        else
        {
            swap(A.v[i],A.v[2*i+2]);
            i=2*i+2;
        }
    for(j=i;j<A.n;j++)
        A.v[j]=A.v[j+1];
    A.n--;
    return A;
}

arbore inserare(arbore A, int x)
{
    int i=A.n;
    A.v[A.n]=x;
    A.n++;
    while(A.v[(i-1)/2] > A.v[i])
    {
        swap(A.v[i],A.v[(i-1)/2]);
        i = (i-1)/2;
        if(i<1)
            break;
    }
    return A;
}
int main()
{
    arbore A;
    int i,x;

    //citire heap
    cin>>A.n;
    for(i=0;i<A.n;i++)
        cin>>A.v[i];

    cout<<"stergerea minimului"<<endl;
    A = stergere_varf(A);
    for(i=0;i<A.n;i++)
        cout<<A.v[i]<<" ";
    cout<<endl;

    cout<<"inserare element"<<endl;
    cin>>x;
    A = inserare(A,x);
    for(i=0;i<A.n;i++)
        cout<<A.v[i]<<" ";
    return 0;
}
