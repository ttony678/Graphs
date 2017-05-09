#include "../include/Edge.h"
#include <iostream>
using std::cout;
using std::endl;

Edge::Edge() {
    src.Num(0);
    dest.Num(0);
}

Edge::Edge(const Node &x, const Node &y, int w) {
    src = x;
    dest = y;
    weight = w;
}

Edge::Edge(int x, int y, int w) {
    src.Num(x);
    dest.Num(y);
    weight = w;
}

Node Edge::Src() const {
    return src;
}

Node Edge::Dest() const {
    return dest;
}

int Edge::Weight() const {
    return weight;
}

void Edge::Print() const {
    cout << "SRC: " << src.Num() << " -> DEST: " << dest.Num() << endl;
}

void Edge::operator = (const Edge &rhs) {
    src = rhs.Src();
    dest = rhs.Dest();
    weight = rhs.Weight();
}

bool Edge::operator < (const Edge &rhs) const {
    if (weight < rhs.Weight()) {
        return true;
    } else {
        return false;
    }
}

bool Edge::operator == (const Edge &rhs) const {
    if (src == rhs.Src() && dest == rhs.Dest() && weight == rhs.Weight()) {
        return true;
    } else {
        return false;
    }
}
