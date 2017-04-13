#include "../include/Graph.h"
#include "../include/Undir_Graph.h"
#include <iostream>
using std::cout;
using std::endl;

Undir_Graph::Undir_Graph() : Graph() {}

void Undir_Graph::add_edge(Edge e) {
    bool present = false;

    for (unsigned i = 0; i < edges.size(); i++) {
        if (e.get_src() == edges.at(i).get_src() && e.get_dest() == edges.at(i).get_dest()) {
            cout << "Edge: " << e.get_src().get_num() << "->" << e.get_dest().get_num()
                 << " -- already in graph" << endl;
            present = true;
        }
    }

    if (!present) {
        Edge other(e.get_dest(), e.get_src());
        edges.push_back(e);
        edges.push_back(other);
    }
}

void Undir_Graph::add_edge(Node x, Node y, int w) {
    bool present = false;

    for (unsigned i = 0; i < edges.size(); i++) {
        if (x == edges.at(i).get_src() && y == edges.at(i).get_dest()) {
            cout << "Edge: " << x.get_num() << "->" << y.get_num()
                 << " -- already in graph" << endl;
            present = true;
        }

    }

    if (!present) {
        Edge e(x, y, w);
        edges.push_back(e);

        Edge other(y, x, w);
        edges.push_back(other);
    }
}