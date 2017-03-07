#include <iostream>
#include "../include/Graph.h"
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
    Edge cf(c, f);

    Graph g;
    g.add_edge(ab);
    g.add_edge(ac);
    g.add_edge(bd);
    g.add_edge(be);
    g.add_edge(cf);
    g.print();

    return 0;
}
