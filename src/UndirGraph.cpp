#include "../include/DirGraph.h"
#include "../include/UndirGraph.h"
#include <iostream>
using std::cout;
using std::endl;

UndirGraph::UndirGraph() : DirGraph() {}

// This parameter is composed of a source Node and destination Node.
// Since this is an undirected Graph, it also adds an Edge from dest to src.
void UndirGraph::AddEdge(const Edge &srcToDest) {
    Edge destToSrc(srcToDest.Dest(), srcToDest.Src(), srcToDest.Weight());

    // Checking to see if the Edge is already in the Graph.
    for (unsigned i = 0; i < edges.size(); i++) {
        if (srcToDest == edges.at(i) || destToSrc == edges.at(i)) {
            cout << "Edge: " << srcToDest.Src().Num() << " <-> " 
                 << srcToDest.Dest().Num() << " -- already in graph" << endl;
            return;
        } 
    }

    edges.push_back(srcToDest);
    edges.push_back(destToSrc);
}

// Creates an Edge from src to dest with both Node paramaters and adds it to 
// the Graph. Also creates an Edge from dest to src and adds to the Graph.
void UndirGraph::AddEdge(const Node &src, const Node &dest, int weight) {
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
            cout << "Edge: " << src.Num() << " <-> " << dest.Num()
                 << " -- already in graph" << endl;
            return;
        }
    }

    edges.push_back(srcToDest);        
    edges.push_back(destToSrc);
}

void UndirGraph::AddEdge(int x, int y, int weight) {
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
            cout << "Edge: " << src.Num() << " <-> " << dest.Num()
                 << " -- already in graph" << endl;
            return;
        }
    }

    edges.push_back(srcToDest);
    edges.push_back(destToSrc);
}