#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Node {
    int data;
    Node* next;
public:
    Node(int value);
    friend class List;
};

class List {
    Node* head;
public:
    List();
    bool isEmpty();
    void push(int value);
    void pop();
    void print();
    void readFromFile(const string filename);
};