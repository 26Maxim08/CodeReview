#include "Container.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int n1, n2, n3;
    vector<int> V;
    deque<int> D;
    list<int> L;

    cout << "������� ����������� ������� n1 (n1 >= 2, n1 - ������): ";
    cin >> n1;
    Input(V, n1);

    cout << "������� ����������� ���� n2 (n2 >= 2, n2 - ������): ";
    cin >> n2;
    Input(D, n2);

    cout << "������� ����������� ������ n3 (n3 >= 2, n3 - ������): ";
    cin >> n3;
    Input(L, n3);

    cout << "����������� ���������� �����������." << endl;
    cout << "������: ";
    Print(V);
    cout << "���: ";
    Print(D);
    cout << "������: ";
    Print(L);

    MiddleElement(V);
    MiddleElement(D);
    MiddleElement(L);

    cout << "���������� ���������� �����������." << endl;
    cout << "������: ";
    Print(V);
    cout << "���: ";
    Print(D);
    cout << "������: ";
    Print(L);

    return 0;
}
