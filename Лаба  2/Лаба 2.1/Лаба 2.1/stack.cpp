#include "stack.h"

Node::Node(int value) : data(value), next(nullptr) {}

Stack::Stack() : top(nullptr) {}

Stack::~Stack(){
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    cout << "���� ������." << endl;
}

void Stack::push(int value) {
    Node* newNode = new Node(value); 
    newNode->next = top;             
    top = newNode;                   
    cout << "������� " << value << " �������� � ����." << endl;
}

void Stack::pop() {
    if (top == nullptr) {
        cout << "���� ����! ���������� ������� �������." << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    cout << "������� " << temp->data << " ������ �� �����." << endl;
    delete temp;
}

void Stack::print() const {
    if (top == nullptr) {
        cout << "���� ����!" << endl;
        return;
    }
    Node* current = top;
    cout << "�������� �����: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* Stack::getTop() {
    return top;
}


void addElementAndPrintAddress(Stack& stack, int D) {
    stack.push(D);
    cout << "����� ����� ������� �����: " << stack.getTop() << endl;
}

bool appWork(Stack& stack) {

    static short choice = 0;
    static int value = 0;

    cout << "\n����:\n";
    cout << "1. �������� ������� � ����\n";
    cout << "2. ������� ������� �� �����\n";
    cout << "3. ������� �������� �����\n";
    cout << "4. �������� ����\n";
    cout << "5. �����\n";
    cout << "������� ��� �����: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "������� ����� ��� ���������� � ����: ";
        cin >> value;
        addElementAndPrintAddress(stack, value);
        return true;
    case 2:
        stack.pop();
        return true;
    case 3:
        stack.print();
        return true;
    case 4:
        stack.~Stack();
        return true;
    case 5:
        cout << "����� �� ���������." << endl;
        return false;
    default:
        cout << "�������� �����! ����������, ���������� �����." << endl;
        return true;
    }
}
