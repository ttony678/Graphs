#ifndef UNDIR_GRAPH_H
#define UNDIR_GRAPH_H
#include "Graph.h"
#include "Edge.h"
using namespace std;

class Undir_Graph : public Graph {
    public:
        Undir_Graph();
        void add_edge(Edge);
        void add_edge(Node, Node, int i = 0);
};

#endif