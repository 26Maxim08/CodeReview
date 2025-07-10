#include "Queue.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Queue evenQueue;
    Queue oddQueue;
    int value = 0;

    cout << "Введите 10 чисел:\n";
    for (int i = 1; i <= 5; i++) {
        
        value = correctinput(2*i-1);
        oddQueue.enqueue(value);

        value = correctinput(2 * i);
        evenQueue.enqueue(value);
    }

    cout << "\nНечетная очередь:\n";
    oddQueue.print();
    cout << "Указательна на head: " << oddQueue.getHead() << endl;
    cout << "Указательна на tail: " << oddQueue.getTail() << endl;

    cout << "\nЧетная очередь:\n";
    evenQueue.print();
    cout << "Указательна на head: " << evenQueue.getHead() << endl;
    cout << "Указательна на tail: " << evenQueue.getTail() << endl;

    return 0;
}