#include <iostream>
using namespace std;
int main()
{
    int i,v[100],v_sortat[100],f[11]={0},n,s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        f[v[i]]++;
    }
    s = f[0];
    for(i=0;i<=9;i++)
    {
        f[i]=s;
        s=s+f[i+1];
    }
    for(i=0;i<n;i++)
    {
        v_sortat[f[v[i]]]=v[i];
        f[v[i]]--;
    }
    for(i=1;i<=n;i++)
        cout<<v_sortat[i]<<" ";
    return 0;
}
