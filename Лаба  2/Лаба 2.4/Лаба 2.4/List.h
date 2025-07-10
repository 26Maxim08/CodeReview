#pragma once

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value);
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List();
    ~List();

    void push(int value);
    void pop(int value);
    void print();
    void printBetweenMinMax() const;
};

