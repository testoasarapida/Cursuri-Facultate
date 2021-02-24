#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include <list>
using namespace std;

class directedGraph
{
    int numar;
    list<int> lista_adiacente[10001];
    public:
        directedGraph();
        virtual ~directedGraph();
        directedGraph(const directedGraph& other);

        void addNode(int);
        void addEdge(int, int);
        int hasEdge(int, int);
        void BFS(int);
        void start_DFS(int);
        void DFS(int, int*);
};

#endif // DIRECTEDGRAPH_H
