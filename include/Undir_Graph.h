#ifndef UNDIR_GRAPH_H
#define UNDIR_GRAPH_H
#include "Graph.h"
#include "Edge.h"
using namespace std;

class Undir_Graph : public Graph {
    public:
        Undir_Graph();
        void AddEdge(Edge);
        void AddEdge(Node, Node, int weight = 1);
        void AddEdge(int, int, int weight = 1);
};

#endif