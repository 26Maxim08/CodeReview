#pragma once

#include <iostream>

using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node(int value);

    friend class Stack; 
};

class Stack {
    Node* top;

public:
    Stack();
    ~Stack();
    void push(int value);
    void pop();
    void print() const;
    Node* getTop();

    friend void addElementAndPrintAddress(Stack& stack, int D);
};

void addElementAndPrintAddress(Stack& stack, int D);

bool appWork(Stack& stack);
