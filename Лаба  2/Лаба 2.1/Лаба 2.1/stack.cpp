#include "stack.h"

Node::Node(int value) : data(value), next(nullptr) {}

Stack::Stack() : top(nullptr) {}

Stack::~Stack(){
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    cout << "Стек очищен." << endl;
}

void Stack::push(int value) {
    Node* newNode = new Node(value); 
    newNode->next = top;             
    top = newNode;                   
    cout << "Элемент " << value << " добавлен в стек." << endl;
}

void Stack::pop() {
    if (top == nullptr) {
        cout << "Стек пуст! Невозможно удалить элемент." << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    cout << "Элемент " << temp->data << " удален из стека." << endl;
    delete temp;
}

void Stack::print() const {
    if (top == nullptr) {
        cout << "Стек пуст!" << endl;
        return;
    }
    Node* current = top;
    cout << "Элементы стека: ";
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
    cout << "Адрес новой вершины стека: " << stack.getTop() << endl;
}

bool appWork(Stack& stack) {

    static short choice = 0;
    static int value = 0;

    cout << "\nМеню:\n";
    cout << "1. Добавить элемент в стек\n";
    cout << "2. Удалить элемент из стека\n";
    cout << "3. Вывести элементы стека\n";
    cout << "4. Очистить стек\n";
    cout << "5. Выйти\n";
    cout << "Введите ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Введите число для добавления в стек: ";
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
        cout << "Выход из программы." << endl;
        return false;
    default:
        cout << "Неверный выбор! Пожалуйста, попробуйте снова." << endl;
        return true;
    }
}
