#include "../include/Graph.h"
#include <iostream>
using std::cout;
using std::endl;

Graph::Graph() {}

void Graph::add_edge(Edge e) {
    bool present = false;

    for (unsigned i = 0; i < edges.size(); i++) {
        if (e.get_src() == edges.at(i).get_src() && e.get_dest() == edges.at(i).get_dest()) {
            cout << "Edge: " << e.get_src().get_num() << "->" << e.get_dest().get_num()
                 << " -- already in graph" << endl;
            present = true;
        }
    }

    if (!present) {
        edges.push_back(e);
    }
}

void Graph::add_edge(Node x, Node y, int w) {
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
    }
}

void Graph::add_edge(int x, int y, int w) {
    Node src(x);
    Node dest(y);
    Edge e(src, dest, w);
    edges.push_back(e);
}

void Graph::print() {
    cout << endl;

    if (edges.size() > 0) {
        for (unsigned i = 0; i < edges.size(); i++) {
            edges.at(i).print();
        }
    }
    else {
        cout << "Graph is empty" << endl;
    }
}

void Graph::bfs(Node begin) {
    vector<Node> visited;
    queue<Node> breadth;

    if (edges.size() == 0) {
        cout << "Graph is empty" << endl;
        return;
    }

    breadth.push(begin);

    while (!breadth.empty()) {
        Node temp = breadth.front();
        visited.push_back(temp);
        breadth.pop();

        cout << temp.get_num() << endl;

        // This loop checks the source Node 'src' of every Edge in the graph
        // and compares it with the front of the 'breadth' queue. If the front matches
        // any source Node, the corresponding destination 'dest' Node is added
        // to the queue.
        for (unsigned int i = 0; i < edges.size(); i++) {
            if (edges.at(i).get_src() == temp) {
                if (!node_visited(edges.at(i).get_dest(), visited)) {
                    breadth.push(edges.at(i).get_dest());
                }
            }
        }
    }
}

void Graph::dfs(Node begin) {
    vector<Node> visited;
    stack<Node> stk;

    if (edges.size() == 0) {
        cout << "Graph is empty" << endl;
        return;
    }

    stk.push(begin); // Pushing 'begin' Node twice for all its adjacent Nodes
    stk.push(begin); // or else it'll be popped off too soon in the loop.
    visited.push_back(begin);
    cout << begin.get_num() << endl;

    while (!stk.empty()) {
        stk.pop();
        if (stk.empty())
            return;

        // This loop iterates through every edge in the graph and compares the
        // 'src' node with what is at the top of the stack initially. Once an
        // adjacent node is found (the 'dest' node), it is pushed to the
        // visited vector and the top of the stack, and then set as the new top
        // variable which keeps traversing deeper and deeper. It keeps going
        // through the graph by resetting the counter variable i to zero
        // afterwards.
        Node top = stk.top();
        for (unsigned int i = 0; i < edges.size(); i++) {
            Node temp = edges.at(i).get_src();
            if (top == temp && !node_visited(edges.at(i).get_dest(), visited)) {
                temp = edges.at(i).get_dest();
                cout << temp.get_num() << endl;
                visited.push_back(temp);
                stk.push(temp);
                top = temp;
                i = 0;
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
