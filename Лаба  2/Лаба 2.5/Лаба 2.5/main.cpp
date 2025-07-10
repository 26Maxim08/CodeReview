#include "Container.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int n1, n2, n3;
    vector<int> V;
    deque<int> D;
    list<int> L;

    cout << "Введите размерность вектора n1 (n1 >= 2, n1 - четное): ";
    cin >> n1;
    Input(V, n1);

    cout << "Введите размерность дека n2 (n2 >= 2, n2 - четное): ";
    cin >> n2;
    Input(D, n2);

    cout << "Введите размерность списка n3 (n3 >= 2, n3 - четное): ";
    cin >> n3;
    Input(L, n3);

    cout << "Изначальное содержимое контейнеров." << endl;
    cout << "Вектор: ";
    Print(V);
    cout << "Дек: ";
    Print(D);
    cout << "Список: ";
    Print(L);

    MiddleElement(V);
    MiddleElement(D);
    MiddleElement(L);

    cout << "Измененное содержание контейнеров." << endl;
    cout << "Вектор: ";
    Print(V);
    cout << "Дек: ";
    Print(D);
    cout << "Список: ";
    Print(L);

    return 0;
}
