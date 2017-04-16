#include "../include/Node.h"

Node::Node() {
    num = 0;
}

Node::Node(int x) {
    num = x;
}

void Node::Num(int x) {
    num = x;
}

int Node::Num() const {
    return num;
}

void Node::operator = (const Node &rhs) {
    num = rhs.Num();
}

bool Node::operator == (const Node &rhs) {
    if (num == rhs.Num()) {
        return true;
    }
    else {
        return false;
    }
}

bool Node::operator != (const Node &rhs) {
    return !(operator == (rhs));
}
