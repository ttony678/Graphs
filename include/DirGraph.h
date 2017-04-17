#ifndef DIRGRAPH_H
#define DIRGRAPH_H
#include "Edge.h"
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class DirGraph {
    public:
        DirGraph();
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
