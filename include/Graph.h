#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include <vector>
using namespace std;

class Graph {
    private:
        vector<Edge> edge;
    public:
        Graph();
        void add_edge(Edge);
        void add_edge(Node, Node, int i = 0);
        void add_edge(int, int, int i = 0);
        void print();
};

#endif
