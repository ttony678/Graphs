#include "Edge.h"
#include <iostream>
using std::cout;
using std::endl;

Edge::Edge() {
    src.set_num(0);
    dest.set_num(0);
}

Edge::Edge(Node x, Node y, int w) {
    src = x;
    dest = y;
    weight = w;
}

Edge::Edge(int x, int y, int w) {
    src.set_num(x);
    dest.set_num(y);
    weight = w;
}

void Edge::print() {
    cout << "SRC: " << src.get_num() << " -> DEST: " << dest.get_num() << endl;
}
