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
    Node g(7);
    Node h(8);
    Node i(9);

    Edge ab(a, b);
    Edge ac(a, c);
    Edge bd(b, d);
    Edge be(b, e);
    Edge bf(b, f);
    Edge fg(f, g);
    Edge dh(d, h);
    Edge di(d, i);

    Graph x;
    x.add_edge(ab);
    x.add_edge(ac);
    x.add_edge(bd);
    x.add_edge(be);
    x.add_edge(bf);
    x.add_edge(fg);
    x.add_edge(dh);
    x.add_edge(di);
    x.print();

    cout << endl;

    x.dfs(a);

    return 0;
}
