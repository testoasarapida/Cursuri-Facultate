#include "directedGraph.h"
#include <iostream>
#include <list>
using namespace std;

directedGraph::directedGraph()
{
    this->numar = 0;
}

directedGraph::~directedGraph()
{
    this->numar = NULL;
}

directedGraph::directedGraph(const directedGraph& other)
{
    this->numar = other.numar;
}

void directedGraph::addNode(int a)
{
    this->numar = a;
}

void directedGraph::addEdge(int source, int target)
{
    this->lista_adiacente[source].push_back(target);
}

int directedGraph::hasEdge(int source, int target)
{
    list<int>::iterator i;
    for(i = this->lista_adiacente[source].begin(); i != this->lista_adiacente[source].end(); i++)
        if(*i == target)
            return 1;
    return 0;
}

void directedGraph::BFS(int startNode)
{
    int v[this->numar] = {0};
    list<int> coada;
    v[startNode] = 1;
    coada.push_back(startNode);
    list<int>::iterator i;
    while(!(coada.empty()))
    {
        startNode = coada.front();
        cout<<startNode<<" ";
        coada.pop_front();
        for(i = this->lista_adiacente[startNode].begin(); i != this->lista_adiacente[startNode].end(); i++)
            if(v[*i] == 0)
            {
                v[*i] = 1;
                coada.push_back(*i);
            }
    }
}

void directedGraph::start_DFS(int startNode)
{
    int v[this->numar] = {0};
    DFS(startNode, v);
}

void directedGraph::DFS(int startNode, int v[])
{
    v[startNode] = 1;
    cout<<startNode<<" ";
    list<int>::iterator i;
    for(i = this->lista_adiacente[startNode].begin(); i != this->lista_adiacente[startNode].end(); i++)
        if(v[*i] == 0)
            DFS(*i, v);
}

