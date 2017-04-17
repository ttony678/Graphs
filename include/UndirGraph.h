#ifndef UNDIRGRAPH_H
#define UNDIRGRAPH_H
#include "DirGraph.h"
#include "Edge.h"
using namespace std;

class UndirGraph : public DirGraph {
    public:
        UndirGraph();
        void AddEdge(Edge);
        void AddEdge(Node, Node, int weight = 1);
        void AddEdge(int, int, int weight = 1);
};

#endif