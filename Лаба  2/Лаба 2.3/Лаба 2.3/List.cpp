#include "List.h"

Node::Node(int value) : data(value), next(nullptr) {

}

List::List() : head(nullptr){

}

bool List::isEmpty() {
    return head == nullptr;
}

void List::push(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        head = newNode;
    } else if (head->data < value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && current->next->data > value) {
            current = current->next;
        }
            newNode->next = current->next;
            current->next = newNode;
        }
}

void List::pop() {
    Node* temp = head;
    head = head->next;
    temp->next = nullptr;
    temp->data = NULL;
    delete(temp);
}

void List::print() {
    Node* current = head;
    while (current->data != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void List::readFromFile(const string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    int N;
    file >> N;                      

    int value;
    for (int i = 0; i < N; ++i) {  
        file >> value;
        cout<< value << endl;
        push(value);         
    }

    file.close();
}