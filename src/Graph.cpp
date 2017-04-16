#include "../include/Graph.h"
#include <iostream>
using std::cout;
using std::endl;

Graph::Graph() {}

void Graph::AddEdge(Edge e) {
    bool present = false;

    for (unsigned i = 0; i < edges.size(); i++) {
        if (e == edges.at(i)) {
            cout << "Edge: " << e.Src().Num() << "->" << e.Dest().Num()
                 << " -- already in graph" << endl;
            present = true;
        }
    }

    if (!present) {
        edges.push_back(e);
    }
}

void Graph::AddEdge(Node src, Node dest, int weight) {
    bool present = false;
    Edge srcToDest(src, dest, weight);

    // Checking if both Nodes are the same.
    if (src == dest) {
        cout << "Cannot create an Edge with two of the same Nodes" << endl;
        return;
    }

    for (unsigned i = 0; i < edges.size(); i++) {
        if (srcToDest == edges.at(i)) {
            cout << "Edge: " << src.Num() << "->" << dest.Num()
                 << " -- already in graph" << endl;
            present = true;
        }
    }

    if (!present) {
        edges.push_back(srcToDest);
    }
}

void Graph::AddEdge(int x, int y, int weight) {
    bool present = false;
    Node src(x);
    Node dest(y);
    Edge srcToDest(src, dest, weight);

    // Checking if both Nodes are the same.
    if (src == dest) {
        cout << "Cannot create an Edge with two of the same Nodes" << endl;
        return;
    }

    // Checking if Edge is already in the Graph.
    for (unsigned i = 0; i < edges.size(); i++) {
        if (srcToDest == edges.at(i)) {
            cout << "Edge: " << src.Num() << "->" << dest.Num()
                 << " -- already in graph" << endl;
            present = true;
        }
    }

    if (!present) {
        edges.push_back(srcToDest);
    }
}

void Graph::Print() {
    cout << endl;

    if (edges.size() > 0) {
        for (unsigned i = 0; i < edges.size(); i++) {
            edges.at(i).Print();
        }
    }
    else {
        cout << "Graph is empty" << endl;
    }
}

void Graph::Bfs(Node begin) {
    vector<Node> visited;
    queue<Node> breadth;

    if (edges.size() == 0) {
        cout << "Graph is empty" << endl;
        return;
    }

    breadth.push(begin);

    while (!breadth.empty()) {
        Node front = breadth.front();
        visited.push_back(front);
        breadth.pop();

        cout << front.Num() << endl;

        // This loop checks the source Node 'src' of every Edge in the graph
        // and compares it with the front of the 'breadth' queue. If the front
        // matches any source Node, the corresponding destination 'dest' Node
        // is added to the queue.
        for (unsigned int i = 0; i < edges.size(); i++) {
            Node temp = edges.at(i).Src();
            if (front == temp && !isNodeVisited(edges.at(i).Dest(), visited)) {
                breadth.push(edges.at(i).Dest());
            }
        }
    }
}

void Graph::Dfs(Node begin) {
    vector<Node> visited;
    stack<Node> stk;

    if (edges.size() == 0) {
        cout << "Graph is empty" << endl;
        return;
    }

    stk.push(begin); // Pushing 'begin' Node twice for all its adjacent Nodes
    stk.push(begin); // or else it'll be popped off too soon in the loop.
    visited.push_back(begin);
    cout << begin.Num() << endl;

    while (!stk.empty()) {
        stk.pop();
        if (stk.empty())
            return;

        // This loop iterates through every edge in the graph. Then it compares
        // the 'src' Node with what is initially pushed to the top of the stack 
        // (begin). Once an adjacent Node is found, it (the 'dest' Node) is
        // pushed to the visited vector and the top of the stack. It is then 
        // set as the new top variable which keeps traversing deeper and 
        // deeper. It keeps going through the graph by setting the counter 
        // variable i=0 afterwards.
        Node top = stk.top();
        for (unsigned int i = 0; i < edges.size(); i++) {
            Node temp = edges.at(i).Src();
            if (top == temp && !isNodeVisited(edges.at(i).Dest(), visited)) {
                temp = edges.at(i).Dest();
                cout << temp.Num() << endl;
                visited.push_back(temp);
                stk.push(temp);
                top = temp;
                i = 0;
            }
        }
    }
}

// This function checks to see if a Node has already been visited
bool Graph::isNodeVisited(Node check, vector<Node> vNodes) {
    if (vNodes.size() == 0) {
        return false;
    }
    else {
        for (unsigned i = 0; i < vNodes.size(); i++) {
            if (check == vNodes.at(i)) {
                return true;
            }
        }
    }
    return false;
}
