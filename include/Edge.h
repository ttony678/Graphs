#ifndef EDGE_H
#define EDGE_H
#include "Node.h"

class Edge {
    public:
        Edge();
        Edge(const Node&, const Node&, int weight = 0);
        Edge(int, int, int weight = 0);
        Node Src() const;       // Get src.
        Node Dest() const;      // Get dest.
        int  Weight() const;    // Get weight.
        void Print() const;     // Print all edges.
        void operator =  (const Edge&);
        bool operator <  (const Edge&) const;
        bool operator == (const Edge&) const;

    private:
        Node src;
        Node dest;
        int  weight;
};

#endif
