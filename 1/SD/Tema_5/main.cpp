#include <iostream>
#include "directedGraph.h"
using namespace std;

int main()
{
    directedGraph G;
    int n, m, i, source, target;

    cout<<"Dati numarul de noduri: ";
    cin>>n;
    G.addNode(n);

    cout<<"Dati numarul de muchii: ";
    cin>>m;
    for(i = 0; i < m; i++)
    {
        cout<<"Citeste pereche: ";
        cin>>source>>target;
        G.addEdge(source, target);
    }

    cout<<"BFS: ";
    G.BFS(2);
    cout<<endl;

    cout<<"DFS: ";
    G.start_DFS(2);
    cout<<endl;
}
