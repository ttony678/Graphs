#include "Node.h"

Node::Node() {
    num = 0;
}

Node::Node(int x) {
    num = x;
}

void Node::set_num(int x) {
    num = x;
}

int Node::get_num() {
    return num;
}
