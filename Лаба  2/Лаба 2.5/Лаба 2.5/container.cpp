#include "Container.h"


template <typename Container>
void Input(Container& container, int size) {
    int choice, value;
    cout << "�������� ����� ����� ��� ����������:" << endl;
    cout << "1) ���� � ����������." << endl;
    cout << "2) ��������� ���������." << endl;
    cout << "3) ���� �� ���������� �����." << endl;
    cin >> choice;

    if (size < 2 || size % 2 != 0) {
        cout << "������: ������������ ������. ������ ������ ���� ������ � �� ����� 2." << endl;
        return;
    }

    switch (choice) {
    case 1:
        for (int i = 0; i < size; ++i) {
            cout << "������� ������� " << i + 1 << ": ";
            cin >> value;
            container.insert(container.end(), value);
        }
        break;
    case 2:
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(-50, 50);
        for (int i = 0; i < size; ++i) {
            container.insert(container.end(), dis(gen));
        }
        break;
    case 3:
        ifstream file("a.txt", ios::in);
        if (!file) {
            cout << "������: ���� �� ����� ���� ������." << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            if (!(file >> value)) {
                cout << "������: � ����� ������������ ���������." << endl;
                return;
            }
            container.insert(container.end(), value);
        }
        file.close();
        break;
    default:
        cout << "������: ������������ ����� �����." << endl;
        break;
    }
}

template <typename Container>
void Print(const Container& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

template <typename Container>
void MiddleElement(Container& container) {
    auto it = container.begin();
    auto size = container.size();
    for (int i = 0; i < size / 2 - 1; ++i) {
        ++it;
    }
    auto average1 = it;
    ++it;
    auto average2 = it;
    Swap(*average1, *average2);
}
