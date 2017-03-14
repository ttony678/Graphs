#include "../include/Node.h"

Node::Node() {
    num = 0;
}

Node::Node(int x) {
    num = x;
}

void Node::set_num(int x) {
    num = x;
}

int Node::get_num() const {
    return num;
}

bool Node::operator == (const Node &x) {
    if (num == x.get_num()) {
        return true;
    }
    else {
        return false;
    }
}

bool Node::operator != (const Node &x) {
    return !operator == (x);
}
