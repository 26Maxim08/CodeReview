#include "List.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    List list;
    int n;
    int value;

    cout << "������� ���������� ���������: ";
    cin >> n;

    cout << "������� �������� ������: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        list.push(value);
    }

    cout << "�������� ������: ";
    list.print();

    cout << "�������� ����� ����������� � ������������ ����������: ";
    list.printBetweenMinMax();

    return 0;
}
