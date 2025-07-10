#include "Queue.h"

Node::Node(int value) : data(value), next(nullptr) {}

Queue::Queue():head(nullptr), tail(nullptr) {}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Очередь пуста!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
}

bool Queue::isEmpty() {
    return head == nullptr;
}

void Queue::print() {
    if (isEmpty()) {
        cerr << "Очередь пуста!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int* Queue::getHead(){
    if (isEmpty()) {
        cerr << "Очередь пуста!" << endl;
        return nullptr; 
    }
    
    return &head->data;
}

int* Queue::getTail() {
    if (isEmpty()) {
        cerr << "Очередь пуста!" << endl;
        return nullptr;
    }
    return &tail->data;
}

int correctinput(int index) {
    cout << "Число " << index << ": ";
    int value;
    while (true) {
        cin >> value;
        if (cin.good()) {
            return value;
        } else {
            cerr<< "Ошибка! Введите число!\n";
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Число " << index << ": ";
        }
    }
}