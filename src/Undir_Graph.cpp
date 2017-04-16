#include "../include/Graph.h"
#include "../include/Undir_Graph.h"
#include <iostream>
using std::cout;
using std::endl;

Undir_Graph::Undir_Graph() : Graph() {}

// This parameter is composed of a source Node and destination Node.
// Since this is an undirected Graph, it also adds an Edge from dest to src.
void Undir_Graph::AddEdge(Edge srcToDest) {
    bool present = false;
    Edge destToSrc(srcToDest.Dest(), srcToDest.Src(), srcToDest.Weight());

    // Checking to see if the Edge is already in the Graph.
    for (unsigned i = 0; i < edges.size(); i++) {
        if (srcToDest == edges.at(i) || destToSrc == edges.at(i)) {
            cout << "Edge: " << srcToDest.Src().Num() << "<->" 
                 << srcToDest.Dest().Num() << " -- already in graph" << endl;
            present = true;
        }
    }

    if (!present) {
        edges.push_back(srcToDest);
        edges.push_back(destToSrc);
    }
}

// Creates an Edge from src to dest with both Node paramaters and adds it to 
// the Graph. Also creates an Edge from dest to src and adds to the Graph.
void Undir_Graph::AddEdge(Node src, Node dest, int weight) {
    bool present = false;
    Edge srcToDest(src, dest, weight);
    Edge destToSrc(dest, src, weight);

    // Checking if both Nodes are the same.
    if (src == dest) {
        cout << "Cannot create an Edge with two of the same Nodes" << endl;
        return;
    }

    // Checking if Edge created by both Node Paramaters is already in
    // the Graph.
    for (unsigned i = 0; i < edges.size(); i++) {
        if (srcToDest == edges.at(i) || destToSrc == edges.at(i)) {
            cout << "Edge: " << src.Num() << "<->" << dest.Num()
                 << " -- already in graph" << endl;
            present = true;
        }
    }

    if (!present) {
        edges.push_back(srcToDest);        
        edges.push_back(destToSrc);
    }
}

void Undir_Graph::AddEdge(int x, int y, int weight) {
    bool present = false;
    Node src(x);
    Node dest(y);
    Edge srcToDest(src, dest, weight);
    Edge destToSrc(dest, src, weight);

    // Checking if both Nodes are the same.
    if (src == dest) {
        cout << "Cannot create an Edge with two of the same Nodes" << endl;
        return;
    }

    // Checking if Edge created by both Node Paramaters is already in
    // the Graph.
    for (unsigned i = 0; i < edges.size(); i++) {
        if (srcToDest == edges.at(i) || destToSrc == edges.at(i)) {
            cout << "Edge: " << src.Num() << "<->" << dest.Num()
                 << " -- already in graph" << endl;
            present = true;
        }
    }

    if (!present) {
        edges.push_back(srcToDest);
        edges.push_back(destToSrc);
    }
}