#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    public:
        Graph();
        void AddEdge(Edge);
        void AddEdge(Node, Node, int weight = 1);
        void AddEdge(int, int, int weight = 1);
        void Print();
        void Bfs(Node);
        void Dfs(Node);

    protected:
        vector<Edge> edges;

    private:
        bool isNodeVisited(Node, vector<Node>);
};

#endif
