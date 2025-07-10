/**
@file Node.cpp
@brief Реализация операций с узлами дерева
*/

#include "Node.h"

Node::Node(const string& val) : value(val), left(nullptr), right(nullptr) {}

Node::~Node() {
    delete left;
    delete right;
}

int Node::evaluate(int x) const {
    if (!left && !right) {
        if (value == "x") return x;
        return stoi(value);
    }
    
    int leftVal = left ? left->evaluate(x) : 0;
    int rightVal = right ? right->evaluate(x) : 0;
    
    if (value == "+") return leftVal + rightVal;
    if (value == "-") return leftVal - rightVal;
    if (value == "*") return leftVal * rightVal;
    if (value == "/") return leftVal / rightVal;
    if (value == "%") return leftVal % rightVal;
    if (value == "^") return static_cast<int>(pow(leftVal, rightVal));
    
    return 0;
}

void Node::transform() {
    if (left) left->transform();
    if (right) right->transform();
    
    if (value == "*" && left && left->value == "x" && right && right->value != "x") {
        swap(left, right);
    }
}

void Node::print(ostream& out, int depth) const {
    if (right) right->print(out, depth + 1);
    out << setw(depth * 4) << "" << value << endl;
    if (left) left->print(out, depth + 1);
}