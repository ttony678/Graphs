#include "../include/Graph.h"
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
    if (edge.size() > 0) {
        for (unsigned i = 0; i < edge.size(); i++) {
            edge.at(i).print();
        }
    }
    else {
        cout << "Graph is empty" << endl;
    }
}

void Graph::dfs(Node begin) {
    vector<Node> visited;
    queue<Node> q;

    for (unsigned int i = 0; i < edge.size(); i++) {
        if (edge.at(i).get_src() == begin) {
            for (unsigned int k = 0; k < visited.size(); k++) {
                
            }
            visited.push_back(edge.at(i).get_src());
        }
    }
}
