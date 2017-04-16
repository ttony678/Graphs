#ifndef EDGE_H
#define EDGE_H
#include "Node.h"

class Edge {
    public:
        Edge();
        Edge(Node, Node, int weight = 0);
        Edge(int, int, int weight = 0);
        Node Src() const;
        Node Dest() const;
        int  Weight() const;
        void Print();
        void operator =  (const Edge&);
        bool operator <  (const Edge&);
        bool operator == (const Edge&);

    private:
        Node src;
        Node dest;
        int  weight;
};

#endif
