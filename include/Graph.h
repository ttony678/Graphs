#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    protected:
        vector<Edge> edges;
    private:
        bool node_visited(Node, vector<Node>);
    public:
        Graph();
        void add_edge(Edge);
        void add_edge(Node, Node, int i = 0);
        void add_edge(int, int, int i = 0);
        void print();
        void bfs(Node);
        void dfs(Node);
};

#endif
