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
        void AddEdge(const Edge&);
        void AddEdge(const Node&, const Node&, int weight = 1);
        void AddEdge(int, int, int weight = 1);
        void Print() const;
        void Bfs(Node) const;
        void Dfs(Node) const;

    protected:
        vector<Edge> edges;

    private:
        bool isNodeVisited(Node, vector<Node>) const;
};

#endif
