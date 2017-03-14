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
    queue<Node> breadth;

    if (edge.size() == 0) {
        cout << "Graph is empty" << endl;
        return;
    }

    breadth.push(begin);
    visited.push_back(begin);

    while (!breadth.empty()) {
        Node temp = breadth.front();
        cout << temp.get_num() << endl;
        breadth.pop();

        // This loop checks the source Node of each Edge and compares it with
        // the front of the 'breadth' queue. If it finds a source Node that
        // matches, it adds the found Node to the queue and to the
        // 'visited' vector.
        for (unsigned int i = 0; i < edge.size(); i++) {
            if (edge.at(i).get_src() == temp) {
                if (!node_visited(edge.at(i).get_dest(), visited)) {
                    breadth.push(edge.at(i).get_dest());
                    visited.push_back(edge.at(i).get_dest());
                }
            }
        }
    }
}

// This function checks to see if a Node has already been visited
bool Graph::node_visited(Node x, vector<Node> v) {
    if (v.size() == 0) {
        return false;
    }
    else {
        for (unsigned i = 0; i < v.size(); i++) {
            if (x == v.at(i)) {
                return true;
            }
        }
    }
    return false;
}
