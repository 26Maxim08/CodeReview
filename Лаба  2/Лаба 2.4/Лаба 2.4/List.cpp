#include "List.h"

using namespace std;

// ����������� ����
Node::Node(int value) : data(value), prev(nullptr), next(nullptr) {}

// ����������� ������
List::List() : head(nullptr), tail(nullptr) {}

// ���������� �������� � ����� ������
void List::push(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// �������� �������� �� ������
void List::pop(int value) {
    Node* current = head;
    while (current && current->data != value) {
        current = current->next;
    }
    if (current) {
        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        delete current;
    }
}

// ����� ��������� ������
void List::print() {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// ����� ��������� ����� ����������� � ������������ ����������
void List::printBetweenMinMax() const {
    if (!head) return;

    Node* current = head;
    int minVal = head->data;
    int maxVal = head->data;
    Node* minNode = head;
    Node* maxNode = head;

    // ����� ����������� � ������������ ��������
    while (current) {
        if (current->data < minVal) {
            minVal = current->data;
            minNode = current;
        }
        if (current->data > maxVal) {
            maxVal = current->data;
            maxNode = current;
        }
        current = current->next;
    }

    // ������� �������� ����� ����������� � ������������
    bool started = false;
    current = head;
    while (current) {
        if (current == minNode || current == maxNode) {
            if (started) break;
            started = true;
        }
        else if (started) {
            cout << current->data << " ";
        }
        current = current->next;
    }
    cout << endl;
}

// ���������� ������
List::~List() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}


