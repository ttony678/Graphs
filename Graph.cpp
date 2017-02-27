#include "Graph.h"
#include <iostream>
using std::cout;
using std::endl;

Graph::Graph() {}

void Graph::add_edge(Edge e) {
    edge.push_back(e);
}

void Graph::add_edge(Node x, Node y, int w) {
    Edge e(x, y, w);
    edge.push_back(e);
}

void Graph::add_edge(int x, int y, int w) {
    Node src(x);
    Node dest(y);
    Edge e(src, dest, w);
    edge.push_back(e);
}

void Graph::print() {
    for (unsigned i = 0; i < edge.size(); i++) {
        edge.at(i).print();
    }
}
