#include <iostream>
#include "../include/Graph.h"
#include "../include/Undir_Graph.h"
using namespace std;

int main() {

    Node a(1);
    Node b(2);
    Node c(3);
    Node d(4);
    Node e(5);
    Node f(6);
   

    Edge ab(a, b);
    Edge ac(a, c);
    Edge bd(b, d);
    Edge be(b, e);
    Edge bf(b, f);
  

    Graph x;
    x.AddEdge(ab);
    x.AddEdge(ac);
    x.AddEdge(bd);
    x.AddEdge(be);
    x.AddEdge(bf);
    x.Print();

    cout << endl;
    x.Dfs(a);
    cout << endl;
    x.Bfs(a);

    return 0;
}
