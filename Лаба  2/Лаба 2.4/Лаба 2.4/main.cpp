#include "List.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    List list;
    int n;
    int value;

    cout << "¬ведите количество элементов: ";
    cin >> n;

    cout << "¬ведите элементы списка: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        list.push(value);
    }

    cout << "Ёлементы списка: ";
    list.print();

    cout << "Ёлементы между минимальным и максимальным значени€ми: ";
    list.printBetweenMinMax();

    return 0;
}
