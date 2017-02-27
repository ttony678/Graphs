#ifndef EDGE_H
#define EDGE_H
#include "Node.h"

class Edge {
    private:
        Node src, dest;
        int weight;
    public:
        Edge();
        Edge(Node, Node, int i = 0);
        Edge(int, int, int i = 0);
        void print();
};

#endif
