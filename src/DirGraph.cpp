#include "../include/DirGraph.h"
#include <iostream>
using std::cout;
using std::endl;

DirGraph::DirGraph() {}

void DirGraph::AddEdge(Edge e) {
    for (unsigned i = 0; i < edges.size(); i++) {
        if (e == edges.at(i)) {
            cout << "Edge: " << e.Src().Num() << "->" << e.Dest().Num()
                 << " -- already in graph" << endl;
            return;
        }
    }

    edges.push_back(e);
}

void DirGraph::AddEdge(Node src, Node dest, int weight) {
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
            return;
        }
    }

    edges.push_back(srcToDest);
}

void DirGraph::AddEdge(int x, int y, int weight) {
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
            return;
        }
    }

    edges.push_back(srcToDest);
}

void DirGraph::Print() {
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

void DirGraph::Bfs(Node startNode) {
    Node tempSrc;
    Node tempDest;
    Node frontNode;
    vector<Node> vstdNodes;
    queue<Node>  queue;

    if (edges.size() == 0) {
        cout << "Graph is empty" << endl;
        return;
    }

    queue.push(startNode);
    while (!queue.empty()) {
        frontNode = queue.front();
        queue.pop();
        vstdNodes.push_back(frontNode);
        cout << frontNode.Num() << endl;

        // This loop checks the source Node of every Edge in the Graph
        // and compares it with the front of the queue. If the front matches
        // matches any source Node, its destination Node is added to the queue
        // if it has not already been visited.
        for (unsigned int i = 0; i < edges.size(); i++) {
            tempSrc = edges.at(i).Src();
            tempDest = edges.at(i).Dest();
            if (frontNode == tempSrc && !isNodeVisited(tempDest, vstdNodes)) {
                queue.push(tempDest);
            }
        }
    }
}

void DirGraph::Dfs(Node startNode) {
    Node tempSrc;
    Node tempDest;
    Node topNode;
    vector<Node> vstdNodes;
    stack<Node>  stack;

    if (edges.size() == 0) {
        cout << "Graph is empty" << endl;
        return;
    }

    stack.push(startNode); // Pushing starting Node twice or else it'll be
    stack.push(startNode); // popped off too soon in the loop.
    vstdNodes.push_back(startNode);
    cout << startNode.Num() << endl;

    while (!stack.empty()) {
        stack.pop();
        if (stack.empty())
            return;

        // This loop compares the source Node with what is at the top of 
        // the stack. If the Node matches, the destination Node is checked
        // in case it has already been visited. If not, it is added to the 
        // stack, set as visited, and set as the new top Node. It continues
        // the iterations until the top Node doesn't have an Edge connecting
        // to some destination Node. 
        topNode = stack.top();
        for (unsigned int i = 0; i < edges.size(); i++) {
            tempSrc = edges.at(i).Src();
            tempDest = edges.at(i).Dest();
            if (topNode == tempSrc && !isNodeVisited(tempDest, vstdNodes)) {
                cout << tempDest.Num() << endl;
                vstdNodes.push_back(tempDest);
                stack.push(tempDest);
                topNode = tempDest;
                i = 0;
            }
        }
    }
}

// This function checks to see if a Node has already been visited
bool DirGraph::isNodeVisited(Node check, vector<Node> vNodes) {
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
