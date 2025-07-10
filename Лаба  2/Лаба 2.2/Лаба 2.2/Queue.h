#include <iostream>

using namespace std;

class Node {
    int data;
    Node* next;
public:
    Node(int value);
    friend class Queue;
};


class Queue {
    Node* head;
    Node* tail;
public:
    Queue();
    void enqueue(int value);
    void dequeue();
    bool isEmpty();
    void print();
    int* getHead();
    int* getTail();
};

int correctinput(int index);